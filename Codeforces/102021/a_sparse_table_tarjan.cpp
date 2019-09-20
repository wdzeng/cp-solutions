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

// RmqTarjan (eclectic and somehow slower)
// Time Complexity: O(N+QlogN)
// Space complexity: O(NlogN)
class SparseTableTarjan {
   private:
    const int maxlg;
    const int n;
    vector<vector<int>> anc;
    vector<int> dep;

    void dfs(int u, const vector<vector<int>>& edge, int d) {
        dep[u] = d;
        for (int i = 1; i < maxlg; i++)
            if (anc[u][i - 1] < 0)
                anc[u][i] = -1;
            else
                anc[u][i] = anc[anc[u][i - 1]][i - 1];
        for (int a : edge[u]) {
            if (dep[a] != -1) continue;
            anc[a][0] = u;
            dfs(a, edge, d + 1);
        }
    }

   public:
    SparseTableTarjan(const vector<vector<int>>& edge, int root) : n(edge.size()), maxlg(__lg(n)) {
        anc.assign(n, vector<int>(maxlg));
        dep.assign(n, -1);
        dfs(root, edge, 0);
    }

    int lca(int a, int b) {
        if (dep[a] > dep[b]) swap(a, b);
        for (int k = 0; k < maxlg; k++)
            if ((dep[b] - dep[a]) >> k & 1) b = anc[b][k];

        if (a == b) return a;
        for (int k = maxlg - 1; k >= 0; k--)
            if (anc[a][k] != anc[b][k]) a = anc[a][k], b = anc[b][k];
        return anc[a][0];
    }

    int dist(int a, int b) { return dep[a] + dep[b] - 2 * dep[lca(a, b)]; }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int r, c;
    cin >> r >> c;
    int n = r * c;
    vector<vector<int>> edge(n);

    string s;
    getline(cin, s);
    for (int i = -1; i < r; i++) {
        getline(cin, s);
        if (i == -1) continue;
        for (int j = 0, k = 1; j < c; k += 2, j++) {
            int v = i * c + j;
            if (s[k] != '_') {
                int a = (i + 1) * c + j;
                edge[v].push_back(a);
                edge[a].push_back(v);
            }
            if (s[k + 1] != '|') {
                int a = i * c + (j + 1);
                edge[v].push_back(a);
                edge[a].push_back(v);
            }
        }
    }

    SparseTableTarjan tarjan(edge, 0);

    int q;
    cin >> q;
    vector<int> loc;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        loc.push_back(x * c + y);
    }

    ll sum = 0;
    while (loc.size() > 1) {
        int l = loc.back();
        loc.pop_back();
        sum += tarjan.dist(l, loc.back());
    }

    cout << sum << endl;
    return 0;
}