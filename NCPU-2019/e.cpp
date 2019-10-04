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

void solve(int n) {
    vector<ll> v = {1};
    vector<vector<ll>> all = {v};
    for (int i = 1; i < n; i++) {
        vector<ll> u = {1};
        for (int j = 0; j + 1 < i; j++) {
            u.push_back(v[j] + v[j + 1]);
        }
        u.push_back(1);
        v.swap(u);
        all.push_back(v);
    }

    for (int i = 0; i < all.size(); i++) {
        ll m = v[i];
        for (ll l : all[i]) cout << l * m << ' ';
        cout << '\n';
    }
}

int main() {
     cin.tie(0), ios::sync_with_stdio(0);
    int n;
    while (cin >> n) solve(n + 1);
    return 0;
}