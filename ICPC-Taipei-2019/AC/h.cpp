#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

pii operator-(const pii& a, const pii& b) { return pii(a.first * b.second - b.first * a.second, a.second * b.second); }

ll solve(int n) {
    pii nn(1, n);
    ll ret = 0;
    for (int i = n + 1; i <= 2 * n; i++) {
        pii p(1, i);
        pii rem = nn - p;
        swap(rem.first, rem.second);
        if (rem.first % rem.second == 0) {
            ll c = rem.first / rem.second;
            ll a = c ^ i;
            ret = max(ret, a);
        }
    }
    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}
