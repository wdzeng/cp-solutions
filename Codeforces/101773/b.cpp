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
    deque<ll> q;
    for (int i = 0; i < n; i++) {
        ll v;
        cin >> v;
        q.push_back(v);
    }

    ll ans = 0;
    ll prev = 0;
    while (q.size()) {
        ll v = q.front();
        q.pop_front();
        if (!prev) {
            prev = v;
            continue;
        }
        if (v == 0) {
            cout << -1 << endl;
            return 0;
        }

        int added = 0;
        while (v < prev) {
            v <<= 1;
            added++;
        }

        prev = v;
        ans += added;
        while (prev > 1e7) {
            ans += q.size();
            prev >>= 1;
        }

        // cout << added << ' ' << prev << endl;
    }

    cout << ans << endl;
    return 0;
}