#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

const ll inf = 5e18;

class Dinic {
   private:
    struct edge {
        int d, r;
        ll c;
    };
    vector<vector<edge>> adj;
    vector<int> lv, ve;
    int n;
    bool mklv(int s, int d) {
        lv.assign(n, -1);
        lv[s] = 0;
        queue<int> q({s});
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
    // 建空圖。 n 為節點數量 (含 source 和 sink)。
    Dinic(int n) : n(n + 1) { clear(); }
    void clear() { adj.assign(n, {}); }
    void add_edge(int src, int dst, ll cap) {
        edge ss{dst, (int)adj[dst].size(), cap};
        edge dd{src, (int)adj[src].size(), 0};
        adj[src].push_back(ss), adj[dst].push_back(dd);
    }
    ll max_flow(int s, int d) {
        ll ret = 0;
        while (mklv(s, d)) {
            ve.assign(n, 0);
            while (ll f = aug(s, inf, d)) ret += f;
        }
        return ret;
    }
};

int main() {
    fastio();
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int src, p, lim;
        cin >> src >> p >> lim;

        int e;
        cin >> e;
        vector<int> dst(e);
        for (auto& d : dst) {
            cin >> d;
        }
        int m;
        cin >> m;
        vector<pair<pii, pii>> g;
        while (m--) {
            int a, b, lm, t;
            cin >> a >> b >> lm >> t;
            g.push_back({{a, b}, {lm, t}});
        }
        Dinic dinic(n * 105 + 5);
        for (int t = 0; t <= lim; t++) {
            for (auto& e : g) {
                int a, b;
                tie(a, b) = e.x;
                int lm, tm;
                tie(lm, tm) = e.y;
                if (t + tm > lim) continue;
                int idsrc = t * n + a;
                int iddst = (t + tm) * n + b;
                dinic.add_edge(idsrc, iddst, lm);
            }
            for (int i = 1; i <= n; i++) {
                int idsrc = t * n + i;
                int iddst = idsrc + n;
                dinic.add_edge(idsrc, iddst, inf);
            }
        }

        int IDSRC = n * 105 + 5 - 1;
        int IDDST = n * 105 + 5 - 2;
        dinic.add_edge(IDSRC, src, p);
        for (int d : dst) {
            for (int t = 0; t <= lim; t++) {
                int idsrc = t * n + d;
                dinic.add_edge(idsrc, IDDST, inf);
            }
        }

        int ans = dinic.max_flow(IDSRC, IDDST);
        cout << ans << endl;
    }
    return 0;
}