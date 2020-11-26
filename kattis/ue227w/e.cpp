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
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif
const int N = 1005;
int g1[N][4];
int g2[N][4];
int dp[N][N];
int vis[N][N];
int n;

int dfs(int loc1, int loc2, int df) {
    if (loc1 == 0) return df;
    if (~dp[loc1][loc2]) return dp[loc1][loc2];
    if (vis[loc1][loc2]) {
        if (loc1 == n) {
            assert(loc2 == n);
            return 1;
        }
        return df;
    }
    if (loc1 == n) {
        if (loc2 != n) {
            cout << "No" << endl;
            exit(0);
        }
        vis[loc1][loc2] = 1;
        df = 1;
        return dp[loc1][loc2] = dfs(g1[loc1][0], g2[loc2][0], df) | dfs(g1[loc1][1], g2[loc2][1], df) | dfs(g1[loc1][2], g2[loc2][2], df) | dfs(g1[loc1][3], g2[loc2][3], df);
    }
    vis[loc1][loc2] = 1;
    return dp[loc1][loc2] = dfs(g1[loc1][0], g2[loc2][0], df) | dfs(g1[loc1][1], g2[loc2][1], df) | dfs(g1[loc1][2], g2[loc2][2], df) | dfs(g1[loc1][3], g2[loc2][3], df);
}

int main() {
    fastio();
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 4; j++) {
            cin >> g1[i][j];
        }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 4; j++) {
            cin >> g2[i][j];
        }
    mss(dp);
    int flag = dfs(1, 1, 0);
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}