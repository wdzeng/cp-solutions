#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

int solve() {
    int n;
    cin >> n;
    vector<pii> v;
    while (n--) {
        ll a, b;
        cin >> a >> b;
        v.emplace_back(a, 1);
        v.emplace_back(b, -1);
    }

    sort(iter(v), [](pii& a, pii& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y > b.y;
    });

    int c = 0;
    int ans = 0;
    for (auto& s : v) {
        c += s.y;
        ans = max(ans, c);
    }
    return ans;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) cout << solve() << '\n';
    return 0;
}
