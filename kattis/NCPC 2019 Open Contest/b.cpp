#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

ll j1(const pii& a, const pii& b, const pii& c) {
    ll w = a.x + b.x + c.x;
    ll h = max(a.y, max(b.y, c.y));
    return w * h;
}

ll j2(const pii& a, const pii& b, const pii& c) {
    ll w = max(a.x, b.x) + c.x;
    ll h = max(a.y + b.y, c.y);
    return w * h;
}

pii rev(const pii& a) {
    pii b = a;
    swap(b.x, b.y);
    return b;
}

void solve() {
    ll ans = LLONG_MAX;
    pii a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    ans = min(ans, j1(a, b, c));
    ans = min(ans, j1(a, b, rev(c)));
    ans = min(ans, j1(a, rev(b), c));
    ans = min(ans, j1(a, rev(b), rev(c)));
    ans = min(ans, j1(rev(a), b, c));
    ans = min(ans, j1(rev(a), b, rev(c)));
    ans = min(ans, j1(rev(a), rev(b), c));
    ans = min(ans, j1(rev(a), rev(b), rev(c)));

    vector<pii> v1 = {a, b, c};
    vector<pii> v2 = {a, c, b};
    vector<pii> v3 = {b, a, c};
    vector<pii> v4 = {b, c, a};
    vector<pii> v5 = {c, a, b};
    vector<pii> v6 = {c, b, a};
    vector<vector<pii>> v = {v1, v2, v3, v4, v5, v6};
    for (vector<pii>& u : v) {
        ans = min(ans, j2(u[0], u[1], u[2]));
        ans = min(ans, j2(u[0], u[1], rev(u[2])));
        ans = min(ans, j2(u[0], rev(u[1]), u[2]));
        ans = min(ans, j2(u[0], rev(u[1]), rev(u[2])));
        ans = min(ans, j2(rev(u[0]), u[1], u[2]));
        ans = min(ans, j2(rev(u[0]), u[1], rev(u[2])));
        ans = min(ans, j2(rev(u[0]), rev(u[1]), u[2]));
        ans = min(ans, j2(rev(u[0]), rev(u[1]), rev(u[2])));
    }

    cout << ans << endl;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}