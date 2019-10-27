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

int solve() {
    int c, m, z;
    cin >> c >> m >> z;
    int q = (c + m + z) / 3;
    return min(min(c,m), q);
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int q; cin >> q; while(q--)
    cout << solve () << endl;
    return 0;
}
