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
#define testm(m)                                                       \
    for (const auto& p : m) cout << "(" << p.x << ", " << p.y << ") "; \
    cout << endl;
#else
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define test(x)
#define testv(v)
#define testm(m)
#endif

int solve() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    str = ' ' + str;
    int minpiece[n + 1];
    ms(minpiece);
    minpiece[0] = 0;
    minpiece[1] = 1;
    deque<int> q;
    int safepos = 0;
    for (int i = 2; i <= n; i++) {
        while (!q.empty() && q.front() < i - k) q.pop_front();
        if (str[i] == str[i - 1]) {
            int start = max(safepos, i - k);
            for (int x = start; x < i - 1; x++) {
                while (!q.empty() && minpiece[q.back()] >= minpiece[x]) q.pop_back();
                q.push_back(x);
            }
            safepos = i - 2;
        }
        testv(q);
        minpiece[i] = minpiece[i - 1] + 1;
        if (!q.empty()) minpiece[i] = min(minpiece[i], minpiece[q.front()] + 1);
    }
    testv(minpiece);
    return minpiece[n] - 1;
}

int main() {
    fastio();

    int t;
    cin >> t;
    forr(t) { cout << solve() << endl; }
    return 0;
}