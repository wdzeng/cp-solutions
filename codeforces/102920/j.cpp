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
#define debug(a) cerr << #a << ": " << a << endl
#define ass(a) assert(a)
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#define ass(a)
#endif

const int N = 510 * 2;
namespace Two_Sat {
vector<int> a[N], b[N], stk;
int vis[N], res[N];
void dfs(int u, vector<int>* g, int sc) {
    vis[u] = 1, res[u] = sc;
    for (int v : g[u])
        if (!vis[v]) dfs(v, g, sc);
    if (g == a) stk.push_back(u);
}
// 先呼叫 imply 來設定約束，然後呼叫 scc 跑分析。
// var[x] 的真值對應 i = x * 2 ； var[x] 的假值對應 i = x * 2 + 1
// e.g. 若 var[3] 為真則 var[6] 必為假，則呼叫 imply(6, 13)
void imply(int u, int v) {  // if u then v
    a[u].push_back(v), b[v].push_back(u);
}
// 跑 two_sat ，回傳 true 表示有解。解答存於 Two_Sat::res
// e.g. 若 res[13] == 1 表 var[6] 必為假
// e.g. 若 res[0] == 1 且 res[1] == 1 ，表 var[0] 必為真且必為假，矛盾，無解。
int scc(int n /*變數實際數量的兩倍*/) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
        if (!vis[i]) dfs(i, a, -1);
    memset(vis, 0, sizeof(vis));
    int sc = 0;
    while (!stk.empty()) {
        if (!vis[stk.back()]) dfs(stk.back(), b, sc++);
        stk.pop_back();
    }
    for (int i = 0; i < n; i += 2) {
        if (res[i] == res[i + 1]) return 0;
        if (res[i] > res[i + 1])
            res[i] = 1, res[i + 1] = 0;
        else
            res[i] = 0, res[i + 1] = 1;
    }
    return 1;
}
}  // namespace Two_Sat

int g[505][505];

int main() {
    fastio();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    return 0;
}