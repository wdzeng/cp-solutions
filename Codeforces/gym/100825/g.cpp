#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

ll dp[30][8];
int nope[30][3];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    while (k--) {
        double x, y;
        cin >> x >> y;
        int _x = floor(x);
        int _y = floor(y);
        nope[_x][_y] = 1;
    }

    dp[0][0] = 1;
    for (int x = 0; x < n; x++) {
        for (int s = 0; s < 8; s++) {
            if (!dp[x][s]) continue;
            for (int p = 0; p < 8; p++) {
                if (s & p) continue;
                bool ok = 1;
                for (int i = 0; i < 3; i++) {
                    if (nope[x][i] and (p & (1 << i))) ok = 0;
                    if (nope[x + 1][i] and (p & (1 << i))) ok = 0;
                }
                if (!ok) continue;
                dp[x + 1][p] += dp[x][s];
                int t = (s | p);
                if (t == 0) {
                    if (!nope[x][0] and !nope[x][1]) dp[x + 1][p] += dp[x][s];
                    if (!nope[x][2] and !nope[x][1]) dp[x + 1][p] += dp[x][s];
                } else if (t == 1) {
                    if (!nope[x][2] and !nope[x][1]) dp[x + 1][p] += dp[x][s];
                } else if (t == 4) {
                    if (!nope[x][0] and !nope[x][1]) dp[x + 1][p] += dp[x][s];
                }
            }
        }
    }
/*
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i <= n; i++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }*/

    cout << dp[n][0] << endl;

    return 0;
}