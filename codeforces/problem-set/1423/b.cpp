#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define sz(v) int(v.size())

const int N = 2e4 + 50;
const int D = 1e4 + 10;

namespace Dinic {
struct edge {
    int d, r;
    ll c;
};
int lv[N], ve[N];
vector<edge> adj[N];

bool mklv(int s, int d) {
    memset(lv, -1, sizeof(lv));
    lv[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& e : adj[v]) {
            if (e.c == 0 || lv[e.d] != -1) continue;
            lv[e.d] = lv[v] + 1, q.push(e.d);
        }
    }
    return lv[d] > 0;
}

ll aug(int v, ll f, int d) {
    if (v == d) return f;
    for (; ve[v] < adj[v].size(); ve[v]++) {
        auto& e = adj[v][ve[v]];
        if (lv[e.d] != lv[v] + 1 or !e.c) continue;
        ll sent = aug(e.d, min(f, e.c), d);
        if (sent > 0) {
            e.c -= sent, adj[e.d][e.r].c += sent;
            return sent;
        }
    }
    return 0;
}

void clear() {
    for (auto& a : adj) a.clear();
}

void add_edge(int src, int dst, ll cap) {
    adj[src].push_back({dst, sz(adj[dst]), cap});
    adj[dst].push_back({src, sz(adj[src]), 0});
}

ll max_flow(int s, int d) {
    ll ret = 0;
    while (mklv(s, d)) {
        memset(ve, 0, sizeof(ve));
        while (ll f = aug(s, 9e18, d)) ret += f;
    }
    return ret;
}
};  // namespace Dinic

int main() {
    int n, m;
    cin >> n >> m;
    int minn = 1e9, maxx = 0;
    vector<pair<ll, pii>> g;
    while (m--) {
        int u, v, d;
        cin >> u >> v >> d;
        g.push_back({d, {u - 1, v - 1}});
    }

    int l = 0, r = 1e9 + 10;
    while (l <= r) {
        int m = (l + r) >> 1;
        Dinic::clear();
        for (auto& e : g)
            if (e.x <= m) Dinic::add_edge(e.y.x, e.y.y + n, 1);
        for (int i = 0; i < n; i++) {
            Dinic::add_edge(n + n, i, 1);
            Dinic::add_edge(n + i, n + n + 1, 1);
        }
        if (Dinic::max_flow(n + n, n + n + 1) == n) {
            r = m - 1;
        } else
            l = m + 1;
    }
    int ans = l;
    if (ans > 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}