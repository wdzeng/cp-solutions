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
void foul() {
    cout << "invalid" << endl;
    exit(0);
}

int main() {
    fastio();
    vector<string> g(8);

    auto test = [&](int x, int y) {
        for (int i = -8; i <= 8; i++) {
            if (i == 0) continue;
            int xx = x - i;
            int yy = y - i;
            if (xx < 0 || xx >= 8 || yy < 0 || yy >= 8) continue;
            if (g[xx][yy] == '*') foul();
        }
        for (int i = -8; i <= 8; i++) {
            if (i == 0) continue;
            int xx = x + i;
            int yy = y - i;
            if (xx < 0 || xx >= 8 || yy < 0 || yy >= 8) continue;
            if (g[xx][yy] == '*') foul();
        }
        for (int i = -8; i <= 8; i++) {
            if (i == 0) continue;
            int xx = x + i;
            if (xx < 0 || xx >= 8) continue;
            if (g[xx][y] == '*') foul();
        }
        for (int i = -8; i <= 8; i++) {
            if (i == 0) continue;
            int yy = y - i;
            if (yy < 0 || yy >= 8) continue;
            if (g[x][yy] == '*') foul();
        }
    };
    int cnt = 0;
    for (int i = 0; i < 8; i++) cin >> g[i];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (g[i][j] == '*') {
                cnt++;
                test(i, j);
            }
        }
    }
    if (cnt != 8) foul();
    cout << "valid" << endl;
    return 0;
}