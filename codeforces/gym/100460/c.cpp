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

const int maxn = 1e5 + 10;
vector<pii> adj[maxn];

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int n, w;
    cin >> n >> w;
    while (w--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(c, b);
        adj[b].emplace_back(c, a);
    }

    vector<int> dp1(maxn, 2e9), dp2(maxn, 2e9);
    priority_queue<pii> q;
    q.emplace(0, 1);

    while (q.size()) {
        auto a = q.top();
        q.pop();
        int c = a.x;
        int v = a.y;
        cout << v << endl;

        if (c < dp2[v])
            dp1[v] = dp2[v], dp2[v] = c;
        else if (c < dp1[v])
            dp1[v] = c;
        else
            continue;
        if (v == n) continue;

        for (auto u : adj[v]) {
            int cost = u.x;
            int dest = u.y;
            cout << cost << ' ' << dest << endl;
            if (cost >= dp2[dest]) continue;
            q.emplace(cost, dest);
        }
    }
    cout << dp2[n] << ' ' << dp1[n] << endl;
    return 0;
}
