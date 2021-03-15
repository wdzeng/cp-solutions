#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int maxn = 501;
int dp[maxn][maxn];
int w[maxn][maxn];
int n, m;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> w[i][j];
            if (!w[i][j]) w[i][j] = inf;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                if (w[k][i] < w[k][j])
                    dp[i][j]++;
                else if (w[k][i] > w[k][j])
                    dp[j][i]++;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] == dp[j][i])
                dp[i][j] = dp[j][i] = 0;
            else if (dp[i][j] < dp[j][i])
                dp[i][j] = 0;
            else
                dp[j][i] = 0;
        }
    }

    for (int i = 1; i <= m; i++) dp[i][i] = inf;
    for (int k = 1; k <= m; k++) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i][j], min(dp[i][k], dp[k][j]));
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        bool flag = true;
        for (int j = 1; j <= m; j++) {
            if (i == j) continue;
            if (dp[i][j] < dp[j][i]) {
                flag = false;
                break;
            }
        }
        if (flag) cout << i << ' ';
    }
    cout << '\n';
    return 0;
}