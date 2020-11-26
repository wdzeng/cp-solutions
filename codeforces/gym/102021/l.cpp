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

vector<vector<int>> g;
vector<vector<int>> ans;

void dec(int x, int y) {
    if (g[x][y] == 0) throw "";
    g[x][y]--;
}

void decall(int x, int y) {
    dec(x - 1, y - 1);
    dec(x - 1, y);
    dec(x - 1, y + 1);
    dec(x, y - 1);
    dec(x, y);
    dec(x, y + 1);
    dec(x + 1, y - 1);
    dec(x + 1, y);
    dec(x + 1, y + 1);
}

int R, C;
void solve() {
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[0].size(); j++) {
            cin >> g[i][j];
        }
    }

    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            if (g[x][y] == 0)
                ans[x + 1][y + 1] = -1;
            else if (g[x][y] == 1) {
                ans[x + 1][y + 1] = 1;
                decall(x + 1, y + 1);
            } else
                throw "";
        }
    }

    for (auto& v : g) {
        for (int i : v)
            if (i != 0) throw "";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> R >> C;
    g.assign(R + 2, vector<int>(C + 2));
    ans.assign(R + 2, vector<int>(C + 2));
    try {
        solve();
    } catch (...) {
        cout << "impossible\n";
        return 0;
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            assert(abs(ans[i][j]) == 1);
            cout << (ans[i][j] == 1 ? 'X' : '.');
        }
        cout << '\n';
    }
    return 0;
}