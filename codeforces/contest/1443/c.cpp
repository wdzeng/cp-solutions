#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pii> v(n);
        for (auto& p : v) cin >> p.x;
        for (auto& p : v) cin >> p.y;
        sort(all(v));
        reverse(all(v));
        ll sum = 0;
        ll ans = 1e18;
        for (auto& p : v) {
            ans = min(ans, max(sum,p.x));
            sum += p.y;
        }
        ans = min(sum, ans);
        cout << ans << '\n';
    }

    return 0;
}