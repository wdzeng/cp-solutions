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

class OfflineTarjan {
   private:
    vector<int> par;
    vector<int> anc;
    vector<int> dep;
    vector<vector<pii>> qry;
    vector<int> ans;
    vector<int> rank;

    const int N;
    const vector<vector<int>>& edge;
    const int root;

    void merge(int a, int b) {
        a = parent(a), b = parent(b);
        if (rank[a] < rank[b]) swap(a, b);
        par[b] = a;
        cout << flush;
        if (rank[a] == rank[b]) rank[a]++;
    }

    void dfs(int u, int d) {
        anc[parent(u)] = u;
        dep[u] = d;

        for (int a : edge[u]) {
            if (dep[a] != -1) continue;
            dfs(a, d + 1);
            merge(a, u);
            anc[parent(u)] = u;
            cout << flush;
        }

        for (auto q : qry[u]) {
            if (dep[q.first] != -1) ans[q.second] = anc[parent(q.first)];
        }
    }

    int parent(int x) {
        if (par[x] == x) return x;
        return par[x] = parent(par[x]);
    }

    void solve(const vector<pii>& query) {
        dep.assign(N, -1);
        rank.assign(N, 0);
        par.resize(N);
        anc.resize(N);
        for (int i = 0; i < N; i++) anc[i] = par[i] = i;

        ans.resize(query.size());
        qry.resize(N);
        for (int i = 0; i < query.size(); i++) {
            auto& q = query[i];
            qry[q.first].emplace_back(q.second, i);
            qry[q.second].emplace_back(q.first, i);
        }

        dfs(root, 0);
    }

   public:
    // O(1)
    OfflineTarjan(const vector<vector<int>>& edge, int root) : N(edge.size()), edge(edge), root(root) {}

    // O(N+Q)
    vector<int> lca(const vector<pii>& query) {
        solve(query);
        return ans;
    }

    vector<int> dist(const vector<pii>& query) {
        solve(query);
        for (int i = 0; i < query.size(); i++) {
            auto& q = query[i];
            ans[i] = dep[q.first] + dep[q.second] - 2 * dep[ans[i]];
        }
        return ans;
    }
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

    OfflineTarjan tarjan(edge, 0);

    int q;
    cin >> q;
    vector<int> loc;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        loc.push_back(x * c + y);
    }

    vector<pii> qry;
    while (loc.size() > 1) {
        int l = loc.back();
        loc.pop_back();
        qry.emplace_back(l, loc.back());
    }

    ll sum = 0;
    auto ans = tarjan.dist(qry);
    for (int a : ans) sum += a;
    cout << sum << endl;
    return 0;
}