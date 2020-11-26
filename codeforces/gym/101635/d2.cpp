#include <bits/stdc++.h>
using namespace std;
const int N = 55, M = 20005;
int n, m, i, j, k, x, tot, son[M][26], w[M], f[N][N], dp[N];
int g[N][M];
char a[N], b[N];
inline void up(int& a, int b) { a < b ? (a = b) : 0; }
inline void ins(int l, int v) {
    int x = 0;
    for (int i = 0; i < l; i++) {
        int o = b[i] - 'a';
        if (!son[x][o]) son[x][o] = ++tot;
        x = son[x][o];
    }
    up(w[x], v);
}
int main() {
    for (i = 1; i < M; i++) w[i] = -1;
    scanf("%s", a + 1);
    n = strlen(a + 1);
    for (i = 1; i <= n; i++) a[i] -= 'a';
    scanf("%d", &m);
    while (m--) {
        int l, w;
        scanf("%s%d", b, &w);
        l = strlen(b);
        ins(l, w);
        reverse(b, b + l);
        ins(l, w);
    }
    for (i = 0; i <= n + 1; i++)
        for (j = 0; j <= n + 1; j++) f[i][j] = -1;

    for (i = n; i; i--) {
        for (j = i - 1; j <= n + 1; j++)
            for (k = 0; k <= tot; k++) g[j][k] = -1;
        g[i - 1][0] = 0;
        for (j = i - 1; j <= n; j++)
            for (k = 0; k <= tot; k++)
                if (~g[j][k]) {
                    for (x = j + 1; x <= n; x++)
                        if (~f[j + 1][x]) up(g[x][k], g[j][k] + f[j + 1][x]);
                    if (j < n) {
                        int y = son[k][a[j + 1]];
                        if (y) {
                            up(g[j + 1][y], g[j][k]);
                            if (~w[y]) up(g[j + 1][0], g[j][k] + w[y]);
                        }
                    }
                    if (k == 0) up(f[i][j], g[j][k]);
                }
    }

    for (i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (j = 1; j <= i; j++)
            if (~f[j][i]) up(dp[i], dp[j - 1] + f[j][i]);
    }
    printf("%d", dp[n]);
}