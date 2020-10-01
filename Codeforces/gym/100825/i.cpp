#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int N = 15;
int g[N][N];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<string> mmap(n);
    for (auto& s : mmap) cin >> s;

    string secret;
    cin >> secret;

    vector<pii> h;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (mmap[x][y] == '.') h.emplace_back(x, y);
        }
    }

    if (h.size() * 4 != n * n) {
        cout << "invalid grille" << endl;
        return 0;
    }

    mss(g);

    for (int t = 0; t < 4; t++) {
        auto hh = h;
        sort(all(hh));
        for (int q = 0; q < hh.size(); q++) {
            g[hh[q].x][hh[q].y] = secret[t * hh.size() + q];
            int nx = hh[q].y;
            int ny = n - hh[q].x - 1;
            hh[q] = {nx, ny};
        }
        h.swap(hh);
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (g[x][y] == -1) {
                cout << "invalid grille" << endl;
                return 0;
            }
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cout << (char)g[x][y];
        }
    }
    cout << endl;

    return 0;
}