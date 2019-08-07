#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))

vector<ll> dvs(ll k) {
    vector<ll> ret;
    ll sq = sqrt(k);
    for (ll i = 1; i <= sq; i++)
        if (k % i == 0) {
            ret.push_back(i);
            if (i * i != k) ret.push_back(k / i);
        }
    return ret;
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    ll k;
    cin >> k;

    set<pair<ll, ll>> ans;
    for (ll x : dvs(k)) {
        ll y = k / x;
        y /= __gcd(y, x);
        auto cand = dvs(y);
        for (ll c : cand) {
            ll m = k / c + k / x;
            ans.emplace(m * x, m * c);
        }
    }

    cout << ans.size() << endl;
    for (auto& p : ans) cout << p.first << " " << p.second << endl;
    return 0;
}