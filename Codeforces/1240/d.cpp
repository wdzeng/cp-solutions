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

ll solve() {
    int n;
    cin >> n;
    int val[n + 1];
    val[0] = 0;
    for (int i = 1; i <= n; i++) cin >> val[i];

    vector<map<int, int>> maps(n + 1);
    vector<int> link(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int v = val[i];
        int match = maps[i - 1][v];
        if (match) {
            link[i] = match;
            maps[i].swap(maps[match - 1]);
        }
        maps[i][v] = i;
    }

    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (!link[i]) continue;
        ans[i] = 1 + ans[link[i] - 1];
    }

    ll ret = 0;
    for (int a : ans) ret += a;
    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q; cin >> q; while(q--) cout << solve() << '\n';
    return 0;
}