#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t lll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

int main() {
    fastio();
    int q;
    cin >> q;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        vector<pair<ll, int>> P;
        for (ll i = 2; i * i <= b; i++) {
            int cnt = 0;
            while (b % i == 0) b /= i, cnt++;
            if (cnt) P.push_back({i, cnt});
        }
        if (b > 1) P.push_back({b, 1});

        lll ans = 1e18;
        ans *= ans;
        for (auto& pr : P) {
            ll p = pr.x;
            int t = pr.y;
            lll r = p;
            ll cnt = 0;
            while (r <= a) {
                cnt += a / r;
                r *= p;
            }
            cnt /= t;
            ans = min(ans, cnt);
        }
        cout << (ll)ans << endl;
    }
    return 0;
}