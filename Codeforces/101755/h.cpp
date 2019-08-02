#include <bits/stdc++.h>
using namespace std;
const int maxn = 200001;
typedef pair<int, int> point;
#define x first
#define y second

int r, c, d;
int bad[maxn];
bool visited[maxn];
int sx, sy, dx, dy;
queue<pair<point, int>> qm, q;

inline int loc(int x, int y) { return x * c + y; }
void setbad(int x, int y, int d) {
    if (x < 0 || y < 0 || x >= r || y >= c) return;
    if (bad[loc(x, y)] >= d) return;
    bad[loc(x, y)] = d;
    qm.push({{x, y}, d});
}
void go(int x, int y, int s) {
    if (x == dx && y == dy) {
        cout << s << endl;
        exit(0);
    }
    if (x < 0 || y < 0 || x >= r || y >= c) return;
    if (bad[loc(x, y)] > 0 || visited[loc(x, y)]) return;
    visited[loc(x, y)] = true;
    q.push({{x, y}, s});
}

int main() {
    cin >> r >> c >> d;

    for (int x = 0; x < r; x++) {
        string s;
        cin >> s;
        for (int y = 0; y < c; y++) {
            if (s[y] == 'S')
                sx = x, sy = y;
            else if (s[y] == 'F')
                dx = x, dy = y;
            else if (s[y] == 'M')
                setbad(x, y, d + 1);
        }
    }

    while (!qm.empty()) {
        point p = qm.front().first;
        int ss = qm.front().second - 1;
        qm.pop();

        if (ss == 0) continue;
        setbad(p.x - 1, p.y, ss);
        setbad(p.x + 1, p.y, ss);
        setbad(p.x, p.y - 1, ss);
        setbad(p.x, p.y + 1, ss);
    }

    if (bad[loc(dx, dy)] > 0) {
        cout << -1 << endl;
        return 0;
    }

    go(sx, sy, 0);
    while (!q.empty()) {
        point p = q.front().first;
        int ss = q.front().second + 1;
        q.pop();
        go(p.x - 1, p.y, ss);
        go(p.x + 1, p.y, ss);
        go(p.x, p.y - 1, ss);
        go(p.x, p.y + 1, ss);
    }

    cout << -1 << endl;
    return 0;
}