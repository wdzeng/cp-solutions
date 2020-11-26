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
int n;
vector<ll> cost[3];
vector<int> adj[maxn];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (auto& v : cost) {
        for (int i = 0; i < n; i++) {
            ll c;
            cin >> c;
            v.push_back(c);
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (adj[a].size() > 1 || adj[b].size() > 1) {
            cout << -1 << endl;
            return 0;
        }
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int start;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            start = i;
            break;
        }
    }
    bool vis[n];
    ms(vis);
    vector<int> ls;
    while (1) {
        vis[start] = 1;
        ls.push_back(start);
        int x = adj[start][0];
        if (adj[start].size() == 1) {
            if (vis[x]) break;
            start = x;
            continue;
        }
        int y = adj[start][1];
        if (vis[x])
            start = y;
        else
            start = x;
    }

    vector<vector<int>> vv = {{0, 1, 2}, {0, 2, 1},
                              {1, 0, 2}, {1, 2, 0},
                              {2, 0, 1}, {2, 1, 0}};
    vector<ll> totals;
    for (auto& v : vv) {
        ll s = 0;
        for (int i = 0; i < n; i++) {
            s += cost[v[i % 3]][ls[i]];
        }
        totals.push_back(s);
    }
    int ians = min_element(iter(totals)) - totals.begin();
    auto ans = vv[ians];
    ll total = totals[ians];
    cout << total << endl;

    vector<int> output(n);
    for (int i = 0; i < n; i++) {
        output[ls[i]] = ans[i % 3] + 1;
    }
    for (int a : output) cout << a << ' ';
    cout << endl;
    return 0;
}
