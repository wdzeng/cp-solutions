#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int N = 5010;
int g[N][N];
int n;
const int M = 5318008;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        pii src, dst;
        cin >> src.x >> src.y >> dst.x >> dst.y;
        if (src.x > dst.x) swap(src.x, dst.x);
        if (src.y > dst.y) swap(src.y, dst.y);
        if (dst.y - src.y > dst.x - src.x) swap(src.x, src.y), swap(dst.x, dst.y);

        ms(g);
        g[src.x][src.y] = 1;
        for (int x = src.x; x < dst.x; x++) {
            for (int y = 1; y <= n; y++) {
                g[x + 1][y - 1] += g[x][y];
                g[x + 1][y] += g[x][y];
                g[x + 1][y + 1] += g[x][y];
                g[x + 1][y - 1] %= M;
                g[x + 1][y] %= M;
                g[x + 1][y + 1] %= M;
            }
        }

        cout << g[dst.x][dst.y] << '\n';
    }
    return 0;
}