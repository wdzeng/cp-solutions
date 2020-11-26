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

void solve() {
    int h, n;
    cin >> h >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(iter(v));
    reverse(iter(v));

    list<int> l(iter(v));
    int ans = 0;
    while (l.size() > 1) {
        int c = l.front();
        l.pop_front();
        int cc = l.front();
        if (cc != c - 1) {
            l.push_front(l.front() + 1);
            continue;
        }

        l.pop_front();
        if (l.empty()) {
            if (c == 2) break;
            ans++;
            l.push_front(c - 2);
            continue;
        }

        if (l.front() != c - 2) {
            l.push_front(c - 2);
            ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}