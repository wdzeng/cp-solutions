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

const int N = 405;
vector<int> adj[N];
vector<pii> A = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

namespace H {
const int N = 1605;
int vis[N], rnd, m[N];  // 跑完匈牙利之後配對結果儲存於此， -1 表示人醜
vector<int> g[N];       // 關係表

int dfs(int s) {
    for (int x : g[s]) {
        if (vis[x]) continue;
        vis[x] = 1;
        if (m[x] == -1 || dfs(m[x])) {
            m[x] = s, m[s] = x;
            return 1;
        }
    }
    return 0;
}

int hungarian(int p) {  // 傳入女性人數
    memset(m, -1, sizeof(m));
    int c = 0;
    for (int i = 0; i < p; i++) {
        if (m[i] == -1) {
            memset(vis, 0, sizeof(vis));
            c += dfs(i);
        }
    }
    return c;
}
}  // namespace H

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int X, Y;
    cin >> X >> Y;
    vector<string> G(X);
    for (auto& str : G) cin >> str;
    for (int x = 0; x < X; x++) {
        for (int y = 0; y < Y; y++) {
            int srcid = x * Y + y;
            for (auto& a : A) {
                int i = x + a.x, j = y + a.y;
                if (i < 0 or i >= X or j < 0 or j >= Y) continue;
                int dstid = i * Y + j;
                adj[srcid].push_back(dstid);
            }
        }
    }

    int o = 0;
    auto& E = H::g;
    int XY = X * Y;
    for (int x = 0; x < X; x++) {
        for (int y = 0; y < Y; y++) {
            int id = x * Y + y;
            if (G[x][y] == 'o') {
                o++;
                for (int a : adj[id]) {
                    pii d(a / Y, a % Y);
                    E[id].push_back(a + XY * 2);
                    if (G[d.x][d.y] != 'o') E[id].push_back(a + XY * 3);
                }
            } else {
                for (int a : adj[id]) {
                    pii d(a / Y, a % Y);
                    E[id].push_back(a + XY * 2);
                    if (G[d.x][d.y] != 'o') E[id].push_back(a + XY * 3);
                    E[id + XY].push_back(a + XY * 2);
                    if (G[d.x][d.y] != 'o') E[id + XY].push_back(a + XY * 3);
                }
            }
        }
    }

    int res = H::hungarian(XY * 2);
    // cout << res << endl;
    if (res == XY * 2 - o)
        cout << "Y\n";
    else
        cout << "N\n";

    return 0;
}