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

string g[105];
int vis[105][105];
int X, Y;
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> X >> Y;
    for (int x = 0; x < X; x++) cin >> g[x];
    int cnt = 0;
    for (int x = 0; x < X; x++) {
        for (int y = 0; y < Y; y++) {
            if (g[x][y] == '.') continue;
            if (vis[x][y]) continue;
            vector<pii> k = {{x, y}};
            vis[x][y] = ++cnt;
            while (!k.empty()) {
                auto u = k.back();
                k.pop_back();
                for (int dx = -1; dx < 2; dx++) {
                    int xx = u.x + dx;
                    if (xx < 0 || xx >= X) continue;
                    for (int dy = -1; dy < 2; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        int yy = u.y + dy;
                        if (yy < 0 || yy >= Y) continue;
                        if (vis[xx][yy]) continue;
                        if (g[xx][yy] == '.') continue;
                        vis[xx][yy] = cnt;
                        k.push_back({xx, yy});
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}