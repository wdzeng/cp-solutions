#include <stdio.h>
// AC
int main() {
    int h1, m1, h2, m2;
    scanf("%d:%d", &h1, &m1);
    scanf("%d:%d", &h2, &m2);

    int dh = h2 - h1;
    int oom = dh * 60 + m2;
    int midm = (oom + m1) / 2;
    int vh = midm / 60;
    printf("%02d:%02d\n", h1 + vh, midm % 60);
    return 0;
}