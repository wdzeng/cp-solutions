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

const int N = 1e5 + 100;
const int K = 105;
ll dp[N][K];
ll cnt[K];
ll cntAfter[K];
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> s = {-1};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s.push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (s[i]) {
            for (int j = 1; j <= k; j++) {  // the last unknown digit is j
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + cnt[s[i] + 1]);
            }
            for (int j = s[i]; j >= 1; j--) cnt[j]++;
            for (int j = s[i]; j <= k; j++) cntAfter[j]--;
        }  //
        else {
            for (int j = 1; j <= k; j++) {
                for (int d = j; d >= 1; d--) {
                    dp[i][d] = max(dp[i][j], dp[i - 1][j] + cnt[d + 1] + cntAfter[d - 1] );
                }
            }
            cnt[0]++;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= k; i++) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}