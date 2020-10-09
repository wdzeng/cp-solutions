#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int solve() {
    int n, w;
    cin >> n >> w;
    vector<pii> ranges;
    vector<int> dirs;
    vector<int> locs;
    bool hasBoat = 0;
    while (n--) {
        int l, r;
        cin >> l >> r;
        if (l == 0) hasBoat = 1;
        ranges.emplace_back(l, r);
        dirs.emplace_back(1);
        locs.emplace_back(l);
    }
    if (!hasBoat) {
        return -1;
    }

    n = ranges.size();
    int t = 0;
    int x = 0;
    while (x < w and t < w * w) {
        int right = 0;
        int stay = 0;
        for (int i = 0; i < n; i++) {
            if (locs[i] == x and dirs[i]) right = 1;
            if (locs[i] == x - 1 and dirs[i]) stay = 1;

            locs[i] += dirs[i] ? 1 : -1;
            if (locs[i] == ranges[i].y)
                dirs[i] = 0;
            else if (locs[i] == ranges[i].x)
                dirs[i] = 1;
        }
        if (right)
            x++;
        else if (!stay)
            x--;
        t++;
    }

    return x == w ? t : -1;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int ans = solve();
        if (ans == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << '\n';
    }
    return 0;
}