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

ll solve() {
    int n;
    cin >> n;
    int l[n], p[n];
    for (int i = 0; i < n; i++) cin >> l[i] >> p[i];

    ll dp[n][3];
    ms(dp);
    dp[0][1] = p[0], dp[0][2] = p[0] * 2;
    for (int i = 1; i < n; i++) {
        dp[i][0] = 1e18;
        if (l[i] != l[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (l[i] != l[i - 1] + 1) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (l[i] != l[i - 1] + 2) dp[i][0] = min(dp[i][0], dp[i - 1][2]);

        dp[i][1] = 1e18;
        if (l[i] + 1 != l[i - 1]) dp[i][1] = min(dp[i][1], dp[i - 1][0]);
        if (l[i] + 1 != l[i - 1] + 1) dp[i][1] = min(dp[i][1], dp[i - 1][1]);
        if (l[i] + 1 != l[i - 1] + 2) dp[i][1] = min(dp[i][1], dp[i - 1][2]);
        dp[i][1] += p[i];

        dp[i][2] = 1e18;
        if (l[i] + 2 != l[i - 1]) dp[i][2] = min(dp[i][2], dp[i - 1][0]);
        if (l[i] + 2 != l[i - 1] + 1) dp[i][2] = min(dp[i][2], dp[i - 1][1]);
        if (l[i] + 2 != l[i - 1] + 2) dp[i][2] = min(dp[i][2], dp[i - 1][2]);
        dp[i][2] += p[i] * 2;
    }

    return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) cout << solve() << '\n';
    return 0;
}
