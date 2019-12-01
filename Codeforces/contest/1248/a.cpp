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

ll solve() {
    int n; cin >> n;
    int odd1 = 0, even1 = 0;
    while(n--) {
        int x; cin >> x; (x%2?odd1:even1)++;
    }
    int odd2=0, even2=0;
    cin >> n;
    while(n--) {
        int x; cin >> x; (x%2?odd2:even2)++;
    }
    return ll(odd1)*odd2 + ll(even1)*even2;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q; cin >> q; while(q--) cout << solve() << '\n';
    return 0;
}
