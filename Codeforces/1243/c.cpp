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

ll modinv(ll a, ll p) {
    if (p == 1) return 0;
    ll pp = p, y = 0, x = 1;
    while (a > 1) {
        ll q = a / p;
        ll t = p;
        p = a % p, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += pp;
    return x;
}

ll modinv(ll a, ll b, ll p) {
    ll ret = modinv(a, p);
    return ret * b % p;
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    ll n, p, w, d;
    cin >> n >> p >> w >> d;

    ll lcmm = w * d / __gcd(w, d);
    ll lm = lcmm / w;
    for (ll i = lm - 1; i > -1; i--) {
        ll cost = i * w;
        if (cost > p) continue;
        ll rest = p - cost;
        if (rest % d != 0) continue;
        ll more = rest / lcmm;
        cost += more * lcmm;
        rest -= more * lcmm;
        ll nd = rest / d, nw = cost / w;
        if (nd + nw > n)
            cout << -1 << endl;
        else
            cout << nw << ' ' << nd << ' ' << n - nw - nd
                 << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}
