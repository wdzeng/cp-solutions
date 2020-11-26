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
#ifndef hy
#define endl '\n'
#endif

string line;
int canRepeatInSize(int l, int r, int z) {
    int len = r - l;
    if (len % z) return 0;
    for (int i = 0; i < z; i++) {
        for (int loc = l + i + z; loc < r; loc += z)
            if (line[loc] != line[loc - z]) return 0;
    }
    return 1;
}

const int N = 705;
int dp[N][N];
int main() {
#ifndef hy
    cin.tie(0), ios::sync_with_stdio(0);
#endif
    int n;
    cin >> n;
    cin >> line;
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    for (int i = 0; i < N; i++) dp[i][i] = 0;
    for (int i = 0; i < N - 1; i++) dp[i][i + 1] = 1;
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            const int r = l + len;
            for (int s = l + 1; s < r; s++) dp[l][r] = min(dp[l][r], dp[l][s] + dp[s][r]);
            for (int z = 1; z <= len / 2; z++)
                if (canRepeatInSize(l, r, z)) dp[l][r] = min(dp[l][r], dp[l][l + z]);
            // cout << l << '#' << r << '#' << dp[l][r] << endl;
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}