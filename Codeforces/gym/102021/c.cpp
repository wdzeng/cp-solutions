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

int n;
int vis[1002];
vector<vector<pii>> e;

int bfs(int v) {
    if (vis[v] != -1) return vis[v];
    int mx = 0;
    for(auto adj: e[v]) {
        mx = max(mx, bfs(adj.x) + adj.y);
    }
    return vis[v] = mx;
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int m;
    cin >> n >> m;
    mss(vis);
    e.resize(n);
    
    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--, b--;
        e[a].emplace_back(b, l);
    }

    for (int i = 0; i < n; i++) {
        bfs(i);
    }

    cout << *max_element(vis, vis+n) << endl;
    return 0;
}