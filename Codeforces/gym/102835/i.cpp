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

const int N = 1002;
vector<int> adj[N];

// v 是 cut vertex 若且惟若：
//     v 有大於一個子節點 | v 是 root
//     存在一個 v 的子節點 u 使得 low[u] >= dfn[v]
// (u, v) 是 bridge 若且惟若 u 是 v 的子節點且 low[u] > dfn[v]
// 1-based only
namespace tarjan {

int dfn[N], low[N], fa[N];
vector<int> ch[N];
int cnt = 0;
int bcc[N], b;    //  找 bcc
vector<int> stk;  // 找 bcc

void dfs(int u, int p) {
    dfn[u] = low[u] = ++cnt;
    stk.push_back(u);  // 找 bcc
    for (int v : adj[u]) {
        if (v == p) continue;
        if (dfn[v])
            low[u] = min(low[u], dfn[v]);
        else {  // dfs 子節點
            fa[v] = u;
            ch[u].push_back(v);
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
    }

    // 找 BCC
    if (low[u] == dfn[u]) {
        b++;
        while (1) {
            int v = stk.back();
            stk.pop_back();
            bcc[v] = b;
            if (v == u) break;
        }
    }
}

}  // namespace tarjan

void reset() {
    for (auto& vec : adj) vec.clear();
    for (auto& vec : tarjan::ch) vec.clear();
    tarjan::stk.clear();
    tarjan::b = tarjan::cnt = 0;
    ms(tarjan::dfn);
    ms(tarjan::low);
    ms(tarjan::fa);
    ms(tarjan::bcc);
}

void solve() {
    reset();

    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b), adj[b].push_back(a);
    }

    tarjan::dfs(1, 0);
    int ans1 = tarjan::ch[1].size() > 1;
    for (int i = 2; i <= n; i++) {
        for (int c : tarjan::ch[i])
            if (tarjan::low[c] >= tarjan::dfn[i]) {
                ans1++;
                break;
            }
    }
    int ans2 = 0;
    for (int i = 1; i <= n; i++) {
        for (int c : tarjan::ch[i])
            if (tarjan::low[c] > tarjan::dfn[i]) {
                ans2++;
            }
    }
    int ans3 = ans2, ans4 = 1;
    vector<int> bccg[N];
    for (int i = 1; i <= n; i++) {
        int bccid = tarjan::bcc[i];
        bccg[bccid].push_back(i);
    }
    for (auto& bccs : bccg) {
        int e = 0;
        for (int v : bccs) {
            for (int u : adj[v]) {
                if (v > u) continue;
                if (binary_search(all(bccs), u)) e++;
            }
        }
        ans4 = max(ans4, e);
        if (bccs.size() > 2) ans3++;
    }
    int g = __gcd(ans3, ans4);
    ans3 /= g, ans4 /= g;
    cout << ans1 << ' ' << ans2 << ' ' << ans3 << ' ' << ans4 << '\n';
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}