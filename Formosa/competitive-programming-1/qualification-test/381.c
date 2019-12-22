#include <stdio.h>
// AC
int gcd(int les, int lar) {
    if (!les) return lar; // Check zero.
    int lem;
    while (1) {
        lem = lar % les;
        if (!lem) return les;
        lar = les;
        les = lem;
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    if (a > b)
        printf("%d\n", gcd(b, a));
    else
        printf("%d\n", gcd(a, b));
    return 0;
}
