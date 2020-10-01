#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
typedef unsigned long long ull;

const int N = 20;
ull dp[1 << N];
ll before[N][N];
int c[N];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto& val : v) cin >> val;
    unordered_map<int, int> m;

    for (auto& _val : v) {
        if (!m.count(_val)) m[_val] = m.size();
        _val = m[_val];
    }

    const int M = m.size();

    for (auto val : v) {
        for (int a = 0; a < M; a++) {
            if (a == val) continue;
            before[val][a] += c[a];
        }
        c[val]++;
    }

    mss(dp);
    dp[0] = 0;

    for (int i = 0; i < (1 << M); i++) {
        for (int a = 0; a < M; a++) {
            ll ans = 0;
            if (!((i >> a) & 1)) continue;
            for (int b = 0; b < M; b++) {
                if (b == a) continue;
                if ((i >> b) & 1) continue;
                ans += before[a][b];
            }
            dp[i] = min(dp[i], dp[i - (1 << a)] + ans);
        }
    }

    cout << dp[(1 << M) - 1] << endl;

    return 0;
}