#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

/** 威達的 LCA ，時間普通 O(Q*log(N)) ，記憶體需求也普通
 *  O(N*log(N)) 。支援非離線。**/
class SparseTableTarjan {
   private:
    int maxlg;
    vector<vector<int>> anc;
    vector<int> dep;

    void dfs(int u, vector<vector<int>>& edge, int d) {
        dep[u] = d;
        for (int i = 1; i < maxlg; i++)
            if (anc[u][i - 1] == -1)
                break;
            else
                anc[u][i] = anc[anc[u][i - 1]][i - 1];
        for (int a : edge[u]) {
            if (dep[a] != -1) continue;
            anc[a][0] = u;
            dfs(a, edge, d + 1);
        }
    }

   public:
    SparseTableTarjan(vector<vector<int>>& edge, int root) {
        int n = edge.size();
        maxlg = ceil(log2(n));
        anc.assign(n, vector<int>(maxlg, -1));
        dep.assign(n, -1);
        dfs(root, edge, 0);
    }
    int lca(int a, int b) {
        if (dep[a] > dep[b]) swap(a, b);
        for (int k = 0; dep[b] - dep[a]; k++)
            if (((dep[b] - dep[a]) >> k) & 1) b = anc[b][k];

        if (a == b) return a;
        for (int k = maxlg - 1; k >= 0; k--)
            if (anc[a][k] != anc[b][k])
                a = anc[a][k], b = anc[b][k];
        return anc[a][0];
    }
    int dist(int a, int b) {
        return dep[a] + dep[b] - 2 * dep[lca(a, b)];
    }
};

const int N = 2e5 + 10;
vector<vector<int>> edge(N);
int root = 0;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    SparseTableTarjan t(edge, root);

    int T;
    cin >> T;
    while (T--) {
        int r, b;
        cin >> r >> b;
        vector<int> rr, bb;
        while (r--) {
            int v;
            cin >> v;
            v--;
            rr.push_back(v);
        }
        while (b--) {
            int v;
            cin >> v;
            v--;
            bb.push_back(v);
        }
        int rrlca = t.lca(rr[0], rr[0]);
        int bblca = t.lca(bb[0], bb[0]);
        for (int i = 1; i < rr.size(); i++) rrlca = t.lca(rrlca, rr[i]);
        for (int i = 1; i < bb.size(); i++) bblca = t.lca(bblca, bb[i]);
        int aalca = t.lca(rrlca, bblca);
        if (aalca != rrlca and aalca != bblca) {
            cout << "YES\n";
            continue;
        }
        bool ok = 1;
        if (aalca == rrlca) {
            for (auto v : rr)
                if (t.lca(bblca, v) == bblca) {
                    ok = 0;
                    break;
                }
        }
        else {
            for (auto v : bb)
                if (t.lca(rrlca, v) == rrlca) {
                    ok = 0;
                    break;
                }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}