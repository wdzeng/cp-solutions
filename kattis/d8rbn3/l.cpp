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
#ifndef hy
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#else
#define fastio()
#define debug(a) cout << #a << ": " << a << endl
#endif

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
            while (ll f = aug(s, 9e18, d)) ret += f;
        }
        return ret;
    }
};

const int N = 1e4 + 5;
int isprime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

ll cost[N];
ll prof[N];
ll nodeid[N][20];
const ll inf = 1e15;

int main() {
    fastio();
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> prof[i];
    for (int i = 1; i <= n; i++) cin >> cost[i];

    int nodecnt = 0;
    int src = nodecnt++;
    nodecnt += n;
    for (int i = 2; i < N; i++) {
        if (!isprime(i)) continue;
        ll prod = i;
        for (int j = 1; prod < N; j++) {
            nodeid[i][j] = nodecnt++;
            prod *= i;
        }
    }
    int sink = nodecnt++;
    Dinic dinic(nodecnt);

    ll cap = N + 50;
    for (int i = 1; i <= n; i++) {
        dinic.add_edge(src, i, cap);
        dinic.add_edge(i, sink, cap - prof[i]);

        int x = i;
        for (int p = 2; p <= x; p++) {
            if (!isprime(p)) continue;
            int j = 0;
            while (x % p == 0) x /= p, j++;
            if (j) dinic.add_edge(i, nodeid[p][j], inf);
        }
    }

    for (int p = 2; p < N; p++) {
        if (!isprime(p)) continue;
        int j = 1;
        for (; nodeid[p][j + 1]; j++) {
            ll c = 1ll * j * j * cost[p];
            dinic.add_edge(nodeid[p][j], nodeid[p][j + 1], c);
        }
        dinic.add_edge(nodeid[p][j], sink, 1ll * j * j * cost[p]);
    }

    ll mxf = dinic.max_flow(src, sink);
    ll total = cap * n;
    ll miss = total - mxf;
    cout << miss << endl;
    return 0;
}