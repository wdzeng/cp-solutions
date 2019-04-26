#include <stdio.h>
#include <string.h>
#define min(a, b) (a) < (b) ? (a) : (b)
// AC
int main() {
    int np = 0;
    int x, t;
    scanf("%d", &t);

    int n;
    scanf("%d", &n);
    int c[n];
    memset(c, 0, sizeof(int) * n);

    while (t--) {
        scanf("%d", &x);
        c[x % n]++;
    }

    int count = c[0] & 0xFFFFFFFE;
    int c0 = 1, c1 = n - 1;
    for (int c0 = 1, c1 = n - 1; c0 <= c1; c0++, c1--) {
        if (c0 == c1)
            count += (c[c0] & 0xFFFFFFFE);
        else
            count += (min(c[c0], c[c1]))*2;
    }
    printf("%d\n", count);
    return 0;
}