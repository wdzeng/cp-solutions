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

void solve() {
    int dp[11][21][160];
    ms(dp);
    dp[0][0][0] = 1;
    int n, x, s;
    cin >> x >> n >> s;
    if (!x and !n and !s) exit(0);

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= x; k++) {
            for (int ss = 0; ss <= s; ss++) {
                for (int c = 0; c < k; c++) {
                    if (ss - k >= 0) dp[i][k][ss] += dp[i - 1][c][ss - k];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= x; i++) ans += dp[n][i][s];
    cout << ans << endl;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    while (1) solve();
    return 0;
}
