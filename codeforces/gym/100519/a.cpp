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
#define mss(a) memset(a, 1, sizeof(a))
#define mp(e, f) make_pair(e, f)

vector<vector<int>> g;
int n;

ll left(int x) {
    ll ret = 0;
    vector<int> put;
    for (int y = 0; y < n; y++) {
        if (g[x][y]) put.push_back(g[x][y]);
    }
    vector<int> updated;
    int i;
    for (i = 1; i < put.size(); i++) {
        if (put[i] == put[i - 1]) {
            updated.push_back(put[i] * 2);
            ret += put[i] * 2;
            i++;
        } else {
            updated.push_back(put[i - 1]);
        }
    }
    if (i - 1 < put.size()) updated.push_back(put[i - 1]);
    updated.resize(n, 0);
    g[x].swap(updated);
    return ret;
}

ll right(int x) {
    reverse(iter(g[x]));
    ll ret = left(x);
    reverse(iter(g[x]));
    return ret;
}

void rotate() {
    vector<vector<int>> r(n, vector<int>(n));
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) r[x][y] = g[y][x];
    }
    g.swap(r);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    g.resize(n, vector<int>(n, 0));
    int o;
    cin >> o;
    while (o--) {
        int v, r, c;
        cin >> v >> r >> c;
        r--, c--;
        g[r][c] = v;
    }
    cin >> o;
    ll score = 0;
    while (o--) {
        char d;
        cin >> d;
        switch (d) {
        case 'L':
            for (int x = 0; x < n; x++) score += left(x);
            break;
        case 'R':
            for (int x = 0; x < n; x++) score += right(x);
            break;
        case 'U':
            rotate();
            for (int x = 0; x < n; x++) score += left(x);
            rotate();
            break;
        case 'D':
            rotate();
            for (int x = 0; x < n; x++) score += right(x);
            rotate();
            break;
        }
        int v, r, c;
        cin >> v >> r >> c;
        r--, c--;
        g[r][c] = v;
    }
    cout << score << endl;
    return 0;
}