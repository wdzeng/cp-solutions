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
#define mp(e, ee) make_pair(e, ee)

/**
 * Support single element increment and range sum query.
 *
 * Time Complexity: O(QlogN)
 * Space Complexity: O(N)
 */
class BIT {
   private:
    int n;
    vector<ll> a;

    ll sum(int i) const {
        i++;
        ll r = 0;
        while (i > 0) r += a[i], i -= i & -i;
        return r;
    }

   public:
    // Constructs an binary indexed tree with all values initialized to 0, where n is size of array.
    BIT(int sz = 0) { init(sz); }
    // Increases element at index i by value v.
    void add(int i, ll v) {
        // i--;  // comment this line to 0-based
        i++;
        while (i <= n) a[i] += v, i += i & -i;
    }
    // Queries sum in [l, r].
    ll sum(int l, int r) const {
        // l--, r--;  // comment this line to 0-based
        return sum(r) - sum(l - 1);
    }

    void init(int sz) {
        n = sz;
        a.assign(n + 1, 0);
    }
};

struct pA {
    int n, mn, mx;
    vector<int> dad;
    vector<vector<int>> adj;
    vector<int> sz;
    vector<int> dep;
    ll ans = 0;
    BIT b;
    vector<int> tk;

    pA() {}

    void solve() {
        int l, r;
        cin >> n >> l >> r;
        mn = n - 1 - r, mx = n - 1 - l;
        dad.assign(n, 0);
        sz.assign(n, 0);
        dep.assign(n, 0);
        adj.assign(n, vector<int>());
        ans = 0;
        b.init(n * 2);

        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            adj[a].push_back(b), adj[b].push_back(a);
        }
        dfs(0, -1, 0);
        solve(0, 0);
        cout << ans << '\n';
    }

    int dfs(int v, int d, int dp) {
        dad[v] = d;
        dep[v] = dp;
        int szz = 0;
        for (int e : adj[v]) {
            if (e == d) continue;
            szz += dfs(e, v, dp + 1);
        }
        return sz[v] = szz + 1;
    }

    void solve(int v, bool keep) {
        if (v == -1) return;

        int h = -1;
        for (int e : adj[v]) {
            if (e == dad[v]) continue;
            if (h == -1 || sz[e] > sz[h]) h = e;
        }

        for (int e : adj[v]) {
            if (e == dad[v] || e == h) continue;
            solve(e, 0);
        }

        solve(h, 1);

        for (int e : adj[v]) {
            if (e == dad[v] || e == h) continue;
            stack<int> k;
            vector<int> lg;
            k.push(e);
            while (!k.empty()) {
                int u = k.top();
                k.pop();
                lg.push_back(u);
                for (int ee : adj[u]) {
                    if (ee == dad[u]) continue;
                    k.push(ee);
                }
            }
            for (int u : lg) {
                int l = mn - (dep[u] - dep[v]);
                int r = mx - (dep[u] - dep[v]);
                if (r < 1) continue;
                ans += b.sum(dep[v] + l, dep[v] + r);
            }
            for (int u : lg) {
                b.add(dep[u], 1);
                tk.push_back(dep[u]);
            }
        }

        ans += b.sum(dep[v] + mn, dep[v] + mx);
        b.add(dep[v], 1);
        tk.push_back(dep[v]);
        if (!keep) {
            for (int d : tk) b.add(d, -1);
            tk.clear();
        }
    }
};

int main() {
    freopen("awesome.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    pA a;
    while (t--) a.solve();
    return 0;
}