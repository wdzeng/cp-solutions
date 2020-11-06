#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

const int N = 1005;
vector<int> adj[N];
int src, dst;

int vis[N];
int dfs(int v) {
    vis[v] = 1;
    if (v == dst) return 1;
    for (int a : adj[v])
        if (!vis[a])
            if (dfs(a)) return 1;
    return 0;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    cin >> src >> dst;

    vector<pair<pii, pii>> E;
    set<int> segs = {1, k + 1};
    while (m--) {
        int a, b, l, r;
        cin >> a >> b >> l >> r;
        segs.insert(l);
        segs.insert(r + 1);
        E.push_back({{a, b}, {l, r + 1}});
    }
    vector<int> vec(all(segs));

    int ans = 0;
    for (int i = 1; i < zz(vec); i++) {
        for (auto& v : adj) v.clear();
        int l = vec[i - 1], r = vec[i];
        // cout << "CHECK " << l << ' ' << r << endl;
        for (auto& e : E) {
            int a, b, el, er;
            tie(el, er) = e.y;
            tie(a, b) = e.x;
            if (l >= el && r <= er) {
                adj[a].push_back(b);
                // cout << "EDGE " << a << ' ' << b << endl;
            }
        }
        ms(vis);
        if (dfs(src)) ans += r - l;
    }
    cout << ans << endl;

    return 0;
}