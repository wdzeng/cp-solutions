#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifndef hy
#define endl '\n'
#endif

int main() {
#ifndef hy
    cin.tie(0), ios::sync_with_stdio(0);
#endif

    int C, R;
    cin >> C >> R;
    int n;
    cin >> n;
    vector<int> minn(C, 1e9), maxx(C, 0);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        minn[x] = min(minn[x], y);
        maxx[x] = max(maxx[x], y);
    }
    ll lc = 0, ls = 0, rc = 0, rs = 0;
    vector<pii> ev;
    for (int i = 0; i < C; i++) {
        if (minn[i] > maxx[i]) continue;
        ev.push_back({minn[i], 1});
        ev.push_back({maxx[i], 0});
        rc++;
        rs += maxx[i];
    }
    sort(all(ev));
    reverse(all(ev));
    ll ans = rs;
    ll cur = rs;
    for (int i = 0; i <= R + 1; i++) {
        while (ev.size() && ev.back().x == i) {
            auto u = ev.back();
            ev.pop_back();
            if (u.y == 1) {
                rc--;
            } else {
                lc++;
            }
        }
        cur += lc;
        cur -= rc;
        ans = min(ans, cur);
    }
    
    cout << ans * 2 + C - 1 << endl;
    return 0;
}