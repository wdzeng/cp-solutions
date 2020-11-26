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

bool grid[60][60][4];

int E = 0, W = 1, N = 2, S = 3;

bool isins(int x, int y) { return (grid[x][y][0] or grid[x][y][1]) and (grid[x][y][2] or grid[x][y][3]); }

struct info {
    int x, y, dir;
    info(int x, int y, int d) : x(x), y(y), dir(d) {}
};

vector<info> go(int x, int y, int step, bool e, bool w, bool s, bool n) {
    if (step == 0) return {};

    vector<info> ret;
    if (s and grid[x][y][S]) {
        auto v = go(x, y - 1, step - 1, 1, 1, 1, 0);
        ret.insert(v.end(), v.begin(), v.end());
    }
    if (n and grid[x][y][N]) {
        auto v = go(x, y + 1, step - 1, 1, 1, 0, 1);
        ret.insert(v.end(), v.begin(), v.end());
    }
    if (w and grid[x][y][W]) {
        auto v = go(x - 1, y, step - 1, 0, 1, 1, 1);
        ret.insert(v.end(), v.begin(), v.end());
    }
    if (e and grid[x][y][E]) {
        auto v = go(x + 1, y, step - 1, 1, 0, 1, 1);
        ret.insert(v.end(), v.begin(), v.end());
    }
    return ret;
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int r;
    pii src;
    int t;
    cin >> r >> src.x >> src.y >> t;

    while (r--) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        if (x0 == x1) {
            int x = x0;
            if (y1 > y0) swap(y0, y1);
            grid[x][y0][N] = 1;
            grid[x][y1][S] = 1;
            for (int y = y0 + 1; y < y1; y++) {
                grid[x][y][N] = grid[x][y][S] = 1;
            }
        }  //
        else {
            int y = y0;
            if (x1 > x0) swap(x0, x1);
            grid[x0][y][E] = 1;
            grid[x1][y][W] = 1;
            for (int x = x0 + 1; x < x1; x++) {
                grid[x][y][E] = grid[x][y][W] = 1;
            }
        }
    }
    return 0;
}
