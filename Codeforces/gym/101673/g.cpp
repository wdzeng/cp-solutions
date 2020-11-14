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

int cal[105];
int dp[105][20005];  // i-th meal is eaten and has remaning m eating ability

inline void setmax(int& val, int var) {
    val = max(val, var);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    mss(dp);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> cal[i];
    dp[0][m] = 0;
    dp[1][m] = 0;
    dp[2][m] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] == -1) continue;
            int caneat = min(j, cal[i]);
            int nextm = j * 2 / 3;
            setmax(dp[i + 1][nextm], dp[i][j] + caneat);
            setmax(dp[i + 2][j], dp[i][j] + caneat);
            setmax(dp[i + 3][m], dp[i][j] + caneat);
        }
    }

    /*for (int j = 0; j <= m; j++) {
        for (int i = 0; i <= n; i++) {
            cout << dp[i][j] << '\t';
        }
        cout << '\n';
    }*/
    int maxx = 0;
    for (int j = 0; j <= m; j++) setmax(maxx, dp[n][j]);
    for (int j = 0; j <= m; j++) setmax(maxx, dp[n + 1][j]);
    for (int j = 0; j <= m; j++) setmax(maxx, dp[n + 2][j]);
    for (int j = 0; j <= m; j++) setmax(maxx, dp[n + 3][j]);
    cout << maxx << endl;
    return 0;
}