#include <stdio.h>
#include <string.h>
// AC
int main() {
    int n = 0;
    scanf("%d", &n);
    long long sum = 0;
    int tar[n];
    tar[0] = 0;
    long long tt = 0;
    for (int i = 1; i < n; i++) {
        scanf("%d", tar + i);
        tt += tar[i];
        sum += tt;
        // printf(": %d\n", sum);
    }

    const long long arrsum = (long long)n * (n + 1) / 2;
    if ((arrsum - sum) % n) {
        printf("-1\n");
        return 0;
    }

    char arr[n];
    memset(arr, 0, sizeof(char) * n);

    int x = (arrsum - sum) / n;
    for (int i = 0; i < n; i++) {
        x += tar[i];
        if (x < 1 || x > n || arr[x - 1]) {
            printf("-1\n");
            return 0;
        }
        arr[x - 1] = 1;
    }

    x = (arrsum - sum) / n;
    for (int i = 0; i < n; i++) {
        x += tar[i];
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}