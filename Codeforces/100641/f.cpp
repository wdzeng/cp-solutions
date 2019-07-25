#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
const int inf = 1000000;

struct info {
    bool hor;
    int step;
    int srclen = inf, dstlen = -1;
} grid[maxn][maxn];
int ncol, nrow, ansl, ansr, ansc, anss;
bool ansh;
vector<pair<int, int>> path;

void findsrc() {
    int r = 0, c = 0, l = 0;
    bool found = true;
    while (!(r == nrow - 1 && c == ncol - 1)) {
        // cout << r << " " << c << endl;
        if (r < 0 || r >= nrow || c < 0 || c >= ncol) {
            found = false;
            break;
        }
        auto& g = grid[r][c];
        if (g.srclen != inf) {
            found = false;
            break;
        }
        g.srclen = l++;
        path.push_back({r, c});
        int& x = g.hor ? c : r;
        x += g.step;
    }

    if (found) {
        ansl = l;
        l = 1;
        for (int i = path.size() - 1; i >= 0; --i) {
            auto& p = path[i];
            grid[p.first][p.second].dstlen = l++;
        }
    } else {
        ansl = inf;
        for (auto& p : path) {
            grid[p.first][p.second].dstlen = inf;
        }
    }
}

int finddst(int r, int c) {
    if (r < 0 || r >= nrow || c < 0 || c >= ncol) return inf;
    auto& g = grid[r][c];
    if (g.dstlen == -2) return inf;  // loop
    if (g.dstlen != -1) return g.dstlen;

    g.dstlen = -2;
    int nxtr = g.hor ? r : (r + g.step);
    int nxtc = g.hor ? (c + g.step) : c;
    int nxtlen = finddst(nxtr, nxtc);
    return g.dstlen = (nxtlen == inf ? inf : (nxtlen + 1));
}

void get_input() {
    int s;
    char dir;
    for (int r = 0; r < nrow; r++)
        for (int c = 0; c < ncol; c++) {
            if (r == nrow - 1 && c == ncol - 1) break;
            auto& g = grid[r][c];
            g.srclen = inf;
            g.dstlen = -1;
            int s;
            char dir;
            cin >> s >> dir;
            switch (dir) {
                case 'E':
                    g.hor = true;
                    g.step = s;
                    break;
                case 'W':
                    g.hor = true;
                    g.step = -s;
                    break;
                case 'N':
                    g.hor = false;
                    g.step = -s;
                    break;
                case 'S':
                    g.hor = false;
                    g.step = s;
                    break;
            }
        }
}

void task() {
    sort(path.begin(), path.end());
    for (auto& p : path) {
        int r = p.first;
        int c = p.second;
        int srclen = grid[r][c].srclen;
        for (int s = 1; c + s < ncol || r + s < nrow || c - s > 0 || r - s > 0; s++) {
            // east
            if (c + s < ncol) {
                int nxtr = r;
                int nxtc = c + s;
                int l = srclen + grid[nxtr][nxtc].dstlen + 1;
                if (l < ansl) {
                    ansl = l;
                    ansr = r;
                    ansc = c;
                    ansh = true;
                    anss = s;
                    if (nrow == 1 || ncol == 1) {
                        if (ansl == 1) return;
                    } else {
                        if (ansl == 2) return;
                    }
                }
            }
            // north
            if (r - s >= 0) {
                int nxtr = r - s;
                int nxtc = c;
                int l = srclen + grid[nxtr][nxtc].dstlen + 1;
                if (l < ansl) {
                    ansl = l;
                    ansr = r;
                    ansc = c;
                    ansh = false;
                    anss = -s;
                    if (nrow == 1 || ncol == 1) {
                        if (ansl == 1) return;
                    } else {
                        if (ansl == 2) return;
                    }
                }
            }
            // south
            if (r + s < nrow) {
                int nxtr = r + s;
                int nxtc = c;
                int l = srclen + grid[nxtr][nxtc].dstlen + 1;
                if (l < ansl) {
                    ansl = l;
                    ansr = r;
                    ansc = c;
                    ansh = false;
                    anss = s;
                    if (nrow == 1 || ncol == 1) {
                        if (ansl == 1) return;
                    } else {
                        if (ansl == 2) return;
                    }
                }
            }
            // west
            if (c - s >= 0) {
                int nxtr = r;
                int nxtc = c - s;
                int l = srclen + grid[nxtr][nxtc].dstlen + 1;
                if (l < ansl) {
                    ansl = l;
                    ansr = r;
                    ansc = c;
                    ansh = true;
                    anss = -s;
                    if (nrow == 1 || ncol == 1) {
                        if (ansl == 1) return;
                    } else {
                        if (ansl == 2) return;
                    }
                }
            }
        }
    }
}

void solve() {
    path.clear();
    ansr = -1;
    ansc = -1;
    get_input();
    findsrc();
    grid[nrow - 1][ncol - 1].dstlen = 0;
    for (int r = 0; r < nrow; r++)
        for (int c = 0; c < ncol; c++) finddst(r, c);
    task();
}

int main() {
    int t = 0;
    while (cin >> nrow >> ncol && nrow && ncol) {
        solve();
        printf("Case %d: ", ++t);
        if (ansl == inf)
            cout << "impossible";
        else if (ansr == -1 && ansc == -1)
            cout << "none " << ansl;
        else {
            printf("%d %d %d%c %d", ansr, ansc, abs(anss), ansh ? (anss > 0 ? 'E' : 'W') : (anss > 0 ? 'S' : 'N'), ansl);
        }
        cout << endl;
    }
    return 0;
}