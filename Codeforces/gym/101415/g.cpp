#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const double PI = acos(-1);
#define x first
#define y second
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
 
const pii O = {0, 0};
 
struct piii {
    const pii xx;
    const pii yy;
    const pii zz;
    piii(const pii& a, const pii& b = O, const pii& c = O) : xx(a), yy(b), zz(c) {}
};
 
int dx[5] = {-1, 0, 0, 0, 1};
int dy[5] = {0, -1, 0, 1, 0};
 
inline int absmin(int a, int b) { return abs(a) < abs(b) ? a : b; }
 
struct pG {
    const int R, C, N;
    const vector<string>& g;
    pii src[3], dst[3];
 
    pG(const vector<string>& g, int n) : g(g), R(g.size()), C(g[0].size()), N(n) {
        src[0] = src[1] = src[2] = dst[0] = dst[1] = dst[2] = O;
        for (int x = 0; x < R; x++)
            for (int y = 0; y < C; y++)
                if (g[x][y] == ' ' || g[x][y] == '#')
                    continue;
                else if (islower(g[x][y]))
                    src[g[x][y] - 'a'] = {x, y};
                else
                    dst[g[x][y] - 'A'] = {x, y};
    }
 
    inline bool valid(int x, int y) { return x >= 0 && x < R && y >= 0 && y < C && g[x][y] != '#'; }
 
    int solve() {
        short vis[16][16][16][16][16][16];
        ms(vis);
        vis[src[0].x][src[0].y][src[1].x][src[1].y][src[2].x][src[2].y] = 1;
        vis[dst[0].x][dst[0].y][dst[1].x][dst[1].y][dst[2].x][dst[2].y] = -1;
        queue<piii> q[2];
        q[0].emplace(src[0], src[1], src[2]);
        q[1].emplace(dst[0], dst[1], dst[2]);
 
        auto next = [&](int i) {
            queue<piii> uq;
            auto& oq = q[i];
 
            while (!oq.empty()) {
                const auto v = oq.front();
                int s = abs(vis[v.xx.x][v.xx.y][v.yy.x][v.yy.y][v.zz.x][v.zz.y]) + 1;
                if (i == 1) s *= -1;
                oq.pop();
 
                for (int i0 = 0; i0 < 5; i0++) {
                    pii e = {v.xx.x + dx[i0], v.xx.y + dy[i0]};
                    if (!valid(e.x, e.y)) continue;
                    if (N == 1) {
                        if (e == v.xx) continue;
                        auto& ss = vis[e.x][e.y][0][0][0][0];
                        if (!ss) {
                            ss = s;
                            uq.emplace(e);
                            continue;
                        }
                        if (ss < 0 != s < 0) return abs(ss) + abs(s) - 2;
                        continue;
                    }
                    for (int i1 = 0; i1 < 5; i1++) {
                        pii f = {v.yy.x + dx[i1], v.yy.y + dy[i1]};
                        if (!valid(f.x, f.y)) continue;
                        if (f == e) continue;
                        if (e == v.yy && f == v.xx) continue;
                        if (N == 2) {
                            if (e == v.xx && f == v.yy) continue;
                            auto& ss = vis[e.x][e.y][f.x][f.y][0][0];
                            if (!ss) {
                                ss = s;
                                uq.emplace(e, f);
                                continue;
                            }
                            if (ss < 0 != s < 0) return abs(ss) + abs(s) - 2;
                            continue;
                        }
 
                        for (int i2 = 0; i2 < 5; i2++) {
                            pii w = {v.zz.x + dx[i2], v.zz.y + dy[i2]};
                            if (!valid(w.x, w.y)) continue;
                            if (w == e || w == f) continue;
                            if (w == v.xx && e == v.zz) continue;
                            if (w == v.yy && f == v.zz) continue;
 
                            if (e == v.xx && f == v.yy && w == v.zz) continue;
                            auto& ss = vis[e.x][e.y][f.x][f.y][w.x][w.y];
                            if (!ss) {
                                ss = s;
                                uq.emplace(e, f, w);
                                continue;
                            }
                            if (ss < 0 != s < 0) return abs(ss) + abs(s) - 2;
                        }
                    }
                }
            }
 
            oq.swap(uq);
            return -1;
        };
 
        while (1) {
            int r = next(0);
            if (r != -1) return r;
            r = next(1);
            if (r != -1) return r;
        }
    }
};
 
int main() {
    freopen("G.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    int r, c, n;
    while (cin >> c >> r >> n && r) {
        vector<string> g(r);
        getline(cin, g[0]);
        for (int i = 0; i < r; i++) {
            getline(cin, g[i]);
        }
        int ans = pG(g, n).solve();
        cout << ans << endl;
    }
    return 0;
}