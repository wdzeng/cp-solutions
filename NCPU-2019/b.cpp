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

int c(int n) {
    int ret = 0;
    while (n) {
        if (n & 1) ret++;
        n >>= 1;
    }
    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        ll s = 0;
        for (int i = l; i <= r; i++) {
            s += c(i);
        }
        cout << s << '\n';
    }
    return 0;
}