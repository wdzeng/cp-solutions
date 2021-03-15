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

int dfs(int a, int b, int df) {
    if (a == 0) return df;
    if (~dp[a][b]) return dp[a][b];
    if (vis[a][b]) {
        if (a == n) return 1;
        return df;
    }
    if (a == n && b != n) {
        cout << "No" << endl;
        exit(0);
    }
    vis[a][b] = 1;
    int ok = 0;
    for (int i = 0; i < 4; i++) {
        ok |= dfs(g1[a][i], g2[b][i], df || a == n && b == n);
    }
    return dp[a][b] = ok;
}

int main() {
    fastio();
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 4; j++) cin >> g1[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 4; j++) cin >> g2[i][j];
    mss(dp);
    int f = dfs(1, 1, 0);
    cout << (f ? "Yes" : "Impossible") << endl;
    return 0;
}