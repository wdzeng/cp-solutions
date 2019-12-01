#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)
typedef long double lld;
typedef pair<lld, lld> pdd;

struct frac {
    ll den, num;
    frac() : den(1), num(1) {}
    frac(ll a) : den(a), num(1) {}
    frac(ll a, ll b) : den(a), num(b) {}
    const frac operator*(const frac& f) const { return frac(den * f.den, num * f.num); }
    const frac operator/(const frac& f) const { return frac(den * f.num, num * f.den); }
    bool operator>(const frac& f) const { return den * f.num > num * f.den; }
    bool operator<(const frac& f) const { return f > *this; }
    bool operator==(const frac& f) const { return !(*this > f) && !(*this < f); }
    const frac operator+(ll v) const { return frac(den + v * num, num); }
    const frac operator+(const frac& f) const { return frac(den * f.num + num * f.den, num * f.num); }
    lld val() const { return lld(den) / num; }
};

ll det(vector<vector<ll>> g) {
    ll s = g[0][0] * g[1][1] * g[2][2] + g[0][1] * g[1][2] * g[2][0] + g[0][2] * g[1][0] * g[2][1];
    ll t = g[0][0] * g[1][2] * g[2][1] + g[0][1] * g[1][0] * g[2][2] + g[0][2] * g[1][1] * g[2][0];
    return s - t;
}

pair<frac, frac> out(pii& a, pii& b, pii& c) {
    ll num = abs(det({{a.x, a.y, 1}, {b.x, b.y, 1}, {c.x, c.y, 1}})) * 2;
    ll x = abs(det({{a.x * a.x + a.y * a.y, a.y, 1}, {b.x * b.x + b.y * b.y, b.y, 1}, {c.x * c.x + c.y * c.y, c.y, 1}}));
    ll y = abs(det({{a.x, a.x * a.x + a.y * a.y, 1}, {b.x, b.x * b.x + b.y * b.y, 1}, {c.x, c.x * c.x + c.y * c.y, 1}}));
    return {frac(x, num), frac(y, num)};
}

ll d2(pii& a, pii& b) {
    ll dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll r;
    cin >> r;
    r *= 2;

    pii a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    a.x *= 2, a.y *= 2, b.x *= 2, b.y *= 2, c.x *= 2, c.y *= 2;

    ll lab2 = d2(a, b);
    ll lbc2 = d2(b, c);
    ll lca2 = d2(c, a);
    if (lbc2 > lca2 && lbc2 > lab2)
        swap(a, c), swap(lab2, lbc2);
    else if (lca2 > lbc2 && lca2 > lab2)
        swap(b, c), swap(lab2, lca2);

    pii m = {(a.x + b.x) / 2, (a.y + b.y) / 2};
    ll lmc2 = d2(m, c);
    frac maxl2;
    pair<frac, frac> ans;
    if (lmc2 > lab2 / 4) {
        ans = out(a, b, c);
        ans.x = ans.x + -a.x;
        ans.y = ans.y + -a.y;
        maxl2 = (ans.x * ans.x + ans.y * ans.y);
    } else
        maxl2 = frac(lab2 / 4, 1), ans = m;

    if (!(maxl2 < frac(r * r, 1)))
        cout << "NO\n";
    else
        printf("YES\n%Lg %Lg\n", ans.x.val() / 2, ans.y.val() / 2);
    return 0;
}
