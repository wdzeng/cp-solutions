#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifndef hy
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#else
#define fastio()
#define debug(a) cout << #a << ": " << a << endl
#endif

int main() {
    fastio();
    int n, k;
    cin >> n >> k;
    vector<pair<pii, pii>> vec;
    set<ll> s;
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        vec.push_back({{i, a}, {b, c}});
    }
    sort(all(vec), [](pair<pii, pii> a, pair<pii, pii> b) { return a.x.y > b.x.y; });
    for (int i = 0; i < k; i++) s.insert(vec[i].x.x);
    sort(all(vec), [](pair<pii, pii> a, pair<pii, pii> b) { return a.y.x > b.y.x; });
    for (int i = 0; i < k; i++) s.insert(vec[i].x.x);
    sort(all(vec), [](pair<pii, pii> a, pair<pii, pii> b) { return a.y.y > b.y.y; });
    for (int i = 0; i < k; i++) s.insert(vec[i].x.x);
    cout << s.size() << endl;
    return 0;
}