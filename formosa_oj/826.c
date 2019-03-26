#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sq unsigned char
#define QQ printf("QAQ\n")
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)

// AC

int row, col;

int tryeat(sq choco[row][col], const int x, const int y, int xlim, int ylim,
           int* lim) {
    if (x <= xlim && y <= ylim || x <= *lim && y <= *lim || !choco[x][y] ||
        x < 0 || y < 0)
        return 0;

    choco[x][y] = 0;
    int cur, counter = 1;
    for (cur = x - 1; choco[cur][y] && cur > xlim; cur--) {
        counter++;
        choco[cur][y] = 0;
    }
    xlim = cur;
    for (cur = y - 1; choco[x][cur] && cur > ylim; cur--) {
        counter++;
        choco[x][cur] = 0;
    }
    ylim = cur;
    return counter + tryeat(choco, x - 1, y - 1, xlim, ylim, lim);
}

void solve(int t) {
    sq choco[row][col];
    int size = row * col;
    memset(choco, 1, size * sizeof(sq));

    int x, y, eated, lim = -1;
    while (t--) {
        scanf("%d %d", &x, &y);
        x--;
        y--;
        eated = tryeat(choco, x, y, -1, -1, &lim);
        if (eated) {
            printf("%d\n", eated);
            size -= eated;
        } else
            QQ;
        choco[x][y] = 0;
        lim = max(lim, min(x, y));
    }
    printf("%d", size);
}

int main() {
    int q;
    scanf("%d %d %d", &row, &col, &q);
    solve(q);
    return 0;
}