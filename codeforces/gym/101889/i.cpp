#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int ,int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

const int N = 2e5 + 5;
vector<pii> adj[N];
int dep[N];
pair<int, int> fa[N][20];

void dfs(int v, pii r, int d) {
    fa[v][0] = r;
    dep[v] = d;
    for (auto a : adj[v])
        if (a.x != r.x) dfs(a.x, {v, a.y}, d + 1);
}

void build() {
    dfs(1, {0, 0}, 0);
    for (int k = 1; k < 20; k++)
        for (int i = 1; i < N; i++) {
            int u = fa[fa[i][k - 1].x][k - 1].x;
            int mx = max(fa[i][k - 1].y, fa[fa[i][k - 1].x][k - 1].y);
            fa[i][k] = {u, mx};
        }
}

int lcamax(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    int diff = dep[a] - dep[b];
    int ret = 0;
    while (diff) {
        int up = __lg(diff & -diff);
        ret = max(ret, fa[a][up].y);
        a = fa[a][up].x;
        diff -= (1 << up);
    }
    if (a == b) return ret;
    for (int i = 19; i >= 0; i--) {
        if (fa[a][i].x == fa[b][i].x) continue;
        ret = max(ret, fa[a][i].y);
        ret = max(ret, fa[b][i].y);
        a = fa[a][i].x;
        b = fa[b][i].x;
    }
    ret = max(fa[a][0].y, ret);
    ret = max(fa[b][0].y, ret);
    return ret;
}

vector<pii> gadj[N];
typedef pair<int, pii> piii;
unordered_set<int> adjm[N];
unordered_map<int, int> gadjm[N];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, r;
    cin >> n >> r;
    while (r--) {
        int a, b;
        int x;
        cin >> a >> b >> x;
        gadj[a].emplace_back(x, b);
        gadj[b].emplace_back(x, a);
        gadjm[a][b] = x;
        gadjm[b][a] = x;
    }

    priority_queue<piii, vector<piii>, greater<piii>> q;
    q.push({0, {1, 0}});
    int vis[N] = {0};
    while (!q.empty()) {
        auto a = q.top();
        q.pop();

        int u = a.y.x, s = a.y.y;
        int e = a.x;
        if(vis[u]) continue;
        vis[u] = 1;

        if (s && u) {
            adj[s].emplace_back(u, e);
            adj[u].emplace_back(s, e);
            adjm[s].insert(u);
            adjm[u].insert(s);
        }
        for (auto& j : gadj[u]) {
            if (vis[j.y]) continue;
            q.push({j.x, {j.y, u}});
        }
    }
    build();

    ll tree = 0;
    for (int i = 1; i <= n; i++) {
        for (auto& a : adj[i]) tree += a.y;
    }
    tree /= 2;
    int qu;
    cin >> qu;
    while (qu--) {
        int a, b;
        cin >> a >> b;
        if (adjm[a].count(b)) {
            cout << tree << '\n';
            continue;
        }
        ll lcal = lcamax(a, b);
        cout << tree - lcal + gadjm[a][b] << '\n';
    }

    return 0;
}