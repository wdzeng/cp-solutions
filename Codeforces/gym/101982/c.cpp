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

const ll M = 998244353;
ll dp[1010][1010];
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        int lv;
        cin >> lv;
        m[lv]++;
    }
    vector<int> v = {-1};
    for (auto& p : m) v.push_back(p.y);
    dp[0][0] = 1;
    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j <= k; j++) {
            if (j) dp[i][j] += dp[i - 1][j - 1] * v[i];
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= M;
        }
    }
    cout << dp[v.size() - 1][k] << endl;
    return 0;
}