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

const int N = 500+10;
char q[N][N];

int solve() {
    int r, c;
    cin >> r >> c;
    int ans = 0;
    if (r == 1 || c == 1) {
        for (int i = 0; i < max(r, c); i++) {
            char x;
            cin >> x;
            if (i != 0 && i != max(r, c) - 1 && x == '.') ans++;
        }
        return ans;
    }

    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            cin >> q[x][y];
        }
    }

    if (r == 2) {
        for (int y = 1; y < c - 1; y++) {
            if (q[0][y] == '.' && q[1][y] == '.') ans++;
        }
        return ans;
    }
    if (c == 2) {
        for (int x = 1; x < r - 1; x++) {
            if (q[x][0] == '.' && q[x][1] == '.') ans++;
        }
        return ans;
    }

    for (int x = 1; x < r - 1; x++)
        for (int y = 1; y < c - 1; y++) ans += q[x][y] == '.';

    bool flag = true;
    for (int x = 1; x < r - 1 && flag; x++) {
        if (q[x][0] == '#' || q[x][c - 1] == '#') flag = false;
    }
    for (int y = 1; y < c - 1 && flag; y++) {
        if (q[0][y] == '#' || q[c - 1][y] == '#') flag = false;
    }
    if (flag) ans++;
    return ans;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cout << solve() << endl;
    return 0;
}