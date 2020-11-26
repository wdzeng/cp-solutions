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

class BIT {
   private:
    int n;
    vector<ll> a;

    ll sum(int i) {
        i++;
        ll r = 0;
        while (i > 0) r += a[i], i -= i & -i;
        return r;
    }

   public:
    BIT(int n) : n(n) { a.resize(n + 1); }
    void add(int i, ll v) {
        i++;
        while (i <= n) a[i] += v, i += i & -i;
    }
    ll sum(int l, int r) { return sum(r) - sum(l - 1); }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pii> v;
    unordered_map<int, int> m;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
        s.insert(x);
        s.insert(y);
    }
    for (int i : s) m[i] = m.size();
    for (auto& p : v) p.x = m[p.x], p.y = m[p.y];

    vector<int> order(n);
    for (int i = 0; i < n; i++) order[i] = i;
    sort(iter(order), [&v](int i, int j) { return v[i] < v[j]; });

    BIT b(n * 2);
    vector<int> ans(n);
    for (int o : order) {
        ans[o] = b.sum(0, v[o].y);
        b.add(v[o].y, 1);
    }
    for (int a : ans) cout << a << ' ';
    cout << endl;
    return 0;
}