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
#define mss(a) memset(a, 1, sizeof(a))
#define mp(e, f) make_pair(e, f)

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int val[n], minn;
    for (int i = 0; i < n; i++) cin >> val[i];
    minn = *min_element(val, val + n);

    int s = 0;
    int adjust = 0;
    for (int i = 0; i < n; i++) {
        s += val[i];
        if (i < k - 1) continue;

        if (i >= k) s -= val[i - k];
        if (s >= 0) {
            for (int x = i; x > i - k && s >= 0; x--) {
                int mindiff = min(s + 1, val[x] - minn);
                adjust += mindiff;
                s -= mindiff;
                val[x] -= mindiff;
            }
        }
    }

    cout << adjust << endl;
    for (int v : val) cout << v << ' ';
    cout << endl;
    return 0;
}