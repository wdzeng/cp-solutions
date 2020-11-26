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
        ll ans = 0;
        int a, b, c;
        cin >> a >> b >> c;
        while (c > 1 && b) c -= 2, b--, ans++;
        while (b > 1 && a) b -= 2, a--, ans++;
        cout << ans * 3 << '\n';
    }
    return 0;
}
