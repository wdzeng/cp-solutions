#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);

#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

int g[121][121][41];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int n;
    int minx, maxx, miny, maxy, minz, maxz;
    cin >> n >> minx >> maxx >> miny >> maxy >> minz >> maxz;
    while (n--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x > maxx || y > maxy || z > maxz) continue;
        for (int xx = maxx - x; xx > -1; xx--)
            for (int yy = maxy - y; yy > -1; yy--)
                for (int zz = maxz - z; zz > -1; zz--) {
                    g[xx + x][yy + y][zz + z] += g[xx][yy][zz];
                }
        g[x][y][z]++;
    }

    int ans = 0;
    for (int x = minx; x <= maxx; x++)
        for (int y = miny; y <= maxy; y++)
            for (int z = minz; z <= maxz; z++) ans += g[x][y][z];
    cout << ans << endl;
    return 0;
}