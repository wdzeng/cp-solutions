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

int b[102][102];
int n;
void put(int x, int y, int c) {
    if (x < 0 || x >= n || y < 0 || y >= n) return;
    if (b[x][y]) return;
    b[x][y] = c;
    put(x - 2, y - 1, c * -1);
    put(x - 2, y + 1, c * -1);
    put(x + 2, y - 1, c * -1);
    put(x + 2, y + 1, c * -1);
    put(x - 1, y - 2, c * -1);
    put(x - 1, y + 2, c * -1);
    put(x + 1, y - 2, c * -1);
    put(x + 1, y + 2, c * -1);
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            put(i, j, 1);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (b[i][j] == 1 ? "W" : "B");
        }
        cout << endl;
    }
    return 0;
}
