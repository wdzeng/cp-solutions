// AC

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#define fail() printf("^v^\n")
#define MAX_LONG 0x7fffffffffffffff
#define min(a, b) (a) < (b) ? (a) : (b)

void solve() {
    long left, right;
    int nseq;
    scanf("%d %ld %ld", &nseq, &left, &right);
    const int len = min(right - left + 1, nseq);

    long readed;
    uint8_t array[len];
    memset(array, 0, len);
    while (nseq--) {
        scanf("%ld", &readed);
        readed -= left;
        if (readed < 0 || readed >= len) continue;
        // printf("[%d] = true\n", (int)readed);
        array[readed] = 1;
    }

    long min = MAX_LONG;  // MAX LONG
    for (int i = 0; i < len; i++) {
        if (!array[i]) {
            min = left + i;
            break;
        }
    }

    if (min == MAX_LONG) {
        if (len < right - left + 1)
            printf("%ld\n", left + len);
        else
            fail();
    } else
        printf("%ld\n", min);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}