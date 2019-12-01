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
#define assure(x) assert(x)
#else
#define lf "\n"
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define test(x)
#define testv(v)
#define testm(m)
#define assure(x)
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

int solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> edge[n];
    forr(m) {
        int x, y, d;
        cin >> x >> y >> d;
        x--;
        y--;
        edge[x].emplace_back(d, y);
        edge[y].emplace_back(d, x);
    }

    priority_queue<pii, vector<pii>, greater<pii>> q;
    int ret = 0;
    int inserted = 1;
    for (auto& e : edge[0]) q.push(e);
    bool vis[n];
    ms(vis);
    vis[0] = 1;
    while (inserted < n) {
        assure(!q.empty());
        auto e = q.top();
        test(e.second);
        q.pop();
        if (vis[e.second]) continue;
        vis[e.second] = 1;
        for (auto& ee : edge[e.second])
            if (!vis[ee.second]) q.push(ee);
        ret = max(e.first, ret);
        inserted++;
    }
    return ret;
}

int main() {
    fastio();

    int t;
    cin >> t;
    forr(t) cout << solve() << lf;
    return 0;
}