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
#ifndef hy
#define endl '\n'
#endif

int main() {
#ifndef hy
    cin.tie(0), ios::sync_with_stdio(0);
#endif
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (a >= b) {
            if (a % b) {
                cout << a << endl;
            } else {
                vector<pii> m;
                for (int i = 2; i * i <= b; i++) {
                    if (b % i == 0) {
                        ll a = i;
                        while (b % a == 0) a *= i;
                        a /= i;
                        b /= a;
                        m.push_back({i, a});
                    }
                }
                if (b > 1) m.push_back({b, b});
                ll ans = 1;
                for (auto& p : m) {
                    int d = p.x;
                    int g = p.y;
                    ll pure = a;
                    while (pure % g == 0) pure /= d;
                    ans = max(ans, pure);
                }
                cout << ans << endl;
            }
        } else {
            cout << a << endl;
        }
    }

    return 0;
}