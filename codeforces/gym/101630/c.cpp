#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifdef hy
#define fastio()
#define debug(a) cout << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

const int N = 1e5 + 5;
vector<vector<int>> adj, radj;

set<pii> s;
vector<int> vis;
int dfs(int v) {
    vis[v] = 1;
    for (int a : adj[v]) {
        if (!vis[a]) {
            s.insert({v, a});
            dfs(a);
        }
    }
}

set<pii> rs;
vector<int> rvis;
int rdfs(int v) {
    rvis[v] = 1;
    for (int a : radj[v]) {
        if (!rvis[a]) {
            rs.insert({a, v});
            rdfs(a);
        }
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pii> e;
        adj.assign(n, {});
        radj.assign(n, {});
        s.clear();
        rs.clear();
        vis.assign(n, 0);
        rvis.assign(n, 0);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            adj[a].push_back(b);
            radj[b].push_back(a);
            e.push_back({a, b});
        }
        dfs(0);
        rdfs(0);
        int rem = m - 2 * n;
        for (auto& p : e) {
            if (s.count(p)) continue;
            if (rs.count(p)) continue;
            cout << p.x + 1 << ' ' << p.y + 1 << endl;
            if (--rem == 0) break;
        }
    }
    return 0;
}