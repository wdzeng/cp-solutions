#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

/**
 * A dinic can find maximal count of flows in O(EV^2) in general, while in biparitite O(E * sqrt(v)). All arguments in this class
 * are safe for both 0- and 1-based cases without any changes.
 */
class Dinic {
    struct edge {
        int d, r;
        ll c;
        edge(int d, ll c, int r) : d(d), c(c), r(r){};
    };

   private:
    vector<vector<edge>> adj;
    vector<int> lv;
    vector<int> ve;
    int n;

    bool mklv(int s, int d) {
        lv.assign(n, -1);
        queue<int> q;
        q.push(s);
        lv[s] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& e : adj[v]) {
                if (e.c == 0 || lv[e.d] != -1) continue;
                lv[e.d] = lv[v] + 1;
                q.push(e.d);
            }
        }
        return lv[d] > 0;
    }

    ll flow(int v, ll f, int d) {
        if (v == d) return f;
        for (; ve[v] < adj[v].size(); ve[v]++) {
            auto& e = adj[v][ve[v]];
            if (lv[e.d] != lv[v] + 1 || !e.c) continue;
            ll sent = flow(e.d, min(f, e.c), d);
            if (sent > 0) {
                e.c -= sent;
                adj[e.d][e.r].c += sent;
                return sent;
            }
        }
        return 0;
    }

   public:
    // Constructs a graph who has at most n vertices, inclusive of source and sink. This graph has no edges until you call add_edge
    // function. Noted that all vertices, including source and sink, should have indcies in range [0, n].
    Dinic(int n) : n(n + 1) { clear(); }

    // Removes all edges from this graph.
    void clear() { adj.assign(n, vector<edge>()); }

    // Adds a directed edge into the graph, where arg s indicates source, d destination, c capacity.
    void add_edge(int s, int d, ll c) {
        edge ss(d, c, adj[d].size());
        edge dd(s, 0, adj[s].size());
        adj[s].push_back(ss);
        adj[d].push_back(dd);
    }

    // Queries the maximal count of flows. Args s and d are source and destination (sink).
    ll max_flow(int s, int d) {
        ll ret = 0;
        while (mklv(s, d)) {
            ve.assign(n, 0);
            while (ll f = flow(s, LLONG_MAX, d)) ret += f;
        }
        return ret;
    }
};

/**
 * Queries minuimum path from src to all the other vertices in a graph where all vertices are connected. Arg n is count of vertices in
 * the graph, while 0- or 1-based are both safe without any changes. Value pairs put in the edge vector are of format {edge length,
 * adjacent vertex}. If ll type is required for edge length, replaces pii with pair<ll, int> and vector<int> with vector<ll>.
 */
vector<ll> dijkstra(int src, vector<vector<pii>>& edge) {  // return type may be int or ll
    using info = pair<ll, int>;
    int nvis = 0;
    vector<ll> sum(edge.size(), -1);  // may be int or ll
    priority_queue<info, vector<info>, greater<info>> q;
    q.emplace(0, src);
    while (!q.empty()) {
        int v = q.top().second;
        auto d = q.top().first;  // may be int or ll
        q.pop();
        if (sum[v] != -1) continue;
        sum[v] = d;
        nvis++;
        for (auto& e : edge[v])
            if (sum[e.second] == -1) q.emplace(d + e.first, e.second);
    }
    return sum;
}

void read(int& ret) {
    bool w = 0;
    ret = 0;
    while (1) {
        char c = getchar();
        if (isdigit(c)) {
            ret = ret * 10 + (c - '0');
            w = 1;
        } else {
            if (w) return;
        }
    }
}

int main() {
    int n, e, s;
    read(n), read(e), read(s);
    vector<vector<pii>> edge(n);
    vector<int> living(n);
    vector<int> shelters(s);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        read(living[i]);
        sum += living[i];
    }
    for (int i = 0; i < e; i++) {
        int a, b, w;
        read(a), read(b), read(w);
        a--, b--;
        edge[a].emplace_back(w, b);
        edge[b].emplace_back(w, a);
    }

    vector<pair<ll, pii>> paths;
    set<ll> scand;
    for (int i = 0; i < s; i++) {
        int l, c;
        read(l), read(c);
        l--;
        shelters[i] = c;
        auto mnp = dijkstra(l, edge);
        for (int j = 0; j < n; j++) {
            scand.insert(mnp[j]);
            paths.push_back({mnp[j], {j, n + i}});
        }
    }
    sort(iter(paths));
    vector<ll> cand(iter(scand));
    int l = 0, r = cand.size() - 1;
    Dinic d(n + s + 2);
    while (l < r) {
        d.clear();
        int m = (l + r) >> 1;
        ll lim = cand[m];
        for (auto& p : paths) {
            if (p.x > lim) break;
            d.add_edge(p.y.x, p.y.y, 1e18);
        }
        for (int i = 0; i < n; i++) {
            if (living[i]) {
                d.add_edge(n + s, i, living[i]);
            }
        }
        for (int i = 0; i < s; i++) {
            d.add_edge(n + i, n + s + 1, shelters[i]);
        }
        if (d.max_flow(n + s, n + s + 1) == sum) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << cand[l] << '\n';
    return 0;
}