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
    freopen("A.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k, m;
    while (cin >> n >> k >> m && n) {
        m--;
        int pos = 0;
        for (int i = 1; i <= n; i++) {
            pos = (pos + k) % i;
        }
        int first = m - k + 1;
        pos = ((pos + first) % n + n) % n;
        cout << pos + 1 << endl;
    }
    return 0;
}