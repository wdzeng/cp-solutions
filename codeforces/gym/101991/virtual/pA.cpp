#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 10, maxk = 20;

vector<int> G[maxn];

int ac[maxn][maxk], tin[maxn], tout[maxn], dis[maxn], T, t, n, l, r, a, b;
long long ans;

bool isac(int x, int y) {
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}

void dfs(int u, int fa, int d) {
    ac[u][0] = fa, dis[u] = d, tin[u] = ++t;
    for (int i = 1; i < maxk; i++)
        if (ac[u][i - 1] == -1)
            ac[u][i] = -1;
        else
            ac[u][i] = ac[ac[u][i - 1]][i - 1];
    for (int x: G[u])
        if (x != fa)
            dfs(x, u, d + 1);
    tout[u] = ++t;
}

int q(int x, int y) {
    int lca;
    if (isac(x, y))
        lca = x;
    else if (isac(y, x))
        lca = y;
    else {
        lca = y;
        for (int i = maxk - 1; i >= 0; i--)
            if (ac[lca][i] >= 0 && !isac(ac[lca][i], x))
                lca = ac[lca][i];
        lca = ac[lca][0];
    }
    return (n - 1) - (dis[x] + dis[y] - 2 * dis[lca]);
}

int main() {
    freopen("awesome.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0); 
    cin >> T;
    while (T--) {
        cin >> n >> l >> r;
        for (int i = 1; i <= n; i++)
            G[i].clear();
        memset(tin, 0, sizeof(tin));
        memset(tout, 0, sizeof(tout));
        memset(dis, 0, sizeof(dis));
        for (int i = 1; i < n; i++) {
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        ans = t = 0;
        dfs(1, -1, 0);
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) {
                a = q(i, j);
                ans += (l <= a && a <= r);
            }
        cout << ans << '\n';
    }
    return 0;
}
