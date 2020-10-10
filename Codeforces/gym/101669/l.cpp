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

const int N = 1e5 + 10;
const int K = 20;
vector<int> adj[N];

namespace lca {

int dep[N];
int dp[N][K];
void clear() {
    ms(dp);
    ms(dep);
}
void dfs(int v, int p, int d) {
    dp[v][0] = p;
    dep[v] = d;
    for (int a : adj[v])
        if (a != p) dfs(a, v, d + 1);
}
void build(int r) {
    clear();
    dfs(r, 0, 0);
    for (int k = 1; k < K; k++) {
        for (int i = 0; i < N; i++) {
            dp[i][k] = dp[dp[i][k - 1]][k - 1];
        }
    }
}
int get(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    while (dep[a] > dep[b]) {
        int dif = dep[a] - dep[b];
        a = dp[a][__lg(dif & -dif)];
    }
    if (a == b) return a;
    for (int k = K - 1; k >= 0; k--)
        if (dp[a][k] != dp[b][k]) a = dp[a][k], b = dp[b][k];
    return dp[a][0];
}

}  // namespace lca

int w[N];
int mincut = 100;
int ans;
void solve(int v, int p) {
    for (int a : adj[v]) {
        if (a != p) {
            solve(a, v);
            w[v] += w[a];
        }
    }
    if (v == 1) return;
    if (w[v] < mincut) {
        mincut = w[v], ans = 0;
        // cout << "Mincut at " << v << ", " << p << " [" << w[v] + 1 << "]" << endl;
    }
    if (w[v] == mincut) {
        ans++;
        // cout << "Find ans at " << v << ", " << p << endl;
    }
}

void solve(const vector<pii>& A, const vector<pii>& B) {
    ms(w);
    for (auto& a : adj) a.clear();
    for (auto& e : A) adj[e.x].push_back(e.y), adj[e.y].push_back(e.x);
    lca::build(1);
    for (auto& e : B) w[e.x]++, w[e.y]++, w[lca::get(e.x, e.y)] -= 2;
    solve(1, 0);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pii> A, B;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        A.emplace_back(a, b);
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        B.emplace_back(a, b);
    }
    solve(A, B);
    // cout << "---" << endl;
    solve(B, A);
    cout << mincut + 1 << ' ' << (mincut == 1 ? (ans / 2) : ans) << endl;
    return 0;
}