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

ll ppow(ll a, ll p, ll m) {
    ll ret = 1;
    while (p) {
        if (p & 1) ret = ret * a % m;
        a = a * a % m, p >>= 1;
    }
    return ret;
}

const ll mod = 1e9 + 7;
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    ll base = ppow(2, m, mod) - 1;
    if (base == -1) base = mod - 1;
    ll ans = ppow(base, n, mod);
    cout << ans << '\n';
    return 0;
}
