#include <stdio.h>
#include <stdlib.h>

typedef struct __node {
    int data;
    struct __node *next;
} Node;

Node *merge_sort(Node *p);
Node *merge_list(Node *a, Node *b);

int main(){
    Node head, *p;
    int a;

    head.next = NULL;
    while(1) {
        scanf("%d", &a);
        if(a < 0) {
            break;
        }

        p = malloc(sizeof(Node));
        if(p == NULL) {
            fprintf(stderr, "メモリ不足\n");
            exit(-1);
        }

        p->data = a;
        p->next = head.next;
        head.next = p;
    }

    head.next = merge_sort(head.next);

    for(p = head.next; p != NULL; p = p->next){
        printf("%d\n",p->data);
    }
}

Node *merge_sort(Node *p){
    Node *q, *a, *b;

    if(p == NULL || p->next == NULL) {
        return(p);
    }
    a = p;
    b = p->next;
    b = b->next;
    while(b != NULL){
        a = a->next;
        b = b->next;
        if(b != NULL) {
            b = b->next;
        }
    }
    q = a->next;
    a->next = NULL;

    p = merge_sort(p);
    q = merge_sort(q);
    return merge_list(p, q);
}

Node *merge_list(Node *a, Node *b) {
    Node n;
    Node *t = &n;
    n.next = NULL;

    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            t->next = a;
            a = a->next;
        } else {
            t->next = b;
            b = b->next;
        }
        t = t->next;
    }

    if (a != NULL) {
        t->next = a;
    } else {
        t->next = b;
    }

    return n.next;
}