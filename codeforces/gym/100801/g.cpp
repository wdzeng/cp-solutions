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
#define mss(a) memset(a, 1, sizeof(a))
#define mp(e, f) make_pair(e, f)

int main() {
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<unordered_set<int>> edge(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (edge[x].count(y)) continue;
        edge[x].insert(y);
        deg[y]++;
    }

    priority_queue<int> added;
    priority_queue<int, vector<int>, greater<int>> deg0;
    vector<int> newgraph;
    vector<pii> newedge;
    for (int i = 0; i < n; i++)
        if (deg[i] == 0) deg0.push(i);

    auto remove_vertex = [&](int v) {
        for (int e : edge[v])
            if (--deg[e] == 0) deg0.push(e);
    };

    for (int t = 0; t < n; t++) {
        while (k > 0 && deg0.size() > 1) {
            added.push(deg0.top());
            deg0.pop();
            k--;
        }

        if (deg0.empty()) {
            int removed = added.top();
            added.pop();
            newedge.emplace_back(newgraph.back(), removed);
            newgraph.push_back(removed);
            remove_vertex(removed);
            continue;
        }

        if (added.empty() || added.top() < deg0.top() || k == 0) {
            int removed = deg0.top();
            deg0.pop();
            newgraph.push_back(removed);
            remove_vertex(removed);
            continue;
        }

        int removed = added.top();
        added.pop();
        newedge.emplace_back(newgraph.back(), removed);
        newgraph.push_back(removed);
        added.push(deg0.top());
        deg0.pop();
        k--;
        remove_vertex(removed);
    }

    for (int v : newgraph) cout << v + 1 << ' ';
    cout << '\n';
    cout << newedge.size() << '\n';
    for (pii& p : newedge) cout << p.x + 1 << ' ' << p.y + 1 << '\n';
    return 0;
}