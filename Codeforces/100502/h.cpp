#include <bits/stdc++.h>
using namespace std;
#define FOR(n) for (int i = 0; i < n; i++)
const int maxn = 200e3;
const int R = 360e3;
const int X = 1e6 + 99;
const int MOD = 1e9 + 7;
typedef unsigned long long ll;

ll hs(ll prev, int i) { return (prev * X + i + 1) % MOD; }

int main() {
    int n;
    cin >> n;
    vector<int> v(n), u(n);
    FOR(n) cin >> v[i];
    FOR(n) cin >> u[i];
    sort(v.begin(), v.end());
    sort(u.begin(), u.end());

    vector<int> a(n), b(n);
    FOR(n) {
        a[i] = ((v[(i + 1) % n] - v[i]) + R) % R;
        b[i] = ((u[(i + 1) % n] - u[i]) + R) % R;
    }

    b.resize(2 * n);
    copy_n(b.begin(), n, b.begin() + n);

    //   for (int i : a) cout << i << " ";
    //  cout << endl;
    //   for (int i : b) cout << i << " ";
    //   cout << endl;

    ll target = 0;
    for (int i : a) target = hs(target, i);
    //  cout << target << endl;

    bool match = [&]() {
        vector<ll> h = {0};
        int sum = 0;
        ll xx = 1;
        for (int i = 0; i < a.size(); i++) xx = xx * X % MOD;

        for (int i : b) {
            sum = hs(sum, i);
            h.push_back(sum);
        }

        // for (int i : h) cout << i << " ";
        // cout << endl;

        for (int i = 0; i < h.size() - a.size(); i++) {
            ll R = h[i + a.size()], l = h[i];
            ll h = (R - l * xx % MOD + MOD) % MOD;
            if (h == target) return true;
        }
        return false;
    }();

    cout << (match ? "possible" : "impossible") << endl;
    return 0;
}