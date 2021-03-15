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

ll t(ll f) {
    return f * f * f;
}

ll solve(ll s, ll a, ll b, ll c) {
    //if (a > b) swap(a, b);
    //if (a > c) swap(a, c);
    //if (b > c) swap(b, c);
    ll q = s - a;
    ll r = s - b;
    ll o = s - a - b;
    return t(q) + t(r) - t(o);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    vector<pii> ans;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll s, a, b, c;
        cin >> s >> a >> b >> c;
        ans.emplace_back(solve(s, a, b, c), i);
    }
    sort(all(ans));
    for (auto& a : ans) cout << a.y + 1 << ' ';
    cout << endl;
    return 0;
}