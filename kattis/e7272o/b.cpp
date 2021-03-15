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

const ll M = 2147483647;
int main() {
    fastio();
    int n;
    cin >> n;
    int l, r;
    cin >> l >> r;

    map<pii, ll> m;
    m[{l, r}] = 1;
    n--;
    while (n--) {
        map<pii, ll> mm;
        int x;
        cin >> x;
        for (auto& p : m) {
            if (p.x.x < x && x < p.x.y) {
                mm[{p.x.x, x}] += p.y;
                mm[{p.x.x, x}] %= M;
                mm[{x, p.x.y}] += p.y;
                mm[{x, p.x.y}] %= M;
            } else {
                if (x < p.x.x) {
                    mm[{x, p.x.y}] += p.y;
                    mm[{x, p.x.y}] %= M;
                } else {
                    mm[{p.x.x, x}] += p.y;
                    mm[{p.x.x, x}] %= M;
                }
            }
        }
        m.swap(mm);
    }
    ll ans = 0;
    for(auto& p : m) {
        ans += p.y;
        ans %= M;
    }
    cout << ans << endl;
    return 0;
}