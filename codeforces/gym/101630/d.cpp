#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second.first
#define z second.second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifdef hy
#define fastio()
#define debug(a) cout << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

vector<pair<int, pii>> solve(int yz, int zx, int xy) {
    if (zx < yz) {
        auto ans = solve(zx, yz, xy);
        for (auto& p : ans) swap(p.x, p.y);
        return ans;
    }
    if (xy < yz) {
        auto ans = solve(xy, zx, yz);
        for (auto& p : ans) swap(p.x, p.z);
        return ans;
    }
    if (xy < zx) {
        auto ans = solve(yz, xy, zx);
        for (auto& p : ans) swap(p.y, p.z);
        return ans;
    }
    if (yz * zx < xy) {
        cout << -1 << endl;
        exit(0);
    }

    set<pii> ret;
    for (int i = 0; i < yz; i++) ret.insert({i, i});
    for (int i = yz; i < zx; i++) ret.insert({i, 0});
    while (ret.size() < xy) {
        int _x = rand() % zx;
        int _y = rand() % yz;
        ret.insert({_x, _y});
    }

    vector<pair<int, pii>> ans;
    for (auto& p : ret) ans.push_back({p.first, {p.second, 0}});
    return ans;
}

int main() {
    fastio();
    int xy, yz, zx;
    cin >> xy >> zx >> yz;
    auto ans = solve(yz, zx, xy);
    cout << ans.size() << endl;
    for (auto& p : ans) {
        cout << p.x << ' ' << p.y << ' ' << p.z << endl;
    }
    return 0;
}