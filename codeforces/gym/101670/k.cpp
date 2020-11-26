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

// 點 u 為割點若且惟若滿足：
//   u 爲樹根且 u 有多於一個子樹。
//   u 不爲樹根且存在 (u,v) 爲樹枝邊使得 low[v] >= dfn[u]。
// 一條無向邊 (u,v) 是橋若且惟若 (u,v) 爲樹枝邊，且滿足 low[v] > dfn[u]。
// 0 base

const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> adj1[N];
int deg[N], rdeg[N];

int candtail[N];
int pathvis[N];
int findtail(int src) {
    pathvis[src] = 1;
    if (candtail[src]) return src;
    for (int a : adj1[src]) {
        if (!pathvis[a]) {
            int ret = findtail(a);
            if (ret) return ret;
        }
    }
    return 0;
}

namespace SCC {

int ins[N],dfn[N], low[N], belong[N];
int c;
int scc_cnt;
vector<int> stk;

void dfs(int u) {
    dfn[u] = low[u] = ++c, ins[u] = 1;
    stk.push_back(u);
    for (int v : adj[u]) {
        if (!dfn[v]) {  //樹枝子邊
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {  //非祖先邊
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        s++;
        while (1) {
            int v = stk.back();
            stk.pop_back();
            belong[v] = s;
            // cout << "vertex " << v << " belongs to scc " << s << endl;
            ins[v] = 0;
            if (v == u) break;
        }
    }
}

void findscc(int n) {
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) dfs(i);
}

void reset() {
    ms(dfn), ms(low), ms(belong), ms(ins);
    s = c = 0;
    stk.clear();
}

}  // namespace SCC

void reset() {
    SCC::reset();
    ms(deg), ms(rdeg), ms(candtail), ms(pathvis);
    for (auto& vec : adj) vec.clear();
    for (auto& vec : adj1) vec.clear();
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    while (cin >> n >> m) {
        reset();

        while (m--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }

        SCC::findscc(n);

        const int scccnt = SCC::s;
        assert(scccnt <= n);
        if (scccnt == 1) {
            cout << "0\n";
            continue;
        }

        vector<int> s2n(scccnt + 1);
        for (int i = 1; i <= n; i++) {
            s2n[SCC::belong[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            int bi = SCC::belong[i];
            for (int a : adj[i]) {
                int ba = SCC::belong[a];
                if (bi == ba) continue;
                adj1[bi].push_back(ba);
                deg[ba]++;
                rdeg[bi]++;
            }
        }
        for (auto& vec : adj1) sort(all(vec)), vec.erase(unique(all(vec)), vec.end());

        vector<int> heads;
        for (int i = 1; i <= scccnt; i++) {
            assert(deg[i] || rdeg[i]);
            if (deg[i] == 0) heads.push_back(i);
            if (rdeg[i] == 0) candtail[i] = 1;
        }
        vector<pii> mhts;
        vector<int> uh, ut;
        for (int h : heads) {
            int t = findtail(h);
            if (t) {
                mhts.emplace_back(h, t), candtail[t] = 0;
                // cout << h << " match " << t << endl;
            } else
                uh.push_back(h);
        }
        for (int i = 1; i <= scccnt; i++)
            if (candtail[i]) ut.push_back(i);
        int rhead = mhts.empty() ? uh[0] : mhts[0].x;
        int rtail = mhts.empty() ? ut[0] : mhts[0].y;

        vector<pii> ans;
        for (int i = 0; i < mhts.size(); i++) {
            int t = mhts[i].y;
            int h = mhts[(i + 1) % mhts.size()].x;
            ans.emplace_back(t, h);
        }
        if (uh.size() > ut.size()) {
            for (int i = 0; i < uh.size(); i++) {
                if (i < ut.size()) {
                    ans.emplace_back(ut[i], uh[i]);
                } else {
                    ans.emplace_back(rtail, uh[i]);
                }
            }
        } else {
            for (int i = 0; i < ut.size(); i++) {
                if (i < uh.size()) {
                    ans.emplace_back(ut[i], uh[i]);
                } else {
                    ans.emplace_back(ut[i], rhead);
                }
            }
        }
        cout << ans.size() << '\n';
        for (auto& p : ans) cout << s2n[p.x] << ' ' << s2n[p.y] << '\n';
    }
    return 0;
}
