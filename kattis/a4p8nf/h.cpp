#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

int solve(ll n, ll x, ll y) {
    if (n == 1) return 1;
    if (x >= n / 2 && y >= n / 2) return -solve(n / 2, x - n / 2, y - n / 2);
    if (x >= n / 2 && y < n / 2) return solve(n / 2, x - n / 2, y);
    if (x < n / 2 && y >= n / 2) return solve(n / 2, x, y - n / 2);
    return solve(n / 2, x, y);
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        ll n, x, y, w, h;
        cin >> n >> x >> y >> w >> h;
        for (int i = y; i < y + h; i++) {
            for (int j = x; j < x + w; j++) {
                cout << solve(n, j, i) << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}