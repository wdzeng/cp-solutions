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
#define mp(e, factors) make_pair(e, factors)

vector<ll> find_factors(ll n, int minn) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i >= minn) ret.push_back(i);
            if (n / i != i && n / i >= minn) ret.push_back(n / i);
        }
    }
    sort(iter(ret));
    return ret;
}

int tail(ll n, int d, ll b) {
    int e = 0;
    while (n >= d && (n - d) % b == 0) {
        e++;
        n -= d;
        n /= b;
    }
    return e;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll n; int d;
    cin >> n >> d;
    if (n < d) {
        cout << "2 0" << endl;
        return 0;
    }
    if (n == d) {
        cout << max(d + 1, 2) << " 1" << endl;
        return 0;
    }

    auto factors = find_factors(n - d, max(2, d + 1));
    ll minbase = 0, minend = 0;
    for (ll factor : factors) {
        ll e = tail(n, d, factor);
        if (e > minend) {
            minbase = factor;
            minend = e;
        }
    }
    if (minbase == 0) {
        minbase = 2, minend = 0;
    }
    cout << minbase << ' ' << minend << endl;
    return 0;
}