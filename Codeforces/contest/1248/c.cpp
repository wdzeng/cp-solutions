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

const int maxn = 1e5 + 5;
const int M = 1e9 + 7;
ll dp[maxn];

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    dp[0] = 2;
    dp[1] = 4;
    for (int i = 2; i < max(m, n); i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= M;
    }
    cout << (dp[m - 1] + dp[n - 1] - 2) % M << endl;
    return 0;
}
