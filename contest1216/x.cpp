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

const int N = 55;
ll g[N][N], dp[N][N];
int n;

void drf(int x, int y, int px, int step, int lim, ll sum) {
    
    if (step == lim) {
        ll S = dp[n][n];
        if (step % 2 == 1) {  // go up
            sum += dp[x][y] - dp[px][y];
           // cout << x << ' ' << y << ' ' << step << ' ' << lim << ' '  << sum << endl;
            if (sum + sum == S) {
                cout << "YES " << lim - 1 << endl;
                throw "";
            }
        } else {  // go right
           
            sum += dp[n][y] - dp[x][y];
            // cout << x << ' ' << y << ' ' << step << ' ' << lim << ' '  << sum << endl;
            if (sum + sum == S) {
                cout << "YES " << lim - 1 << endl;
                throw "";
            }
        }
        return;
    } 
   // cout << x << ' ' << y << ' ' << step << ' ' << lim << ' '  << sum << endl;
    if (step % 2 == 1) {  // have gone right, now go up
        sum += dp[x][y] - dp[px][y];
        for (int yy = y - 1; yy >= 0; yy--)
            drf(x, yy, x, step + 1, lim, sum);
    } else {
        for (int xx = x + 1; xx <= n; xx++) {
            drf(xx, y, x, step + 1, lim, sum);
        }
    }
}

void duf(int x, int y, int px, int step, int lim, ll sum) {
    if (step == lim) {
        ll S = dp[n][n];
        if (step % 2 == 1) {  // go right
            sum += dp[n][y] - dp[x][y];
           // cout << x << ' ' << y << ' ' << step << ' ' << lim << ' '  << sum << endl;
            if (sum + sum == S) {
                cout << "YES " << lim - 1 << endl;
                throw "";
            }
        } else {  // go up
            sum += dp[x][y] - dp[px][y];
           // cout << x << ' ' << y << ' ' << step << ' ' << lim << ' '  << sum << endl;
            if (sum + sum == S) {
                cout << "YES " << lim - 1 << endl;
                throw "";
            }
        }
        return;
    } else if (step % 2 == 1) {  // go right
      //  cout << x << ' ' << y << ' ' << step << ' ' << lim << ' '  << sum << endl;
        for (int xx = x + 1; xx <= n; xx++)
            duf(xx, y, x, step + 1, lim, sum);
    } else {  // go up
        sum += dp[x][y] - dp[px][y];
       // cout << x << ' ' << y << ' ' << step << ' ' << lim << ' '  << sum << endl;
        for (int yy = y - 1; yy >= 0; yy--) {
            duf(x, yy, x, step + 1, lim, sum);
        }
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ms(g);
        ms(dp);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> g[j][i];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + g[i][j];
            }
        }

       // cout << dp[n][n] << endl;
        try {
            //int lim = 4;
            for (int lim = 1; lim <= 6; lim++) {
                drf(0, n, 0, 0, lim, 0);
                duf(0, n, 0, 0, lim, 0);
            }
            cout << "NO" << endl;
        } catch (...) {
        }
    }
    return 0;
}