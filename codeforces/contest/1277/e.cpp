#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int RING = 100, DEAD = 101;

class Solve {
   private:
    int n;
    vector<vector<int>> adj;

    void dfs(int s, int t, int u, vector<int>& flag) {
        vector<int> k = {s};
        unordered_set<int> vis = {s, t};

        while (k.size()) {
            int v = k.back();
            k.pop_back();

            for (int a : adj[v]) {
                if (vis.count(a)) continue;
                k.push_back(a);
                vis.insert(a);
            }
        }

        if (vis.count(u)) {
            for (int v : vis)
                if (v != t) flag[v] = RING;
        } else {
            for (int v : vis)
                if (v != t) flag[v] = DEAD;
        }
    }

   public:
    void solve() {
        int m, src, dst;
        cin >> n >> m >> src >> dst;
        src--, dst--;
        adj.assign(n, {});
        while (m--) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> he(n), she(n);
        for (int a : adj[src])
            if (he[a] == 0) dfs(a, src, dst, he);
        for (int a : adj[dst])
            if (she[a] == 0) dfs(a, dst, src, she);

        ll lonehe = 0, loneshe = 0;
        // cout << ":";
        for (int i = 0; i < n; i++)
            if (he[i] == DEAD) /*cout << i << ' ',*/
                lonehe++;
        /* cout << endl
             << ":";*/
        for (int i = 0; i < n; i++)
            if (she[i] == DEAD) /*cout << i << ' ',*/
                loneshe++;
        /* cout << endl;
        cout << lonehe << ' ' << loneshe << endl;*/
        cout << lonehe * loneshe << endl;
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    Solve s;
    while (t--) s.solve();
    return 0;
}