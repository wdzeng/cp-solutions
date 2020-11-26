#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

const int N = 1005;
const int NN = N * N;
#define ID(x, y) ((x)*N + (y))
int fa[NN], sz[NN];

vector<pii> jh;  // join history

int par(int v) {
    if (fa[v] == v) return v;
    return par(fa[v]);
}

int join(int a, int b) {
    int _a = a, _b = b;
    a = par(a), b = par(b);
    if (a == b) {
        jh.emplace_back(-1, -1);
        return 0;
    }
    if (sz[a] < sz[b]) swap(a, b);
    jh.emplace_back(a, b);
    fa[b] = a;
    sz[a] += sz[b];
    return 1;
}

void undo() {
    assert(!jh.empty());
    auto u = jh.back();
    jh.pop_back();
    int a, b;
    tie(a, b) = u;
    if (a == -1) return;
    fa[b] = b;
    sz[a] -= sz[b];
}

void reset() {
    for (int i = 0; i < NN; i++) fa[i] = i, sz[i] = 1;
    jh.clear();
}

int X, Y;
int g[N][N];
int lc[N], rc[N], gc;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> X >> Y;
    for (int i = 0; i < X; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < Y; j++) g[i][j] = s[j] - '0';
    }

    // scan from left
    reset();
    for (int y = 0; y < Y; y++) {
        if (y > 0) lc[y] = lc[y - 1];
        for (int x = 0; x < X; x++) {
            if (g[x][y] == 1) continue;
            lc[y]++;
            if (x > 0 and g[x - 1][y] == 0) {
                lc[y] -= join(ID(x, y), ID(x - 1, y));
            }
            if (y > 0 and g[x][y - 1] == 0) {
                lc[y] -= join(ID(x, y), ID(x, y - 1));
            }
        }
    }

    // scan from right
    reset();
    for (int y = Y - 1; y >= 0; y--) {
        if (y < Y - 1) rc[y] = rc[y + 1];
        for (int x = 0; x < X; x++) {
            if (g[x][y]) continue;
            rc[y]++;
            if (x > 0 and g[x - 1][y] == 0) {
                rc[y] -= join(ID(x, y), ID(x - 1, y));
            }
            if (y < Y - 1 and g[x][y + 1] == 0) {
                rc[y] -= join(ID(x, y), ID(x, y + 1));
            }
        }
    }

    // link blacks
    reset();
    vector<pii> DIRS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int vis[NN] = {0};
    for (int x = 0; x < X; x++) {
        for (int y = 0; y < Y; y++) {
            if (g[x][y] == 0) continue;
            if (vis[ID(x, y)]) continue;
            gc++;
            vector<pii> k = {{x, y}};
            vis[ID(x, y)] = 1;
            while (!k.empty()) {
                auto u = k.back();
                k.pop_back();
                for (auto& d : DIRS) {
                    int newx = u.x + d.x, newy = u.y + d.y;
                    if (newx < 0 or newx >= X or newy < 0 or newy >= Y) continue;
                    if (g[newx][newy] == 0) continue;
                    if (vis[ID(newx, newy)]) continue;
                    vis[ID(newx, newy)] = 1;
                    k.emplace_back(newx, newy);
                    join(ID(u.x, u.y), ID(newx, newy));
                }
            }
        }
    }

    jh.clear();
    int maxw = -1;
    int maxk = -1;
    int ans;
    for (int y = 0; y < Y; y++) {
        int k = gc;
        int w = (y == 0 ? 0 : lc[y - 1]) + (y == (Y - 1) ? 0 : rc[y + 1]);
        for (int x = 0; x < X; x++) {
            if (g[x][y] == 0) k++;
            if (x > 0) k -= join(ID(x, y), ID(x - 1, y));
            if (y > 0 && g[x][y - 1] == 1) k -= join(ID(x, y), ID(x, y - 1));
            if (y < Y - 1 && g[x][y + 1] == 1) k -= join(ID(x, y), ID(x, y + 1));
        }
        if (w + k > maxw + maxk) {
            maxw = w, maxk = k, ans = y;
        } else if (w + k == maxw + maxk) {
            if (w > maxw)
                maxw = w, maxk = k, ans = y;
        }
        while (!jh.empty()) undo();
    }
    cout << maxw << ' ' << maxk << endl;
    return 0;
}