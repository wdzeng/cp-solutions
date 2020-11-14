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

const int N = 32;
vector<string> g;
unordered_map<char, ll> cost;
int X, Y;
const ll inf = 1e9;

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

pii findSrc() {
    for (int x = 0; x < X; x++)
        for (int y = 0; y < Y; y++)
            if (g[x][y] == 'B') return {x, y};
    assert(0);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> Y >> X;
    int c;
    cin >> c;
    for (int i = 0; i < X; i++) {
        string s;
        cin >> s;
        g.push_back(s);
    }
    for (int i = 0; i < c; i++) {
        ll x;
        cin >> x;
        cost['a' + i] = x;
    }
    cost['.'] = inf;
    cost['B'] = inf;

    pii src = findSrc();
    Dinic dinic(X * Y * 2 + 10);
    int srcId = X * Y * 2 + 1, dstId = X * Y * 2 + 2;
    dinic.add_edge(srcId, src.x * Y + src.y, inf);
    for (int x = 0; x < X; x++) {
        for (int y = 0; y < Y; y++) {
            int id = x * Y + y;
            dinic.add_edge(id, id + X * Y, cost[g[x][y]]);
            if (x == 0) {
                dinic.add_edge(id + X * Y, dstId, inf);
            } else {
                int did = (x - 1) * Y + y;
                dinic.add_edge(id + X * Y, did, inf);
            }
            if (x == X - 1) {
                dinic.add_edge(id + X * Y, dstId, inf);
            } else {
                int did = (x + 1) * Y + y;
                dinic.add_edge(id + X * Y, did, inf);
            }
            if (y == 0) {
                dinic.add_edge(id + X * Y, dstId, inf);
            } else {
                int did = x * Y + y - 1;
                dinic.add_edge(id + X * Y, did, inf);
            }
            if (y == Y - 1) {
                dinic.add_edge(id + X * Y, dstId, inf);
            } else {
                int did = x * Y + y + 1;
                dinic.add_edge(id + X * Y, did, inf);
            }
        }
    }

    ll mincut = dinic.max_flow(srcId, dstId);
    if (mincut >= inf) mincut = -1;
    cout << mincut << endl;

    return 0;
}