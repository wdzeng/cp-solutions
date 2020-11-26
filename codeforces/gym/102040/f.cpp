
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

const int N = 10001;
const int K = __lg(N) + 1;

vector<int> adj[N];

namespace lca {

int fa[N][K], dep[N];

void dfs(int v, int p) {
    dep[v] = dep[p] + 1;
    fa[v][0] = p;
    for (int a : adj[v])
        if (a != p) dfs(a, v);
}

inline void build(int n) {
    for (int i = 0; i <= n; i++) dep[i] = 0;
    dfs(1, 0);

    for (int k = 1; k < K; k++)
        for (int i = 1; i <= n; i++) {
            fa[i][k] = fa[fa[i][k - 1]][k - 1];
        }
}

inline int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    int diff = dep[a] - dep[b];
    while (diff) {
        int d = diff & -diff;
        a = fa[a][__lg(d)];
        diff -= d;
    }
    if (a == b) return a;
    for (int i = K - 1; ~i; i--)
        if (fa[a][i] != fa[b][i]) a = fa[a][i], b = fa[b][i];
    return fa[a][0];
}

}  // namespace lca

int dp[N];
void dfs(int v, int p) {
    for (int a : adj[v])
        if (a != p) dfs(a, v), dp[v] += dp[a];
}

inline void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    lca::build(n);
    int q;
    cin >> q;
    while (q--) {
        int T;
        cin >> T;
        for (int t = 0; t < T; t++) {
            int a, b;
            cin >> a >> b;
            if (lca::dep[a] < lca::dep[b]) swap(a, b);
            int p = lca::lca(a, b);
            if (p == b) {
                dp[a]++;
                dp[lca::fa[p][0]]--;
            } else {
                dp[a]++;
                dp[b]++;
                dp[p]--;
                dp[lca::fa[p][0]]--;
            }
        }

        dfs(1, 0);
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += dp[i] == T;
        cout << ans << '\n';

        for (int i = 0; i <= n; i++) dp[i] = 0;
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}