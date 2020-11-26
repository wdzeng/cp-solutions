#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll x, s;

    cin >> x >> s;
    ll sbk = s;
    if (s < x) {
        cout << -1 << endl;
        return 0;
    }

    ll a = 0, b = 0, c = 0;
    for (int i = 0; s >> i; i++) {
        // cout << x << ' ' << s << endl;
        bool xb = ((x >> i) & 1ll);
        bool xxb = ((x >> (i + 1)) & 1ll);
        bool sb = ((s >> i) & 1ll);
        bool ssb = ((s >> (i + 1)) & 1ll);

        if (xb != sb) {
            cout << -1;
            return 0;
        }
        if (!xb && !sb) {
            if (xxb != ssb) {
                a |= (1ll << i);
                b |= (1ll << i);
                s = (ll((s >> (i + 1)) - 1) << (i + 1)) | ll(s & ((1ll << (i + 1)) - 1));
            }
        } else {
            if (xxb != ssb) {
                a |= (1ll << i);
                b |= (1ll << i);
                c |= (1ll << i);
                s = (ll((s >> (i + 1)) - 1) << (i + 1)) | ll(s & ((1ll << (i + 1)) - 1));
            } else
                a |= (1ll << i);
        }
    }

    if (a + b + c != sbk) {
        cout << -1 << endl;
        return 0;
    }
    
    vector<ll> v = {a, b, c};
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    while (!v.empty() and v.back() == 0) v.pop_back();
    cout << v.size() << endl;
    for (ll val : v) cout << val << ' ';
    cout << endl;
    return 0;
}