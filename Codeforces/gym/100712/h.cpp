#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<long, long> pll;
template <class E>
using uset = unordered_set<E>;
template <class K, class V>
using umap = unordered_map<K, V>;
const double pi = acos(-1);

#define hint() cout << ">> "
#define HYPERBOLA_DEBUG
#ifdef DEBUG
#define lf endl
#define fastio()
#define test(x) hint() << x << lf;
#define testv(v)                                                              \
    hint();                                                                   \
    for (const auto& element##__LINE__ : v) cout << element##__LINE__ << ' '; \
    cout << lf;
#define testm(m)                                                                                             \
    hint();                                                                                                  \
    for (const auto& pair##__LINE__ : m) cout << '(' << pair##__LINE__.x << ',' << pair##__LINE__.y << ") "; \
    cout << lf;
#else
#define lf "\n"
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define test(x)
#define testv(v)
#define testm(m)
#endif

#define x first
#define y second
#define iter(x) begin(x), end(x)
#define add(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define printv(v)                                                             \
    for (const auto& element##__LINE__ : v) cout << element##__LINE__ << ' '; \
    cout << lf;
#define dd(a, b) ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))
#define ddl(a, b) (ll(a.x - b.x) * (a.x - b.x) + ll(a.y - b.y) * (a.y - b.y))
#define forr(n) for (int unique_variable##__LINE__ = 0; unique_variable##__LINE__ < n; unique_variable##__LINE__++)
#define loop(i, n) for (int i = 0; i < n; i++)
#define lool(i, n) for (int i = 1; i <= n; i++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) __lcm(a, b)
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, 1, sizeof(x))

struct bridge_seacher {
    const int n;
    const vector<pii>& edge;
    const vector<vector<int>>& adj;
    vector<int> low, disc, path;
    int counter = 0;
    vector<bool> isbridge;

    bridge_seacher(const vector<pii>& e, const vector<vector<int>>& a) : n(a.size()), edge(e), adj(a) {
        low.assign(n, 0);
        disc.assign(n, 0);
        path.assign(n, -1);
        isbridge.assign(e.size(), 0);
    }

    vector<bool> find() {
        find(0);
        testv(isbridge);
        return isbridge;
    }

    void find(int v) {
        low[v] = disc[v] = ++counter;
        for (int a : adj[v]) {
            int e = edge[a].first;
            if (e == v) e = edge[a].second;
            if (!low[e]) {
                path[e] = v;
                find(e);
                low[v] = min(low[v], low[e]);
                if (disc[v] < low[e]) isbridge[a] = 1;
            } else if (path[v] != e) {
                low[v] = min(low[v], disc[e]);
            }
        }
    }
};

struct compresser {
    const vector<bool>& isbridge;
    const vector<pii>& edge;
    const vector<vector<int>>& adj;
    const int n;

    compresser(const vector<pii>& e, const vector<vector<int>>& a, const vector<bool>& b)
        : n(a.size()), edge(e), adj(a), isbridge(b) {}

    pair<vector<pii>, vector<vector<int>>> compress() {
        vector<int> belong(n, -1);
        int ncomp = 0;
        loop(i, n) {
            if (belong[i] != -1) continue;
            stack<int> q;
            q.push(i);
            belong[i] = ncomp++;
            while (!q.empty()) {
                int v = q.top();
                test(v);
                q.pop();
                for (int a : adj[v]) {
                    if (isbridge[a]) continue;
                    int e = edge[a].first;
                    if (e == v) e = edge[a].second;
                    if (belong[e] != -1) continue;
                    belong[e] = belong[i];
                    q.push(e);
                }
            }
        }

        testv(belong);
        vector<pii> tedge;
        vector<vector<int>> tadj(ncomp);
        loop(i, edge.size()) {
            if (!isbridge[i]) continue;
            const pii& e = edge[i];
            int a = belong[e.first], b = belong[e.second];
            tedge.emplace_back(a, b);
            tadj[a].add(tedge.size() - 1);
            tadj[b].add(tedge.size() - 1);
        }
        return mp(tedge, tadj);
    }
};

struct diameter_measurer {
    const vector<pii>& edge;
    const vector<vector<int>>& adj;

    diameter_measurer(const vector<pii>& e, const vector<vector<int>>& a) : edge(e), adj(a) {}
    int diameter() { return diameter(-1, 0).first; }
    pii diameter(int mom, int i) {
        vector<int> h;
        int dia = 0;
        for (int a : adj[i]) {
            int e = edge[a].first;
            if (e == i) e = edge[a].second;
            if (e == mom) continue;
            pii res = diameter(i, e);
            h.add(res.second);
            dia = max(dia, res.first);
        }

        int h1 = 0, h2 = 0;
        testv(h);
        for (int hh : h) {
            if (hh >= h1)
                h2 = h1, h1 = hh;
            else if (hh >= h2)
                h2 = hh;
        }
        dia = max(dia, h1 + h2 + 1);
        test(dia);
        return mp(dia, h1 + 1);
    }
};

int solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> edge(m);
    vector<vector<int>> adj(n);
    loop(i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[i] = {x, y};
        adj[x].add(i);
        adj[y].add(i);
    }
    auto bridge = bridge_seacher(edge, adj).find();
    test("~~");
    auto cp = compresser(edge, adj, bridge).compress();
    test("!!");
    int dia = diameter_measurer(cp.first, cp.second).diameter();
    test(dia);
    return count(iter(bridge), true) - (dia - 1);
}

int main() {
    fastio();
    int t;
    cin >> t;
    forr(t) cout << solve() << lf;
    return 0;
}