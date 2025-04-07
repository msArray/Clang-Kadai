#include <stdio.h>
#include <stdlib.h>

typedef struct __bnode {
    int data;
    struct __bnode *left;
    struct __bnode *right;
} BinNode;

BinNode *Add(BinNode *p, int a);
void PrintTree(BinNode *p, int lv);
void FreeTree(BinNode *p); 

int main(){
    BinNode *p = NULL;
    int a, lv = 0;
    while(1) {
        scanf("%d", &a);
        if(a < 0) {
            break;
        }

        p = Add(p, a);
        lv += 1;
    }

    PrintTree(p, lv);
    FreeTree(p);

    return 0;
}

BinNode *Add(BinNode *p, int a){
    if(p == NULL){
        p = malloc(sizeof(BinNode));
        if(p == NULL){
            fprintf(stderr, "メモリ不足");
            exit(-1);
        }
        p -> data = a;
        p -> left = p -> right = NULL;
    }else if(a == p->data){
        printf("%dは入っている\n",a);
    }else if(a < p -> data){
        p -> left = Add(p -> left, a);
    }else {
        p -> right = Add(p -> right, a);
    }

    return p;
}

void PrintTree(BinNode *p, int lv){
    if(p != NULL){
        PrintTree(p -> left, lv + 1);
        for(int i = 0;i < lv; i++){
            printf("   ");
        }
        printf("%d\n", p -> data);
        PrintTree(p -> right, lv + 1);
    }
}

void FreeTree(BinNode *p){
    if(p != NULL){
        FreeTree(p -> left);
        FreeTree(p -> right);
        free(p);
    }
}