#include <bits/stdc++.h>

const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
int f[N], g[N], cnt[N];

void M(int &a) {
    if (a >= MOD) a -= MOD;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1];
    g[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == cnt[i - 1]) {
            if (i - 1 - cnt[i - 1] >= 0)
                f[i] = g[i - 1 - cnt[i - 1]];
            if (i - cnt[i] >= 0)
                M(g[i - cnt[i]] += f[i]);
        }
    }
    printf("%d\n", g[n - cnt[n]]);
    return 0;
}