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

int solve(const vector<int>& v) {
    unordered_map<int, int> dp;
    for (int val : v) {
        unordered_map<int, int> u = dp;
        u[val] = max(dp[val], 1);
        for (auto& p : dp) {
            int c = p.first;
            int lowbit = -c & c;
            if (lowbit >= val) u[c + val] = max(dp[c] + 1, u[c + val]);
        }
        dp.swap(u);
    }
    int ret = 0;
    for (int i = 1; i < 256000; i <<= 1) ret = max(ret, dp[i]);
    return ret;
}

int yap(int a, int b) {
    if (b % a != 0) return 0;
    b /= a;
    if (b == 1 or b == 2 or b == 4 or b == 8 or b == 16 or b == 32 or b == 64 or b == 128 or b == 256) return b;
    return 0;
}

int f(int v) {
    while (v % 2 == 0) v /= 2;
    return v;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    while (1) {
        cin >> n;
        if (!n) exit(0);
        vector<int> v;
        while (n--) {
            int a;
            cin >> a;
            v.push_back(a);
        }

        int ans = 0;
        unordered_map<int, vector<int>> m;
        for (int val : v) {
            int fac = f(val);
            m[fac].push_back(val / fac);
        }
        for (auto& p : m) {
            if (p.y.size() > ans) ans = max(ans, solve(p.second));
        }

        cout << ans << '\n';
    }
    return 0;
}
