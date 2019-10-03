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

const int maxn = 1e5 + 5;
vector<int> edge[maxn];

int main() {
    int n, root;
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> root;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y), edge[y].push_back(x);
    }

    bool vis[n];
    ms(vis);
    vis[root] = 1;
    vector<int> leaves;
    for (int e : edge[root]) {
        vector<int> g;
        stack<int> k;
        k.push(e);
        vis[e] = 1;
        while (!k.empty()) {
            int v = k.top();
            k.pop();
            bool leaf = true;
            for (int e : edge[v]) {
                if (vis[e]) continue;
                vis[e] = 1;
                k.push(e);
                leaf = false;
            }
            if (leaf) {
                leaves.push_back(v);
            }
        }
    }

    vector<pii> ans;
    if (edge[root].size() == 1) {
        ans.emplace_back(leaves.back(), root);
        leaves.pop_back();
    }
    int r = leaves.size() / 2;
    for (int i = 0; i + r < leaves.size(); i++) {
        ans.emplace_back(leaves[i], leaves[i + r]);
    }
    printf("%d\n", (int)ans.size());
    for (auto& a : ans) printf("%d %d\n", a.x, a.y);
    return 0;
}