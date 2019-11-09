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
    vector<bool> dp(100001, 0);
    dp[50000] = 1;
    int n;
    cin >> n;
    vector<int> val;
    while (n--) {
        int v;
        cin >> v;
        val.push_back(v);
    }
    random_shuffle(iter(val));
    for (int v : val) {
        vector<bool> u(100001, 0);
        for (int a = 0; a < 100001; a++) {
            if (!dp[a]) continue;
            int add = a + v;
            int sub = a - v;
            if (add >= 0 and add < 100001) u[add] = 1;
            if (sub >= 0 and sub < 100001) u[sub] = 1;
        }
        dp.swap(u);
    }

    for (int i = 0; i <= 50000; i++) {
        if (dp[50000 + i] || dp[50000 - i]) {
            cout << i << '\n';
            return 0;
        }
    }
    assert(false);
    return 0;
}
