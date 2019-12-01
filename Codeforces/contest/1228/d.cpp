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

vector<int> v[3];
vector<int> g;
vector<unordered_set<int>> adj;
int n;

void foul() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int m;
    cin >> n >> m;
    g.assign(n, -1);
    adj.resize(n);

    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    for (auto& a : adj)
        if (a.empty()) foul();

    if (adj[0].empty()) foul();
    g[0] = 0, v[0].push_back(0);
    int a = *(adj[0].begin());
    g[a] = 1, v[1].push_back(a);

    for (int i = 1; i < n; i++) {
        if (i == a) continue;
        if (adj[0].count(i) && adj[a].count(i))
            g[i] = 2, v[2].push_back(i);
        else if (adj[a].count(i))
            g[i] = 0, v[0].push_back(i);
        else
            g[i] = 1, v[1].push_back(i);
    }
    if (v[2].empty()) foul();

    for (int i = 0; i < 3; i++) {
        ll s = 0;
        for (int j : v[i]) s += adj[j].size();
        ll me = v[i].size(), they = n - me;
        if (s != me * they) foul();
    }
    for (int i = 0; i < 3; i++) {
        for (int j : v[i]) {
            for (int e : adj[j])
                if (g[e] == g[j]) foul();
        }
    }

    for (int gp : g) cout << gp + 1 << ' ';
    cout << endl;
    return 0;
}