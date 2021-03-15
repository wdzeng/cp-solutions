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
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

const int N = 1e3 + 5;
int X, Y;
string g[N];
int rec[N][N];
typedef pair<int, int> point;
queue<point> q;
int vis[N][N];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(point p) {
    if (vis[p.x][p.y]) return;
    vector<point> v = {p};
    vis[p.x][p.y] = 1;
    while (!v.empty()) {
        auto b = v.back();
        v.pop_back();
        // cout << b.x << ',' << b.y << endl;
        assert(b.x >= 0 && b.x < X);
        assert(b.y >= 0 && b.y < Y);
        assert(vis[b.x][b.y]);
        for (int dir = 0; dir < 8; dir++) {
            int nx = b.x + dx[dir];
            int ny = b.y + dy[dir];
            if (nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
            if (vis[nx][ny]) continue;
            if (g[b.x][b.y] != g[nx][ny]) continue;
            vis[nx][ny] = 1;
            rec[nx][ny] = rec[b.x][b.y];
            assert(rec[nx][ny] > 0);
            // cout << nx << ',' << ny << endl;
            v.push_back({nx, ny});
        }
        q.push(b);
    }
    // cout << "---" << endl;
}

int main() {
    fastio();
    cin >> X >> Y;
    for (int x = 0; x < X; x++) {
        cin >> g[x];
    }

    set<char> fq;
    for (int x = 0; x < X; x++) {
        for (int y = 0; y < Y; y++) {
            if (g[x][y] == 'W') {
                q.push({x, y});
                rec[x][y] = 0;
                vis[x][y] = 1;
            } else {
                fq.insert(g[x][y]);
            }
        }
    }

    assert(!q.empty());
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        int x = u.x, y = u.y;
        assert(vis[x][y]);
        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
            if (vis[nx][ny]) continue;
            // debug(x);
            // debug(y);
            // debug(nx);
            // debug(ny);
            // debug(g[x][y]);
            // debug(g[nx][ny]);
            assert(g[x][y] != g[nx][ny]);
            rec[nx][ny] = rec[x][y] + 1;
            assert(rec[nx][ny] > 0);
            dfs({nx, ny});
        }
    }

    vector<int> minn(300, 5000);
    for (int x = 0; x < X; x++) {
        for (int y = 0; y < Y; y++) {
            if (g[x][y] == 'W') continue;
            // debug(x);
            // debug(y);
            // debug(g[x][y]);
            // debug(rec[x][y]);
            assert(minn[g[x][y]] > 0);
            assert(rec[x][y] > 0);
            minn[g[x][y]] = min(minn[g[x][y]], rec[x][y]);
        }
    }
    for (char c : fq) {
        assert(minn[c] >= 1);
        cout << c << ' ' << minn[c] - 1 << endl;
    }

    return 0;
}