#include <stdio.h>
#include <stdlib.h>

// AC

int* arr;
int arrlen;
int lim;

void print() {
    for (int i = 0; i < arrlen; i++) printf("%d ", arr[i]);
    printf("\n");
}

void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int next() {
    int i;
    for (i = arrlen - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) break;
    }
    if (i == -1) return 0;

    int j;
    for (j = arrlen - 1; j > i; j--) {
        if (arr[j] > arr[i]) break;
    }
    swap(arr + i, arr + j);
    for (int x = i + 1, y = arrlen - 1; x < y; x++, y--) {
        swap(arr + x, arr + y);
    }
    print();
    return 1;
}

int main() {
    scanf("%d %d", &arrlen, &lim);
    arr = malloc(sizeof(int) * lim);
    for (int i = 0; i < arrlen; i++) scanf("%d", arr + i);
    int some = 0;
    int j = 1;
    while (lim-- && j) {
        j = next();
        some |= j;
    }
    if (!some) printf("hello world!\n");
    return 0;
}