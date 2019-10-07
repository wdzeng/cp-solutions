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
    int n;
    cin >> n;
    vector<int> d;
    while (n--) {
        int x;
        cin >> x;
        d.push_back(x);
    }

    int ans = INT_MAX;
    int ansi;
    for (int i = 0; i + 2 < d.size(); i++) {
        int t = max(d[i], d[i + 2]);
        if (t < ans) {
            ans = t;
            ansi = i;
        }
    }
    cout << ansi+1 << ' ' << ans << endl;
    return 0;
}