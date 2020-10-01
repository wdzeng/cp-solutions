#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define pb push_back
#define INF 1000000000000000LL
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<int> e1(n), e2(n), t1(n), t2(n);
    for (int i = 0; i < n; i++) {
        int x, t, y, r;
        cin >> x >> t >> y >> r;
        e1[i] = x, e2[i] = y;
        t1[i] = t, t2[i] = r;
    }
    int a1 = s1 + s2 + 505, a2 = s2 + 505;
    vector<vector<ll>> dp(a1 + 1, vector<ll>(a2 + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = a1; j >= 0; j--)
            for (int k = a2; k >= 0; k--) {
                if (j >= e1[i]) dp[j][k] = min(dp[j][k], dp[j - e1[i]][k] + t1[i]);
                if (k >= e2[i]) dp[j][k] = min(dp[j][k], dp[j][k - e2[i]] + t2[i]);
            }
    ll ans = INF;
    for (int i = s1; i <= a1; i++) {
        for (int j = max(0, s2 - i + s1); j <= a2; j++)
            ans = min(ans, dp[i][j]);
    }
    if (ans == INF)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
    return 0;
}