#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int data;
    struct __node *next;
} Node;

int main(){
    int x = 2;
    Node head, *p, *q;
    head.next = NULL;

    while(1){
        for(p = head.next,q = &head;p != NULL; q = p,p = q -> next){
            if(x % p->data == 0){
                x += 1;
                p = head.next;
            }
        }

        if(x > 100){
            break;
        }

        if(p == NULL){
            p = malloc(sizeof(Node));
            if(p == NULL){
                fprintf(stderr, "メモリ不足\n");
                exit(-1);
            }

            p->data = x;
            p->next = NULL;
            q->next = p;
        }
    }

    for(p = head.next;p != NULL;p = p -> next) printf("%d ", p->data);
    printf("\n");
}