#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

vector<string> G;

inline void w(int x, int y, char c) {
    if (x < 0 || x >= zz(G) || y < 0 || y >= zz(G)) return;
    G[y][x] = c;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int m, n;
    while (cin >> m >> n) {
        G.resize(m);
        for (auto& g : G) g.assign(m, '.');

        for (int i = 0; i < n; i++) {
            int s, x, y;
            cin >> s >> x >> y;
            if (s == 0) {
                w(x - 1, y, '_');
                w(x, y, 'o');
                w(x + 1, y, '_');
                continue;
            }  //
            else {
                int _y = max(0, y);
                while (_y <= y + s + 1 && y < m) {
                    if (_y == y) {
                        w(x - 1, _y, '_');
                        w(x, _y, '|');
                        w(x + 1, _y, '_');
                    } else if (_y == y + s + 1) {
                        w(x, _y, '^');
                    } else {
                        w(x - 1, _y, '/');
                        w(x, _y, '|');
                        w(x + 1, _y, '\\');
                    }
                    _y++;
                }
            }
        }
        reverse(all(G));
        string b;
        b.assign(m + 2, '*');
        cout << b << '\n';
        for (auto& g : G) {
            cout << '*' << g << '*' << '\n';
        }
        cout << b << '\n';
        cout << '\n';
    }

    return 0;
}