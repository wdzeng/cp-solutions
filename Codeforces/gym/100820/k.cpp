#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

inline int dd(const pii& p, int n) {
    return p.x * n + p.y;
}

vector<string> G;
vector<pii> ans;
vector<pii> _d = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

inline int good(const pii& p, int n) {
    const int n = G.size();
    return p.x >= 0 and p.x < n and p.y >= 0 and p.y < n;
}

inline int group(const pii& a, const pii& b) {
    return (a.x + b.x + a.y + b.y) % 8 == 0;
}

inline void done() {
    if (ans.empty()) {
        cout << "None" << endl;
        exit(0);
    }
    if (ans.size() > 1) {
        cout << "Multiple" << endl;
        exit(0);
    }
    pii p = ans[0];
    cout << p.x << ' ' << p.y << endl;
    exit(0);
}

void judge(const pii& src) {
    cout << src.x << ' ' << src.y << endl;
    assert(G[src.x][src.y] != '.');

    const int n = G.size();
    const int nn = n * n;
    vector<int> adj[nn];
    set<int> vx;

    pii p = src;
    while (p.x < n) {
        for (; p.y < n; p.y += 4) {
            if (G[p.x][p.y] != 'B') continue;
            for (int i = 0; i < 4; i++) {
                int dx = _d[i].x, dy = _d[i].y;
                pii l(p.x + dx, p.y + dx);
                pii ll(p.x + dx + dx, p.y + dy + dy);

                if (!good(l, n)) continue;
                if (!good(ll, n)) continue;
                if (G[l.x][l.y] != 'W') continue;
                if (G[ll.x][ll.y] == 'W') return;
                if (G[ll.x][ll.y] == 'B') return;

                int u = dd(ll, n);
                int v = dd(p, n);
                adj[u].push_back(v);
                adj[v].push_back(u);
                vx.insert(u);
                vx.insert(v);
            }
        }
        p.x += 2;
        p.y = (p.y + 2) % n;
    }
    cout << vx.size() << endl;
    if (vx.empty()) return;

    int c = 0;
    int o = *vx.begin();
    vector<int> vis(nn);
    vector<int> k = {o};
    vis[o] = 1;
    while (!k.empty()) {
        int u = k.back();
        k.pop_back();
        c++;
        for (int a : adj[u]) {
            if (vis[a]) continue;
            k.push_back(a);
        }
    }

    if (c != vx.size()) return;
    int odd;
    for (auto& v : adj)
        if (v.size() % 2) odd++;
    if (odd > 2) return;

    if (odd == 0) {
        p = src;
        while (p.x < n) {
            for (; p.y < n; p.y += 4) {
                if (G[p.x][p.y] != 'B') continue;
                ans.push_back(p);
            }
            p.x += 2;
            p.y = (p.y + 2) % n;
        }
    } else {
        p = src;
        while (p.x < n) {
            for (; p.y < n; p.y += 4) {
                if (G[p.x][p.y] != 'B') continue;
                if (adj[dd(p, n)].size()) ans.push_back(p);
            }
            p.x += 2;
            p.y = (p.y + 2) % n;
        }
    }
}

pii awhite() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] == 'W') return {i, j};
        }
    }
    throw "";
}

void jwhite() {
    const int n = G.size();

    for (int i = 0; i < n; i++) {
        if (G[i][0] == 'W') done();
        if (G[i][n - 1] == 'W') done();
        if (G[0][i] == 'W') done();
        if (G[n - 1][i] == 'W') done();
    }

    pii w = awhite();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] != 'W') continue;
            int dx = abs(i - w.x), dy = abs(j - w.y);
            if (dx % 2 or dy % 2) done();
        }
    }
}

vector<pii> coll(int src, int dx, int dy) {
    const int n = G.size();
    vector<pii> k = {src};
    set<pii> vis = {src};
    while (!k.empty()) {
        auto u = k.back();
        k.pop_back();

        pii v = {u.x + d.x, d.y + d.y};
        pii w = {u.x - d.x, d.y - d.y};
        if (!vis.count(v) and good(v)) {
            k.push_back(v);
            vis.insert(v);
        }
        if (!vis.count(w) and good(w)) {
            k.push_back(w);
            vis.insert(w);
        }
    }
    return vector<pii>(all(vis));
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        G.push_back(s);
    }

    jwhite();

    if (n == 2) {
        done();
    }
    if (n == 3) {
        if (G[0][0] == '.') {
            done();
        }
        judge({0, 0});
        judge({0, 2});
        done();
    }

    if (G[0][0] == '.') {
        judge({0, 1});
        judge({0, 3});
        judge({1, 0});
        judge({1, 2});
    } else {
        judge({0, 0});
        judge({0, 2});
        judge({1, 1});
        judge({1, 3});
    }

    done();

    return 0;
}