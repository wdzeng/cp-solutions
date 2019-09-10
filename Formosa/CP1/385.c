#include <stdio.h>
// AC
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void copyarray(int* src, int* dest, int len) {
    for (int i = 0; i < len; i++) *(dest + i) = *(src + i);
}

int lq(int* array, int len, int n) {
    int arr[len];
    copyarray(array, arr, len);

    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) swap(arr + i, arr + j);
        }
    }
    return arr[n - 1];
}

int main() {
    int nseries, nqueries;
    scanf("%d %d", &nseries, &nqueries);

    int series[nseries];
    for (int i = 0; i < nseries; i++) {
        scanf("%d", series + i);
    }

    int left, right, rank;
    while (nqueries--) { // Cleaner code!!
        scanf("%d %d %d", &left, &right, &rank);
        left--;  // First index is 1. Adjust.
        right--;
        printf("%d\n", lq(series + left, right - left + 1, rank));
    }

    return 0;
}