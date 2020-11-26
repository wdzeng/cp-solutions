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
#define assure(x) assert(x)
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
#define assure(x)
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

vector<int> waste;
int n, lm;

bool judge(int range) {
    test(range);
    int mintime[n];
    mintime[0] = 0;

    deque<int> q;
    q.push_back(0);
    for (int i = 1; i < n; i++) {
        while (!q.empty() && q.front() < i - range) q.pop_front();
        mintime[i] = mintime[q.front()] + waste[q.front()];
        test(mintime[i]);
        if (mintime[i] > lm) return false;
        while (!q.empty() && mintime[q.back()] + waste[q.back()] >= mintime[i] + waste[i]) q.pop_back();
        q.push_back(i);
    }
    return true;
}

int main() {
    freopen("journey.in", "r", stdin);
    freopen("journey.out", "w", stdout);
    fastio();

    cin >> n >> lm;
    lm -= (n - 1);
    vector<int> price;
    forr(n - 1) {
        int p;
        cin >> p;
        price.add(p);
    }

    vector<int> tmp;
    while (!price.empty()) {
        int p = price.back();
        price.pop_back();
        if (!tmp.empty()) {
            p = min(p, tmp.back());
        }
        tmp.add(p);
    }
    reverse(iter(tmp));
    tmp.swap(price);

    waste.add(0);
    forr(n - 2) {
        int w;
        cin >> w;
        waste.add(w);
    }
    waste.add(0);
    testv(waste);

    int l = 1, r = n - 1;
    while (l < r) {
        int range = (l + r) / 2;
        if (judge(range))
            r = range;
        else
            l = range + 1;
    }

    test(l);
    cout << price[l - 1] << lf;
    return 0;
}