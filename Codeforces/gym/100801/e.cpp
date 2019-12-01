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

int main() {
    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);
    fastio();

    string s;
    cin >> s;
    string ans = "";
    int i;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == '+' && ans.back() == '+') continue;
        if (s[i] == '-' && ans.back() == '+') ans.pop_back();
        if (s[i] == '-') {
            ans.add(s[i]);
            i++;
            ans.add(s[i]);
            i++;
            ans.add('+');
            while (i < s.size() && s[i] == '0') {
                ans.add(s[i]);
                i++;
                ans.add('+');
            }
            i--;
        } else {
            ans.add(s[i]);
        }
    }
    while (ans.back() == '+') ans.pop_back();
    cout << ans << lf;
    return 0;
}