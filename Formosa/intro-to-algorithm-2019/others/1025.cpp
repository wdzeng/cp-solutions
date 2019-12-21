#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

const int maxn = 2e3 + 5;
const ll inf = 1e18;

vector<ll> dijkstra(int src, vector<vector<pii>>& adj) {
    vector<ll> ret(maxn, inf);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.emplace(0, src);

    while (!q.empty()) {
        int v = q.top().second;
        ll l = q.top().first;
        q.pop();
        if (l >= ret[v]) continue;
        ret[v] = l;
        for (auto& a : adj[v]) {
            int u = a.second;
            if (ret[u] <= ret[v] + a.first) continue;
            q.emplace(ret[v] + a.first, u);
        }
    }

    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1, vector<pii>());
    auto adj_rev = adj;
    while (m--) {
        int a, b, l;
        cin >> a >> b >> l;
        adj_rev[b].emplace_back(l, a);  // reverse
        adj[a].emplace_back(l, b);
    }

    auto min_path = dijkstra(0, adj);
    auto min_path_rev = dijkstra(0, adj_rev);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += min_path[i] + min_path_rev[i];
    }

    cout << ans << '\n';
    return 0;
}
