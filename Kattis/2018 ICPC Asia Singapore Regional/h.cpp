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

const int maxn = 4e5 + 10;
const int godown = 1;
const int goup = 2;
const int goleft = 3;
const int goright = 4;

int deg[maxn];
vector<int> adj[maxn];
int dir[maxn];

vector<int> rows[maxn], cols[maxn];
vector<int> dirvec[5];
vector<pii> i2l;
map<pii, int> l2i;

int R, C;
vector<int> ans;
bool added[maxn];

void dfs(int v) {
    if (added[v]) return;
    added[v] = 1;
    ans.emplace_back(v);
    for (int a : adj[v]) {
        if (added[a]) continue;
        deg[a]--;
        if (deg[a] == 0) dfs(a);
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> R >> C >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pii p = mp(x, y);
        l2i[p] = l2i.size();
        i2l.push_back(p);
        rows[x].push_back(y);
        cols[y].push_back(x);
    }

    for (auto& v : rows) sort(iter(v));
    for (auto& v : cols) sort(iter(v));

    bool vis[n];
    ms(vis);

    stack<int> k;
    k.push(0);

    while (k.size()) {
        auto v = k.top();
        k.pop();
        vis[v] = 1;

        auto go = [&](pii p, int d) {
            if (!l2i.count(p)) return;
            int u = l2i[p];
            if (vis[u]) return;
            dir[u] = d;
            dirvec[d].push_back(u);
            vis[u] = 1;
            k.push(u);
            adj[v].push_back(u);
            deg[u]++;
        };

        auto& p = i2l[v];
        go({p.x + 1, p.y}, goup);
        go({p.x, p.y + 1}, goleft);
        go({p.x - 1, p.y}, godown);
        go({p.x, p.y - 1}, goright);
    }

    for (auto& v : dirvec[goup]) {
        auto& p = i2l[v];
        auto a = upper_bound(iter(cols[p.y]), p.x);
        if (a == cols[p.y].end()) continue;
        assert(l2i.count(mp(*a, p.y)));
        int u = l2i[mp(*a, p.y)];
        if (dir[u] == goup) continue;
        adj[v].push_back(u);
        deg[u]++;
        // printf("bind %d %d\n", v, u);
    }
    for (auto& v : dirvec[godown]) {
        auto& p = i2l[v];
        auto a = lower_bound(iter(cols[p.y]), p.x);
        if (a == cols[p.y].begin()) continue;
        a--;
        assert(l2i.count(mp(*a, p.y)));
        int u = l2i[mp(*a, p.y)];
        if (dir[u] == godown) continue;
        adj[v].push_back(u);
        deg[u]++;
        // printf("bind %d %d\n", v, u);
    }
    for (auto& v : dirvec[goleft]) {
        auto& p = i2l[v];
        auto a = upper_bound(iter(rows[p.x]), p.y);
        if (a == rows[p.x].end()) continue;
        assert(l2i.count(mp(p.x, *a)));
        int u = l2i[mp(p.x, *a)];
        if (dir[u] == goleft) continue;
        adj[v].push_back(u);
        deg[u]++;
        // printf("bind %d %d\n", v, u);
    }
    for (auto& v : dirvec[goright]) {
        auto& p = i2l[v];
        auto a = lower_bound(iter(rows[p.x]), p.y);
        if (a == rows[p.x].begin()) continue;
        a--;
        assert(l2i.count(mp(p.x, *a)));
        int u = l2i[mp(p.x, *a)];
        if (dir[u] == goright) continue;
        adj[v].push_back(u);
        deg[u]++;
        // printf("bind %d %d\n", v, u);
    }

    if (deg[0] == 0) dfs(0);
    if (ans.size() != n)
        cout << "impossible\n";
    else {
        assert(ans[0] == 0);
        printf("possible\n");
        for (int i = 1; i < ans.size(); i++) {
            char c;
            int d;
            switch (dir[ans[i]]) {
            case goup:
                c = '^';
                d = i2l[ans[i]].y;
                break;
            case godown:
                c = 'v';
                d = i2l[ans[i]].y;
                break;
            case goleft:
                c = '<';
                d = i2l[ans[i]].x;
                break;
            case goright:
                c = '>';
                d = i2l[ans[i]].x;
                break;
            }
            printf("%c %d\n", c, d);
        }
    }
    return 0;
}