#include <stdio.h>

// AC
int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    if (y % x) {
        printf("-1\n");
        return 0;
    }
    x = y / x;
    int n2 = 0, n3 = 0;

    // 2
    while (x % 2 == 0) {
        x /= 2;
        n2++;
    }
    while (x % 3 == 0) {
        x /= 3;
        n3++;
    }
    if (x > 1) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", n2 + n3);
    return 0;
}