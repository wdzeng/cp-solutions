#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

class Dinic {
    struct edge {
        int d, r;
        ll c;
        edge(int d, ll c, int r) : d(d), c(c), r(r){};
    };

   private:
    vector<vector<edge>> adj;
    vector<int> lv, ve;
    int n;
    bool mklv(int s, int d) {
        lv.assign(n, -1);
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
            if (lv[e.d] != lv[v] + 1 || !e.c) continue;
            ll sent = aug(e.d, min(f, e.c), d);
            if (sent > 0) {
                e.c -= sent, adj[e.d][e.r].c += sent;
                return sent;
            }
        }
        return 0;
    }

   public:
    // 建空圖， n 節點數 (含 source, sink)
    Dinic(int n) : n(n + 1) { clear(); }
    void clear() { adj.assign(n, vector<edge>()); }
    // 加有向邊 src->dst ，cap 是容量
    void add_edge(int src, int dst, ll cap) {
        edge ss(dst, cap, adj[dst].size());
        edge dd(src, 0, adj[src].size());
        adj[src].push_back(ss), adj[dst].push_back(dd);
    }
    ll max_flow(int s, int d) {
        ll ret = 0;
        while (mklv(s, d)) {
            ve.assign(n, 0);
            while (ll f = aug(s, 9e18, d)) ret += f;
        }
        return ret;
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    vector<pair<int, pii>> E;
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        E.push_back({w, {a, b}});
    }
    sort(all(E));
    ll ans = 0;
    for (int i = 0; i < E.size(); i++) {
        int w = E[i].x;
        int src, dst;
        tie(src, dst) = E[i].y;
        Dinic d(n + 3);
        for (int j = 0; E[j].x < w; j++) {
            int a, b;
            tie(a, b) = E[j].y;
            d.add_edge(a, b, 1);
            d.add_edge(b, a, 1);
        }
        ans += d.max_flow(src, dst);
    }
    cout << ans << endl;

    return 0;
}