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

    int n; ll s;
    cin >> n >> s;

    ll val[4][n];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val[i][j];
        }
    }

    ll ans = 0;
    unordered_map<ll, int> m;
    int l = 1, r = 2;
    while (r + 1 < n) {
        for (int i = 0; i < l; i++) {
            m[val[0][i] + val[1][l]]++;
        }
        for (int i = r + 1; i < n; i++) {
            ans += m[s - val[2][r] - val[3][i]];
        }
        l++, r++;
    }

    cout << ans << endl;
    return 0;
}
