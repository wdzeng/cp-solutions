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

struct g {
    int n, m;
    vector<vector<int>> adj;
    vector<int> dad;
    set<pii> others;
    vector<int> dep;

    g() {
        cin >> n >> m;
        adj.resize(n);
        while (m--) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            adj[a].push_back(b), adj[b].push_back(a);
        }
    }

    void dfs(int r) {
        stack<int> k;
        k.push(r);
        dad[r] = -1;
        dep[r] = 0;
        while (k.size()) {
            int v = k.top();
            k.pop();
            for (int a : adj[v]) {
                if (dad[a] != -2) {
                    if (a == dad[v]) continue;
                    others.emplace(min(a, v), max(a, v));
                    continue;
                }
                dad[a] = v;
                dep[a] = dep[v] + 1;
                k.push(a);
            }
        }
    }

    void solve() {
        dad.assign(n, -2);
        dep.resize(n);
        dfs(0);
        if (any_of(iter(dad), [](int i) { return i == -2; })) {
            cout << "n\n";
            return;
        }

        // for (auto& o : others) printf("%d %d\n", o.x, o.y);

        if (others.size() < 2) {
            cout << "n\n";
            return;
        }

        if (others.size() == 2) {
            auto a = *others.begin(), b = *prev(others.end());
            auto s0 = loop(a.y, a.x);
            auto s1 = loop(b.y, b.x);
            //   for(auto& p: s0) printf("(%d,%d) ", p.x, p.y); cout << endl;
            //   for(auto& p: s1) printf("(%d,%d) ", p.x, p.y); cout << endl;

            bool res = intersect(s0, s1);
            if (res)
                cout << "y: there are at least three cycles\n";
            else
                cout << "y\n";
            return;
        }

        cout << "y: there are at least three cycles\n";
    }

    set<pii> loop(int a, int b) {
        set<pii> ret;
        if (dep[a] > dep[b]) swap(a, b);
        while (dep[b] > dep[a]) {
            ret.emplace(dad[b], b);
            b = dad[b];
        }
        while (a != b) {
            ret.emplace(dad[a], a);
            ret.emplace(dad[b], b);
            a = dad[a];
            b = dad[b];
        }
        return ret;
    }

    bool intersect(set<pii>& a, set<pii>& b) {
        for (auto& p : a)
            if (b.count(p)) return 1;
        return 0;
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) g().solve();
    return 0;
}