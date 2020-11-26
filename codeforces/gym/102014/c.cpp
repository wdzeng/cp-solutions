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

const int maxn = 500;
bool wall[maxn][maxn];

bool safe(int i) { return i >= 0 and i < maxn; }

void paint(int x, int y) {
    stack<pii> k;
    k.emplace(x, y);
    while (k.size()) {
        pii p = k.top();
        k.pop();
        if (!safe(p.x) or !safe(p.y)) continue;
        if (wall[p.x][p.y]) continue;
        wall[p.x][p.y] = 1;
        k.emplace(p.x, p.y - 1);
        k.emplace(p.x, p.y + 1);
        k.emplace(p.x + 1, p.y);
        k.emplace(p.x - 1, p.y);
    }
}

void solve(int n) {
    ms(wall);
    vector<pii> src, dst;
    set<int> s;
    while (n--) {
        int x0, y0, x1, y1;
        cin >> x0 >> y1 >> x1 >> y0;
        src.emplace_back(x0, y0);
        dst.emplace_back(x1, y1);
        s.insert(x0);
        s.insert(x1);
        s.insert(y0);
        s.insert(y1);
    }
    unordered_map<int, int> m;
    for (int val : s) m[val] = m.size() * 2 + 1;
    for (auto& p : src) p.x = m[p.x], p.y = m[p.y];
    for (auto& p : dst) p.x = m[p.x], p.y = m[p.y];
    for (int i = 0; i < src.size(); i++) {
        for (int x = src[i].x; x <= dst[i].x; x++) wall[x][src[i].y] = wall[x][dst[i].y] = 1;
        for (int y = src[i].y; y <= dst[i].y; y++) wall[src[i].x][y] = wall[dst[i].x][y] = 1;
    }

    ll ans = 0;
    for (int x = 0; x < maxn; x++) {
        for (int y = 0; y < maxn; y++) {
            if (wall[x][y]) continue;
            ans++;
            paint(x, y);
        }
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    while (cin >> n and n) solve(n);
    return 0;
}
