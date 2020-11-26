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
    freopen("black.in", "r", stdin);
    freopen("black.out", "w", stdout);
    fastio();

    int k, w;
    cin >> k >> w;
    if (k == w) {
        cout << 1 << " " << k + w << lf;
        loop(i, k + w) cout << (i % 2 ? '@' : '.');
        cout << endl;
        return 0;
    }
    char ww = '.', kk = '@';
    if (w > k) swap(ww, kk), swap(w, k);

    int width = 4 * w + 1;
    int height = ((k - 1) - 1) / w + 1;
    height = 2 * height + 1 + 2;

    char g[height][width];
    for (int x = 0; x < width; x += 4) {
        loop(h, height) g[h][x] = kk;
    }
    loop(w, width) g[0][w] = g[height - 1][w] = kk;

    for (int x = 1; x < width; x += 2) {
        for (int y = 1; y < height - 1; y++) g[y][x] = ww;
    }

    for (int x = 2; x < width; x += 4) {
        for (int y = 1; y < height - 1; y += 2) g[y][x] = ww;
    }

    k--;
    for (int x = 2; x < width; x += 4) {
        for (int y = 2; y < height - 2; y += 2) {
            g[y][x] = k ? kk : ww;
            if (k > 0) k--;
        }
    }

    cout << height << " " << width << lf;
    loop(y, height) {
        loop(x, width) { cout << g[y][x]; }
        cout << lf;
    }

    return 0;
}