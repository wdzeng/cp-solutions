#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define x first
#define y second
#define iter(x) x.begin(), x.end()

const int MAXN = 1000;
int R, C;
int grid[MAXN][MAXN];
int maxx[MAXN][MAXN];

int solve() {
    cin >> R >> C;
    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            cin >> grid[x][y];
        }
    }

    maxx[0][0] = grid[0][0];

    for (int sum = 1; sum < R + C - 1; sum++) {
        for (int x = 0, y = sum - x; x <= sum; x++, y--) {
            if (x >= R || y >= C) continue;
            if (x == 0)
                maxx[x][y] = maxx[x][y - 1] + grid[x][y];
            else if (y == 0)
                maxx[x][y] = maxx[x - 1][y] + grid[x][y];
            else {
                maxx[x][y] = max(maxx[x - 1][y], maxx[x][y - 1]) + grid[x][y];
            }
        }
    }

    return maxx[R-1][C-1];
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case %d: %d\n", i, solve());
    }
    return 0;
}