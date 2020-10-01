#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
class Dinic {
    struct edge {
        int d, r; ll c;
        edge(int d, ll c, int r) : d(d), c(c), r(r){};
    };
   private:
    vector<vector<edge>> adj; vector<int> lv, ve; int n;
    bool mklv(int s, int d) {
        lv.assign(n, -1); lv[s] = 0;
        queue<int> q; q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
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
    Dinic(int n) : n(n + 1) { clear(); }
    void clear() { adj.assign(n, vector<edge>()); }
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

int ii(const string& s) {
    static unordered_map<string, int> m;
    if (!m.count(s)) m[s] = m.size();
    return m[s];
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int s, r, f, t;
    cin >> s >> r >> f >> t;

    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        ii(s);
    }
    for (int i = 0; i < f; i++) {
        string s;
        cin >> s;
        ii(s);
    }

    Dinic dc(s + 2 * t + 5);

    for (int i = 0; i < t; i++) {
        int u;
        cin >> u;
        while (u--) {
            string str;
            cin >> str;
            int idx = ii(str);
            if (idx < r) {
                dc.add_edge(idx, s + i, 1);
            } else if (r < idx and idx < r + f) {
                dc.add_edge(s + t + i, idx, 1);
            } else {
                dc.add_edge(idx, s + i, 1);
                dc.add_edge(s + t + i, idx, 1);
            }
        }
    }

    for (int i = 0; i < r; i++) {
        dc.add_edge(s + 2 * t, i, 1);
    }
    for (int i = 0; i < f; i++) {
        dc.add_edge(r + i, s + 2 * t + 1, 1);
    }
    for (int i = 0; i < t; i++) {
        dc.add_edge(s + i, s + t + i, 1);
    }

    cout << dc.max_flow(s + 2 * t, s + 2 * t + 1) << endl;

    return 0;
}