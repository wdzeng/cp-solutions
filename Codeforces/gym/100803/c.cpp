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
    // cin.tie(0), ios::sync_with_stdio(0);
    int n, r;
    cin >> n >> r;
    vector<int> res(n + 1, 0);
    while (r--) {
        int a, b;
        cin >> a >> b;
        if (a > b) continue;
        res[a] = max(res[a], b);
    }

    int ans = 0;
    int look = 0;
    int minn = 1e9;
    for (int i = 1; i <= n; i++) {
        if (i == look) {
            ans += (look - minn) * 2;
            minn = 1e9;
        }
        if (res[i]) {
            look = max(look, res[i]);
            minn = min(i, minn);
        }
    }

    cout << ans + (n + 1) << endl;
    return 0;
}
