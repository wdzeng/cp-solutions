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

#define x first
#define y second
#define iter(x) begin(x), end(x)
#define add(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define printv(v)                             \
    for (const auto& e : v) cout << e << " "; \
    cout << endl;
#define dd(a, b) ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))
#define ddl(a, b) (ll(a.x - b.x) * (a.x - b.x) + ll(a.y - b.y) * (a.y - b.y))
#define forr(n) for (int unique_variable##__LINE__ = 0; unique_variable##__LINE__ < n; unique_variable##__LINE__++)
#define loop(i, n) for (int i = 0; i < n; i++)
#define lool(i, n) for (int i = 1; i <= n; i++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) __lcm(a, b)
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, 1, sizeof(x))

#define DEBUGs
#ifdef DEBUG
#define fastio()
#define test(x) cout << x << endl;
#define testv(v) printv(v)
#define testm(m)                                                      \
    for (const auto& p : m) cout << "(" << p.x << "," << p.y << ") "; \
    cout << endl;
#else
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define test(x)
#define testv(v)
#define testm(m)
#endif

int main() {
    fastio();

    int t;
    cin >> t;
    forr(t) {
        int n;
        cin >> n;
        int v[n];
        loop(i, n) {
            cin >> v[i];
            v[i] = 50 - v[i];
        }
        sort(v, v + n);
        int maxx = 100 - (50 - v[0]);
        int safe = upper_bound(v, v + n, maxx) - v - 1;
        cout << safe + 1 << endl;
    }
    return 0;
}