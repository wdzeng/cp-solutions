#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

inline ll lcm(ll a, ll b) {
    return a * b * __gcd(a, b);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll x;
    cin >> x;
    ll minn = 1e18;
    pair<ll, ll> ans;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i) continue;
        ll g = __gcd(i, x / i);
        ll j = x / i * g;
        if (max(i, j) < minn) {
            minn = max(i, j);
            ans = {i, j};
        }
    }

    cout << ans.x << ' ' << ans.y << endl;
    return 0;
}