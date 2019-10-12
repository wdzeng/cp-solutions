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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    ll h;
    cin >> n >> h;
    vector<ll> rt1, lt1, rt0, lt0;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        if ((x - y) % 2 == 0) {
            rt0.push_back(x - y);
            lt0.push_back(x + y);
        } else {
            rt1.push_back(x - y);
            lt1.push_back(x + y);
        }
    }
    sort(iter(rt0));
    sort(iter(rt1));
    sort(iter(lt0));
    sort(iter(lt1));

    ll ans = 0;
    for (ll x : rt0) {
        auto a = lower_bound(iter(lt0), x);
        auto b = upper_bound(iter(lt0), x + (h - 1) * 2);
        ans += (b - a) - 1;
    }
    for (ll x : rt1) {
        auto a = lower_bound(iter(lt1), x);
        auto b = upper_bound(iter(lt1), x + (h - 1) * 2);
        ans += (b - a) - 1;
    }

    ll all = n * (h - 1) * 2;
    cout << all - ans << endl;
    return 0;
}