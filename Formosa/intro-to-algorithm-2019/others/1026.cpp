#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

const int maxn = 500;
const ll inf = 1e18;
vector<pii> adj[maxn];
int n;

int next(ll* cost, bool* vis) {
    int ret = -1;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (ret == -1)
            ret = i;
        else if (cost[i] < cost[ret])
            ret = i;
    }
    return ret;
}

void prim(int src, ll* ret) {
    for (int i = 0; i < n; i++) ret[i] = inf;
    bool vis[n];
    memset(vis, 0, n);
    ret[src] = 0;

    int v;
    while ((v = next(ret, vis)) != -1) {
        for (auto& a : adj[v]) {
            int u = a.second;
            ll ucost = a.first;
            ret[u] = min(ret[u], max(ret[v], ucost));
        }
        vis[v] = 1;
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int m, q;
    cin >> n >> m >> q;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(c, b);
    }

    ll min_cost_table[n][n];
    for (int i = 0; i < n; i++) {
        prim(i, min_cost_table[i]);
    }

    while (q--) {
        int src, dst;
        cin >> src >> dst;
        ll ans = max(min_cost_table[src][dst], min_cost_table[dst][src]);
        if (ans == inf) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}
