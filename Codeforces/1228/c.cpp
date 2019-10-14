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

const ll m = 1e9 + 7;
ll faspow(ll a, ll p) {
    ll ret = 1;
    while (p) {
        if (p & 1) ret = ret * a % m;
        a = a * a % m, p >>= 1;
    }
    return ret;
}

vector<int> p(int n) {
    vector<int> ret;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ret.push_back(n);
    return ret;
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int n;
    ll x;
    cin >> n >> x;
    auto primes = p(n);
    ll ans = 1;
    for (int pm : primes) {
        ll pp = pm;
        while (x >= pp) {
            ll q = x / pp;
            ans = ans * faspow(pm, q) % m;
            if (q < pm) break;
            pp *= pm;
        }
    }
    cout << ans << endl;
    return 0;
}