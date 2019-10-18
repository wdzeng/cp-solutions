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
    int q;
    cin >> q;
    while (q--) {
        int a, b, aa, bb, t;
        cin >> a >> b >> aa >> bb >> t;
        int sa = a && aa ? ((a - 1) / aa + 1) : 0,
            sb = b && bb ? ((b - 1) / bb + 1) : 0;
        if (sa + sb > t)
            cout << -1 << endl;
        else
            cout << sa << ' ' << sb << endl;
    }
    return 0;
}
