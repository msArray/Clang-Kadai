#include <stdio.h>
#include <stdlib.h>

#define N 9999
#define swap(type, x, y)        \
    do {                        \
        type t = x;             \
        x = y;                  \
        y = t;                  \
    } while (0)

void bubble(int a[], int n) {
    int b = 0, c = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            b++;
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                c++;
            }
        }
    }
    printf("単純交換ソート 比較:%d 交換:%d [", b, c);
    for (int i = 0; i < n - 1; i++) {
        printf("%d,", a[i]);
    }
    printf("%d]", a[n - 1]);
}

void selection(int a[], int n) {
    int b = 0, c = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            b++;
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(int, a[i], a[min]);
        c++;
    }
    printf("単純選択ソート 比較:%d 交換:%d [", b, c);
    for (int i = 0; i < n - 1; i++) {
        printf("%d,", a[i]);
    }
    printf("%d]", a[n - 1]);
}

void insert(int a[], int n) {
    int b = 0, c = 0;
    for (int i = 1; i < n; i++) {
        int tmp = a[i];
        int j;
        for (j = i; j > 0; j--) {
            b++;
            if (a[j - 1] > tmp) {
                a[j] = a[j - 1];
                c++;
            } else {
                break;
            }
        }
        a[j] = tmp;
    }
    printf("単純挿入ソート 比較:%d 交換:%d [", b, c);
    for (int i = 0; i < n - 1; i++) {
        printf("%d,", a[i]);
    }
    printf("%d]", a[n - 1]);
}

int main() {
    FILE *fp;
    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int len = 0;
    int data_a[N], data_b[N], data_c[N];

    for (len = 0; fscanf(fp, "%d", &data_a[len]) == 1; len++);

    for (int i = 0; i < len; i++) {
        data_b[i] = data_a[i];
        data_c[i] = data_a[i];
    }

    bubble(data_a, len);
    printf("\n");
    selection(data_b, len);
    printf("\n");
    insert(data_c, len);
    printf("\n");

    fclose(fp);
}
