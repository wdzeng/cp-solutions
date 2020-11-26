#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifndef hy
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#else
#define fastio()
#define debug(a) cout << #a << ": " << a << endl
#endif

ll fpow(ll a, ll p) {
    ll ret = 1;
    while (p) {
        if (p & 1) ret *= a;
        a *= a;
        p >>= 1;
    }
    assert(ret > 0);
    return ret;
}

const ll N = 1e6 + 5;
ll ans[N];
void linlee() {
    for (int i = 1; i < N; i++) ans[i] += 1 + (i - 1) / 2;
    for (ll q = 2; q * q < N; q++) {
        ll qn = q * q;
        for (int n = 2; qn < N; n++) {
            for (ll p = 1; p < q; p++) {
                if (__gcd(p, q) > 1) continue;
                ll pn = fpow(p, n);
                ll sum = (qn * q - pn * p) / (q - p);
                for (ll S = sum; S < N; S += sum) {
                    ans[S]++;
                }
            }
            qn *= q;
        }
    }
}

int main() {
    fastio();
    linlee();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << ans[n] << ' ';
    }
    cout << endl;
    return 0;
}