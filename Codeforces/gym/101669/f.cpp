#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<ll> C(n);
    for (auto& c : C) cin >> c;
    string src, dst;
    cin >> src >> dst;

    vector<pii> v11, v01, v10;
    for (int i = 0; i < n; i++) {
        if (src[i] == '1' and dst[i] == '1')
            v11.emplace_back(C[i], i);
        else if (src[i] == '1')
            v10.emplace_back(C[i], i);
        else if (src[i] == '0' and dst[i] == '1')
            v01.emplace_back(C[i], i);
    }
    sort(all(v11), greater<pii>());
    sort(all(v10), greater<pii>());
    sort(all(v01));

    ll ans = 1e18;
    auto o = v11.begin();
    for (;;) {
        ll s = 0;
        ll cans = 0;
        for (int i = 0; i < n; i++)
            if (src[i] == '1') s += C[i];
        for (auto& p : v10) {
            s -= p.x;
            cans += s;
        }
        for (auto& p : v01) {
            s += p.x;
            cans += s;
        }
        ans = min(ans, cans);
        if (o == v11.end()) break;
        v10.insert(lower_bound(all(v10), *o, greater<pii>()), *o);
        v01.insert(lower_bound(all(v01), *o), *o);
        o++;
    }
    cout << ans << endl;

    return 0;
}