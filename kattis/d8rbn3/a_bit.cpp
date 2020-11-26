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
#define fastio()
#define debug()
#else
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a) cout << (#a) << ": " << (a) << endl
#endif

const ll N = 1e5 + 5;
const ll M = 1e9 + 7;

namespace bit {  // O(log N)
ll d[N], dd[N];
ll sum(int i) {
    ll s = 0, ss = 0;
    int c = i + 1;
    while (i) s += d[i], s %= M, ss += dd[i], ss %= M, i -= i & -i;
    return ((c * s - ss) % M + M) % M;
}
void add(int i, ll v) {  // O(log N)
    int c = i;
    while (i < N)
        d[i] += v, d[i] %= M, dd[i] += c * v, dd[i] %= M, i += i & -i;
}
}  // namespace bit

ll fpow(ll a, ll p) {
    ll ret = 1;
    while (p) {
        if (p & 1) ret *= a, ret %= M;
        a *= a, a %= M, p >>= 1;
    }
    return ret;
}

ll inverse(ll a) {
    return fpow(a, M - 2);
}

int main() {
    fastio();
    int n, q;
    cin >> n >> q;
    ll ans = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            l++, r++;
            
            ll sum = bit::sum(r) - bit::sum(l - 1);
            sum = (sum % M + M) % M;
            ll inv = inverse(r - l + 1);
            ans += 1 + 2 * inv * sum;
            ans %= M;
            
            bit::add(l, inv);
            bit::add(r + 1, (-inv + M) % M);
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}