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

const int N = 1e5 + 5;
const ll M = 1e9 + 7;
ll dp[N];
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
#ifndef hy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    s = "  " + s;
    dp[0] = dp[1] = 1;
    for (int i = 2; i < s.size(); i++) {
        dp[i] += dp[i - 1];
        if (s[i] == 'W' or s[i] == 'E') {
            if (s[i - 1] == 'N' or s[i - 1] == 'S')
                dp[i] += dp[i - 2];
        }
        dp[i] %= M;
    }
    cout << dp[s.size() - 1] << endl;
    return 0;
}