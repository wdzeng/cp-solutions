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
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

ll M = 1e9 + 9;

ll fpow(ll a, ll x) {
    ll ans = 1;
    ll ret = 1;
    while (x) {
        if (x & 1) {
            ret *= a;
            ret %= M;
        }
        a *= a;
        a %= M;
        x >>= 1;
    }
    return ret;
}

ll modinv(ll a) {
    return fpow(a, M - 2);
}

int main() {
    fastio();
    string n;
    cin >> n;
    ll val = 0;
    for (char c : n) {
        val *= 10;
        val += c - '0';
        val %= M;
    }

    for (int i = 1;; i++) {
        val *= modinv(i);
        val %= M;
        if (val == 1) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}