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

const ll M = 1e9 + 7;
const int N = 105;

ll modinv(ll a, ll p = M) {
    if (p == 1) return 0;
    ll pp = p, y = 0, x = 1;
    while (a > 1) {
        ll q = a / p, t = p;
        p = a % p, a = t, t = y, y = x - q * y, x = t;
    }
    if (x < 0) x += pp;
    return x;
}

pair<ll, ll> ask(int r) {
    cout << "1 1 " << r << endl;
    ll k, sum;
    cin >> k >> sum;
    return {k, sum};
}

ll ans[N];
ll dp[N][N];

int main() {
#ifndef hy
    cin.tie(0), ios::sync_with_stdio(0);
#endif
    dp[0][0] = 1;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        ll k, sum;
        tie(k, sum) = ask(i);

        ans[i] = sum - dp[i - 1][k];
        ans[i] = (ans[i] % M + M) % M;
        ans[i] *= modinv(dp[i - 1][k - 1]);
        ans[i] %= M;

        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * ans[i];
            dp[i][j] %= M;
        }
    }

    cout << "2 ";
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}