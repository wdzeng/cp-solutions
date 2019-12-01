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

int a[1010][1010];
int b[1010][1010];
const ll m = 1e9 + 7;

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        int v;
        cin >> v;
        for (int x = 0; x < v; x++) a[i][x] = 1;
        a[i][v] = -1;
    }
    for (int i = 0; i < w; i++) {
        int v;
        cin >> v;
        for (int x = 0; x < v; x++) b[x][i] = 1;
        b[v][i] = -1;
    }
    ll ans = 1;
    for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) {
            if (!a[x][y] && !b[x][y]) ans = ans * 2 % m;
            else if(a[x][y] * b[x][y] == -1) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}