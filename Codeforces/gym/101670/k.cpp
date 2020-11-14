#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vv;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

const int N = 1e5 + 5;

namespace Simple {
vector<int> adj[N];
int indeg[N];

void solve(int n) {
    for (int i = 0; i < n; i++)
        for (int x : adj[x]) indeg[x++;]
}
}  // namespace Simple

pii solve(const vector<int>& cands, const vv& adj, const vv& radj) {
    vector<int> stk;
    int vis[N] = {0};

    for (int src : cands) {
        if (vis[src]) continue;
        vector<int> k = {src};
        while (!k.empty()) {
            int u = k.back();
            k.pop_back();
            stk.push_back(u);
            vis[u] = 1;
            for (int a : adj[u])
                if (!vis[a]) vis[a] = 1, k.push_back(a);
        }
    }

    vv group;
    ms(vis);
    while (!stk.empty()) {
        int s = stk.back();
        stk.pop_back();
        if (vis[s]) continue;
        cout << s << ' ';
        group.emplace_back();
        vector<int>& G = group.back();
        vector<int> k = {s};
        while (!k.empty()) {
            int u = k.back();
            k.pop_back();
            G.push_back(u);
            vis[u] = 1;
            for (int a : radj[u])
                if (!vis[a]) vis[a] = 1, k.push_back(a);
        }
    }
    cout << group.size() << endl;
    return {group[0][0], group.back()[0]};
}

void solve(int n, int m) {
    vv adj(n), radj(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    vector<pii> links;
    int vis[N] = {0};
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vector<int> cands;
        vector<int> stk = {i};
        while (!stk.empty()) {
            int u = stk.back();
            stk.pop_back();
            cands.push_back(u);
            for (int a : adj[u])
                if (!vis[a]) vis[a] = 1, stk.push_back(a);
            for (int a : radj[u])
                if (!vis[a]) vis[a] = 1, stk.push_back(a);
        }
        links.push_back(solve(cands, adj, radj));
    }

    vector<pii> ans;
    if (links.size() == 1) {
        if (links[0].x != links[0].y) ans.push_back(links[0]);
    } else {
        links.push_back(links[0]);
        for (int i = zz(links) - 1; i; i--) ans.emplace_back(links[i - 1].y, links[i].x);
    }
    cout << ans.size() << '\n';
    for (auto& p : ans) cout << p.x + 1 << ' ' << p.y + 1 << '\n';
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    while (cin >> n >> m) solve(n, m);
    return 0;
}