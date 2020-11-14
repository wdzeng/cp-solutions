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
   public:
    struct edge {
        int d, r;
        ll c;
        edge(int d, ll c, int r) : d(d), c(c), r(r) {}
    };
    vector<vector<edge>> adj;
    vector<int> lv, ve;
    int n;
    int mklv(int s, int d) {
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

    Dinic(int n) : n(n + 1) { clear(); }
    void clear() { adj.assign(n, vector<edge>()); }
    void add_edge(int src, int dst, ll cap = 1) {
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
    int n;
    while (cin >> n) {
        Dinic d(n + n + 5);
        vector<pii> v(n);
        for (auto& p : v) cin >> p.x >> p.y;
        for (int i = 0; i < n; i++) {
            d.add_edge(n + n, i);
            d.add_edge(n + i, n + n + 1);
            for (int j = i + 1; j < n; j++) {
                if ((v[i].x == v[j].x && abs(v[i].y - v[j].y) == 1) || (v[i].y == v[j].y && abs(v[i].x - v[j].x) == 1)) {
                    d.add_edge(i, j + n), d.add_edge(j, i + n);
                }
            }
        }
        cout << n - d.max_flow(n + n, n + n + 1) /2 << '\n';
    }
    return 0;
}