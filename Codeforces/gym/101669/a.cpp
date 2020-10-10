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

const int N = 1e5 + 10, K = 310, M = 1e9 + 7;
int dp[N][K];
int rst[26];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int k, n;
    cin >> k >> n;

    for (int i = 0; i < 26; i++) cin >> rst[i];

    string ods, certs;
    cin >> ods >> certs;

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j < k and certs[i] == ods[j]) {
                char c = certs[i];
                int newi = min(n, i + rst[c - 'A'] + 1);
                dp[newi][j + 1] += dp[i][j];
                dp[newi][j + 1] %= M;
            }
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= M;
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}