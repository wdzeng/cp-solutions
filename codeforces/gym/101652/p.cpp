#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

const int N = 1e6 + 5;
int isnotprime[N];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    vector<int> primes;
    for (int i = 2; i < N; i++) {
        if (isnotprime[i]) continue;
        for (int a = i << 1; a < N; a += i) isnotprime[a] = 1;
        primes.push_back(i);
    }
    // cout << primes.size() << endl;

    ll l, r;
    cin >> l >> r;
    ll ans = 0;

    vector<vector<int>> fac(N);

    for (ll p : primes) {
        ll start = l / p * p;
        for (ll i = start; i <= r; i += p) {
            if (i < l) continue;
            fac[i - l].push_back(p);
        }
    }

    for (ll i = l; i <= r; i++) {
        ll val = i;
        ll S = 1;
        for (int p : fac[i - l]) {
            ll s = 1;
            ll pp = 1;
            while (val % p == 0) val /= p, pp *= p, s += pp;
            S *= s;
        }
        if (val > 1) S *= (1 + val);
        ans += S;
    }
    cout << ans << endl;

    return 0;
}