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
 
const int maxn = 505;
int r, c;
int height[maxn * maxn];
vector<pii> edges[maxn * maxn];
 
inline int& h(int x, int y) { return height[x * maxn + y]; }
inline int idx(int x, int y) { return x * maxn + y; }
 
vector<int> spt() {
    using info = pair<int, pii>;
    vector<int> dad(maxn * maxn, -2);
    priority_queue<info, vector<info>, greater<info>> q;
    q.push({height[0], {0, -1}});
    int vis = 0;
    while (!q.empty()) {
        auto item = q.top();
        q.pop();
        int w = item.x;
        int v = item.y.x;
        int d = item.y.y;
        if (dad[v] != -2) continue;
        dad[v] = d;
        if (++vis == r * c) return dad;
 
        for (auto& e : edges[v]) {
            int u = e.y;
            if (dad[u] != -2) continue;
            q.push({e.x, {u, v}});
        }
    }
}
 
class OfflineTarjan {
   private:
    vector<int> par;
    vector<int> anc;
    vector<int> dep;
    vector<vector<pii>> qry;
    vector<int> lcas;
    vector<int> rank;
 
    // You can set this to non-reference type for safety reasons
    vector<vector<int>>& edge;
    int root, n;
 
    void merge(int a, int b) {
        a = parent(a), b = parent(b);
        if (rank[a] < rank[b]) swap(a, b);
        par[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
 
    void dfs(int u, int d) {
        anc[parent(u)] = u;
        dep[u] = d;
 
        for (int a : edge[u]) {
            if (dep[a] != -1) continue;
            dfs(a, d + 1);
            merge(a, u);
            anc[parent(u)] = u;
        }
 
        for (auto q : qry[u]) {
            if (dep[q.first] != -1) lcas[q.second] = anc[parent(q.first)];
        }
    }
 
    int parent(int x) {
        if (par[x] == x) return x;
        return par[x] = parent(par[x]);
    }
 
    void solve(vector<pii>& query) {
        dep.assign(n, -1);
        rank.assign(n, 0);
        par.resize(n);
        anc.resize(n);
        for (int i = 0; i < n; i++) anc[i] = par[i] = i;
 
        lcas.resize(query.size());
        qry.resize(n);
        for (int i = 0; i < query.size(); i++) {
            auto& q = query[i];
            qry[q.first].emplace_back(q.second, i);
            qry[q.second].emplace_back(q.first, i);
        }
 
        dfs(root, 0);
    }
 
   public:
    // Constructs a tarjan by adjacent edge information.
    // The vector in edge[i] gives indices of all adjacent vertex of node of index i.
    // Size of edge is unlimited, but on 1-based cases, effective information should be placed in range [1, n]; 0-based [0, n)
    OfflineTarjan(vector<vector<int>>& edge, int root) : edge(edge), root(root), n(edge.size()) {}
 
    // Given a data set of lca requests, queries least commom ancestors of pairs of nodes. The result set has same order to the data
    // set.
    vector<int> lca(vector<pii>& query) {
        solve(query);
        return lcas;
    }
 
    // Given a data set of minimal distance requests, queries minimal distance within a pair of nodes in each set. The result set has
    // same order to the data set.
    vector<int> dist(vector<pii>& query) {
        solve(query);
        for (int i = 0; i < query.size(); i++) {
            auto& q = query[i];
            lcas[i] = dep[q.first] + dep[q.second] - 2 * dep[lcas[i]];
        }
        return lcas;
    }
};
 
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q;
    cin >> r >> c >> q;
    for (int x = 0; x < r; x++)
        for (int y = 0; y < c; y++) cin >> h(x, y);
 
    for (int x = 0; x < r; x++)
        for (int y = 0; y < c; y++) {
            if (y != c - 1) {
                int w = max(h(x, y), h(x, y + 1));
                edges[idx(x, y)].emplace_back(w, idx(x, y + 1));
                edges[idx(x, y + 1)].emplace_back(w, idx(x, y));
            }
            if (x != r - 1) {
                int w = max(h(x, y), h(x + 1, y));
                edges[idx(x, y)].emplace_back(w, idx(x + 1, y));
                edges[idx(x + 1, y)].emplace_back(w, idx(x, y));
            }
        }
 
    auto dad = spt();
 
    vector<vector<int>> treeedge(maxn * maxn);
    for (int i = 0; i < maxn * maxn; i++) {
        if (dad[i] < 0) continue;
        treeedge[i].push_back(dad[i]);
        treeedge[dad[i]].push_back(i);
    }
 
    vector<pii> qs;
    while (q--) {
        pii src, dst;
        cin >> src.x >> src.y >> dst.x >> dst.y;
        src.x--, src.y--, dst.x--, dst.y--;
        qs.emplace_back(idx(src.x, src.y), idx(dst.x, dst.y));
    }
 
    OfflineTarjan ot(treeedge, 0);
    auto lcas = ot.lca(qs);
    for (int i = 0; i < qs.size(); i++) {
        int ac = lcas[i];
        int src = qs[i].x, dst = qs[i].y;
        int maxh = max(height[src], height[dst]);
        while (src != ac) src = dad[src], maxh = max(maxh, height[src]);
        while (dst != ac) dst = dad[dst], maxh = max(maxh, height[dst]);
        cout << maxh << endl;
    }
    return 0;
}