#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int color[maxn];
bool done[maxn];
int n, m;
int pc, nc = 0;

void foul() {
    cout << "impossible\n";
    exit(0);
}

void paint(int i, int col) {
    if (color[i] != 0 && color[i] != col) foul();
    if (color[i] == col) return;
    color[i] = col;
    if (col > 0)
        pc++;
    else
        nc++;
}

unordered_set<int> edges[maxn];

void task(int i) {
    if (done[i]) return;
    done[i] = true;
    for (int x : edges[i]) paint(x, -color[i]), task(x);
}

int main() {
    cin >> n >> m;
    int x, y, t;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> t;
        if (t == 1)
            edges[x].insert(y), edges[y].insert(x);
        else
            paint(x, t == 2 ? 1 : -1), paint(y, t == 2 ? 1 : -1);
    }

    for (int i = 1; i <= n; i++)
        if (color[i] != 0) task(i);

    int ans = pc;
    for (int i = 1; i <= n; i++) {
        if (!edges[i].empty() && color[i] == 0) {
            pc = nc = 0;
            paint(i, -2), task(i);
            ans += min(pc, nc);
        }
    }

    cout << ans << endl;
    return 0;
}