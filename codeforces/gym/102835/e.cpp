#pragma GCC optimze("unroll-loops", "Ofast")
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

const int N = 501;
const int C = 7;
string s;
int m;
int dp[N][N][C];
int best[N][N];

void solve(int l, int r, int c) {
    if (l + 1 == r) {
        dp[l][r][c] = (s[l] == c ? 1 : -1);
        return;
    }

    for (int i = l + 1; i < r; i++) {
        if (best[l][i] && best[i][r]) {
            best[l][r] = 1;
        }
    }

    int maxx = 0;
    for (int i = l + 1; i < r; i++) {
        if (~dp[l][i][c] && ~dp[i][r][c])
            maxx = max(dp[l][i][c] + dp[i][r][c], maxx);
    }
    if (maxx > 0) {
        dp[l][r][c] = maxx;
        return;
    }

    for (int col = 0; col < C; col++) {
        if (col == c) continue;
        for (int i = l + 1; i < r; i++) {
            if (~dp[l][i][col] && ~dp[i][r][col] && dp[l][i][col] + dp[i][r][col] >= m) {
                dp[l][r][c] = 0;
                return;
            }
        }
    }

    dp[l][r][c] = -1;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> s;
    int n = s.size();
    cin >> m;
    if (m == 1) {
        cout << "Yes" << endl;
        return 0;
    }

    for (char& c : s) {
        switch (c) {
            case 'R':
                c = 0;
                break;
            case 'G':
                c = 1;
                break;
            case 'B':
                c = 2;
                break;
            case 'C':
                c = 3;
                break;
            case 'M':
                c = 4;
                break;
            case 'Y':
                c = 5;
                break;
            case 'K':
                c = 6;
                break;
        }
    }

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            for (int c = 0; c < C; c++)
                solve(i, i + len, c);
        }
    }

    for (int i = 0; i < C; i++) solve(0, n, i);
    for (int i = 0; i < C; i++) {
        if (dp[0][n][i] >= m) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}