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
        int n; cin >> n;
        string s;
        cin >> s;
        int f = s.find_first_of('1'),
            e = s.find_last_of('1');
        if (f == -1)
            cout << s.size() << endl;
        else {
            f = s.size() - f;
            e++;
            int ans = max(f, e) * 2;
            cout << ans << endl;
        }
    }
    return 0;
}
