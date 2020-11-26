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
    int q;
    cin >> q;
    while (q--) {
        int r, g, b;
        cin >> r >> g >> b;
        if (r > g) swap(r, g);
        if (r > b) swap(r, b);
        if (g > b) swap(g, b);
        int diff = b - g;

        if (diff >= r) {
            int ans = r + min(g, b);
            cout << ans << '\n';
        } else {
            r -= diff;
            b -= diff;
            int ans = diff;

            b -= r / 2;
            g -= r - (r / 2);
            ans += r + min(g, b);
            cout << ans << '\n';
        }
    }
    return 0;
}
