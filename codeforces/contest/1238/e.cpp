#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(m, vector<int>(m));

    string s;
    cin >> s;
    for (int i = 1; i < n; i++) {
        int x = s[i] - 'a', y = s[i - 1] - 'a';
        adj[x][y]++, adj[y][x]++;
    }

    vector<ll> dp(1 << m, LLONG_MAX);
    for (int k = 0; k < (1 << m); k++) {
        int c = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if ((k >> i & 1) != (k >> j & 1)) c += adj[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            if (!(k >> i & 1)) continue;
            int kk = k - (1 << i);
            dp[k] = min(dp[k], dp[kk] + c);
        }
        if (dp[k] == LLONG_MAX) dp[k] = 0;
    }

    cout << dp[(1 << m) - 1] << '\n';
    return 0;
}