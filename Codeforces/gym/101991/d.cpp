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

const int maxn = 2020;
int g[maxn][maxn];

void pD() {
    int r, c, q;
    cin >> r >> c >> q;
    unordered_map<int, int> o2c;
    set<pii> points;
    vector<int> c2o;
    set<int> nums;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        nums.insert(x);
        nums.insert(y);
        points.emplace(x, y);
    }
    nums.insert(r), nums.insert(c);

    for (int i : nums) {
        o2c[i] = o2c.size();
        c2o.push_back(i);
    }

    set<pii> ptmp;
    for (auto& p : points) {
        ptmp.emplace(o2c[p.x], o2c[p.y]);
    }
    points.swap(ptmp);

    int R = o2c[r], C = o2c[c];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (points.count({i, j})) g[i][j]++;
            g[i][j] += g[i][j - 1];
        }
    }

    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++) {
            g[i][j] += g[i - 1][j];
        }
    }

    ll ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (g[i][j] & 1) {
                ll dx = c2o[i + 1] - c2o[i];
                ll dy = c2o[j + 1] - c2o[j];
                ans += dx * dy;
            }
        }
    }

    cout << ans << ' ' << ll(r) * c - ans << endl;
}

int main() {
    // freopen("dull.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) pD(), ms(g);
    return 0;
}