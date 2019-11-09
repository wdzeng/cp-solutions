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
const ll M = 1e9 + 7;

vector<ll> npow;

inline ll fastpow(ll a, ll p, ll m) {
    ll ret = 1;
    while (p) {
        if (p & 1) ret = ret * a % m;
        a = a * a % m, p >>= 1;
    }
    return ret;
}

inline ll select(int lm) { return npow[lm + 1] - npow[lm]; }

inline ll solve(int t, int lm) {
    ll ans = 0;
    for (int i = 0; i + t <= lm; i++) {
        ans += (select(i) * select(lm - (i + t)) % M);
        ans = (ans % M + M) % M;
    }
    return ans;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, r, c, k;
    cin >> n >> r >> c >> k;

    npow.resize(max(r, c) + 1);
    for (int i = 0; i < npow.size(); i++) npow[i] = fastpow(i, n, M);

    vector<ll> W(r + 1), H(c + 1);
    for (int w = 1; w <= r; w++) W[w] = solve(w, r);
    for (int h = 1; h <= c; h++) H[h] = solve(h, c);

    ll ans = 0;
    for (int w = 1; w <= r; w++) {
        int h = (k - 1) / w + 1;
        while (h <= c) {
            ans += (W[w] * H[h] % M);
            ans %= M;
            h++;
        }
    }

    cout << ans << endl;
    return 0;
}