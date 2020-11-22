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
#define debug(a) 
#else
#define debug(a) cout << #a << ": " << a << endl
#endif

const ll M = 1e9 + 7;
const int N = 1e5 + 5;

ll fpow(ll a, ll p) {
    ll ret = 1;
    while (p) {
        if (p & 1) ret *= a, ret %= M;
        a *= a, a %= M;
        p >>= 1;
    }
    return ret;
}

ll inverse(ll a) {
    return fpow(a, M - 2);
}

namespace seg {
ll s[N << 2], d[N << 2];

void push(int i, int cl, int cr) {
    if (!d[i]) return;
    int m = (cl + cr) >> 1;
    s[i * 2 + 1] += (m - cl) * d[i];
    s[i * 2 + 1] %= M;
    d[i * 2 + 1] += d[i];
    d[i * 2 + 1] %= M;
    s[i * 2 + 2] += (cr - m) * d[i];
    s[i * 2 + 2] %= M;
    d[i * 2 + 2] += d[i];
    d[i * 2 + 2] %= M;
    d[i] = 0;
}

void add(int l, int r, ll val, int i = 0, int cl = 1, int cr = N) {
    if (cl >= r || cr <= l) return;
    if (l <= cl && cr <= r) {
        s[i] += (cr - cl) * val;
        s[i] %= M;
        d[i] += val;
        d[i] %= M;
        return;
    }
    push(i, cl, cr);
    int m = (cl + cr) >> 1;
    add(l, r, val, i * 2 + 1, cl, m);
    add(l, r, val, i * 2 + 2, m, cr);
    s[i] = (s[i * 2 + 1] + s[i * 2 + 2]) % M;
}

ll sum(int l, int r, int i = 0, int cl = 1, int cr = N) {
    if (cl >= r || cr <= l) return 0;
    if (l <= cl && cr <= r) return s[i];
    push(i, cl, cr);
    int m = (cl + cr) >> 1;
    return (sum(l, r, i * 2 + 1, cl, m) + sum(l, r, i * 2 + 2, m, cr)) % M;
}
}  // namespace seg

int main() {
#ifndef hy
    cin.tie(0), ios::sync_with_stdio(0);
#endif
    int n, q;
    cin >> n >> q;
    ll ans = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            r++;
            ll inv = inverse(r - l);
            debug(inv);
            ans += 1 + 2 * inv * seg::sum(l, r);
            ans %= M;
            seg::add(l, r, inv);
        }  //
        else {
            cout << ans << endl;
        }
    }
    return 0;
}