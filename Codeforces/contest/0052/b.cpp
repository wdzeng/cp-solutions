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

struct BIT {
    int n;
    vector<ll> a;

    BIT(int n) : n(n) { a.resize(n + 1); }

    ll sum(int i) {
        i++;
        ll r = 0;
        while (i > 0) r += a[i], i -= i & -i;
        return r;
    }

    void add(int i) {
        i++;
        while (i <= n) a[i] += 1, i += i & -i;
    }

    ll sum(int l, int r) { return sum(r) - sum(l - 1); }
};
int main() {
     cin.tie(0), ios::sync_with_stdio(0);
    int n;
    int m;
    cin >> n >> m;
    vector<BIT> r(n, BIT(m)), c(m, BIT(n));
    vector<string> g;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '*') r[i].add(j), c[j].add(i);
        }
        g.push_back(s);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != '*') continue;
            ll right = r[i].sum(j + 1, m - 1);
            ll down = c[j].sum(i + 1, n - 1);
            ll up = c[j].sum(0, i - 1);
            ll left = r[i].sum(0, j - 1);
            ans += right * down;
            ans += left * down;
            ans += right * up;
            ans += left * up;
        }
    }

    cout << ans << endl;
    return 0;
}
