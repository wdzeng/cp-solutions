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
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    int ans;
    if (abs(x0 - x1) < abs(y0 - y1)) {
        swap(x0, y0), swap(x1, y1);
    }
    int dx = abs(x0 - x1);
    int dy = abs(y0 - y1);
    if (dx % 2 != dy % 2)
        ans = dx * 2 - 1;
    else
        ans = dx * 2;
    cout << ans << '\n';
    return 0;
}