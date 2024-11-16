#include <stdio.h>
#include <stdlib.h>

#define N 100
#define swap(type, x, y)        \
    do {                        \
        type t = x;             \
        x = y;                  \
        y = t;                  \
    } while (0)

void printArray(int a[], int len, char label[]) {
    printf("%s[",label);
    
    if (len <= 0) {
        printf("]\n");
        return;
    }
    
    for (int i = 0; i < len - 1; i++) {
        printf("%d, ", a[i]);
    }
    
    printf("%d]\n", a[len - 1]);
}

void quick(int a[], int left, int right){
    int pl = left;
    int pr = right;
    int x = a[(pl + pr) / 2];

    do {
        while (a[pl] < x) pl++;
        while (a[pr] > x) pr--;
        if (pl <= pr) {
            swap(int, a[pl],  a[pr]);
            pl++;
            pr--;
        }
    } while(pl <= pr);

    if(left < pr) quick(a, left, pr);
    if(pl < right) quick(a , pl, right);
}

int main(){
    FILE *fp;
    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int len = 0;
    int data[N];

    for (len = 0; fscanf(fp, "%d", &data[len]) == 1; len++);

    printArray(data, len, "before:");

    quick(data, 0, len - 1);

    printArray(data, len, "after:");

    fclose(fp);
}