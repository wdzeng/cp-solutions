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

int R, C;
pii src, dst;
bool g[60][60];

vector<vector<pii>> mns;
int mnslcd = 1;

typedef pair<pii, int> state;

bool face(pii& a, pii& b) {
    if (a.x != b.x && a.y != b.y) return false;
    if (a.y == b.y) {
        int s = min(a.x, b.x), t = max(a.x, b.x);
        for (int i = s + 1; i < t; i++) {
            if (!g[i][a.y]) return false;
        }
    } else {
        int s = min(a.y, b.y), t = max(a.y, b.y);
        for (int i = s + 1; i < t; i++) {
            if (!g[a.x][i]) return false;
        }
    }
    return true;
}

bool safe(pii& a, int t) {
    for (auto& m : mns) {
        auto& loc = m[t % m.size()];
        if (face(a, loc)) return false;
    }
    return true;
}

int task() {
    set<state> record;
    queue<state> q;

    auto i_state = make_pair(src, 0);
    record.insert(i_state);
    q.push(i_state);

    auto putin = [&](int x, int y, int t) {
        if (x < 0 || x >= R) return;
        if (y < 0 || y >= C) return;
        if (!g[x][y]) return;

        pii p = {x, y};
        if (p == dst) throw "";
        if (!safe(p, t)) {
            // printf("Not safe: %d %d\n", p.x, p.y);
            return;
        }
        state s = {p, t % mnslcd};
        if (record.count(s)) return;
        record.insert(s);

        s = {p, t};
        q.push(s);
    };

    while (!q.empty()) {
        const auto& state = q.front();
        int t = state.y + 1;
        int x = state.x.x;
        int y = state.x.y;
        // printf("(%d,%d,%d) ", x, y, t);
        // cout << t << ' ' << flush;

        q.pop();
        // record.insert(state);

        try {
            putin(x, y, t);
            putin(x - 1, y, t);
            putin(x + 1, y, t);
            putin(x, y - 1, t);
            putin(x, y + 1, t);
        } catch (...) {
            return t;
        }
    }

    return -1;
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    // cin >> R >> C;
    char dc;

    scanf("%d%d", &R, &C);
    // cout << R << endl << C << endl;
    scanf(" %c%d%c%d%c%c%c%d%c%d%c", &dc, &(src.x), &dc, &(src.y), &dc, &dc, &dc, &(dst.x), &dc, &(dst.y), &dc);
    src.x--, src.y--, dst.x--, dst.y--;
    // cout << src.x << src.y << dst.x << dst.y << endl;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            g[i][j] = s[j] == '.';
        }
    }

    int nmonster;
    cin >> nmonster;
    for (int i = 0; i < nmonster; i++) {
        vector<pii> v;
        int s;
        cin >> s;
        while (s--) {
            pii p;
            scanf(" %c%d%c%d%c", &dc, &p.x, &dc, &p.y, &dc);
            p.x--;
            p.y--;
            // cout << p.x << ' ' << p.y << endl;
            v.push_back(p);
        }
        for (int z = v.size() - 2; z > 0; z--) v.push_back(v[z]);
        mns.push_back(v);
        mnslcd = mnslcd * v.size() / __gcd(mnslcd, (int)v.size());
    }
    // cout << mnslcd << endl;

    if (!safe(src, 0)) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int ret = task();
    if (ret == -1)
        cout << "IMPOSSIBLE\n";
    else
        cout << ret << endl;
    return 0;
}