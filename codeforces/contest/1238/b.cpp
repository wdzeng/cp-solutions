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

void solve() {
    int n; ll r;
    cin >> n >> r;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(iter(v));
    int ex = 0;
    int ans = 0;
    while(v.size() && v.back() > ans * r) {
        int d = v.back();
        while(v.size() && v.back() == d) v.pop_back();
        ans++;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q; cin >> q; while(q--) solve();
    return 0;
}