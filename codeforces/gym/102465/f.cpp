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
#endif

typedef pair<pii, ll> point;
pii operator-(pii a, pii b) { return {a.x - b.x, a.y - b.y}; }
ll operator*(pii a, pii b) { return a.x * b.y - a.y * b.x; }

int main() {
#ifndef hy
    cin.tie(0), ios::sync_with_stdio(0);
#endif
    int n;
    cin >> n;
    vector<point> vec(n);
    ll ans = 1e18;
    for (auto& p : vec) cin >> p.x.x >> p.x.y >> p.y;
    for (int i = 0; i < n; i++) {
        vector<pair<double, point>> _vp;
        point o = vec[i];
        for (int j = 0; j < n; j++)
            if (j != i) _vp.push_back({atan2(vec[j].x.y - o.x.y, vec[j].x.x - o.x.x), vec[j]});
        sort(all(_vp), [&](pair<double, point> a, pair<double, point> b) {
            return a.x < b.x;
        });
        vector<point> vp;
        for (auto& p : _vp) vp.push_back(p.y);
        queue<point> neg, pos;
        ll negsum = 0, possum = 0;
        auto p = vp[0];
        for (int i = 1; i < n - 1; i++) {
            ll cz = (vp[i].x - o.x) * (p.x - o.x);
            if (cz < 0)
                negsum += vp[i].y, neg.push(vp[i]);
            else
                possum += vp[i].y, pos.push(vp[i]);
        }
        ans = min(ans, abs(possum - negsum));
        for (int j = 0; j < n - 2; j++) {
            pos.push(p);
            possum += p.y;
            if (!neg.empty()) {
                p = neg.front();
                neg.pop();
                negsum -= p.y;
            } else {
                assert(!pos.empty());
                p = pos.front();
                pos.pop();
                possum -= p.y;
            }
            while (!pos.empty() && (pos.front().x - o.x) * (p.x - o.x) < 0) {
                possum -= pos.front().y;
                negsum += pos.front().y;
                neg.push(pos.front());
                pos.pop();
            }
            ans = min(ans, abs(possum - negsum));
        }
    }
    cout << ans << endl;
    return 0;
}