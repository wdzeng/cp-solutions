#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

const int N = 4e5 + 5;
int cost[N];
vector<int> adj[N];
int deg[N];
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
        int q;
        cin >> q;
        while (q--) {
            int a;
            cin >> a;
            a--;
            adj[i].push_back(a);
            deg[a]++;
        }
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) pq.emplace(cost[i], i);
    }
    int ans = 0;
    int order = n - 1;
    while (pq.size()) {
        int u = pq.top().y;
        ans = max(ans, pq.top().x + order);
        pq.pop();
        for (int a : adj[u]) {
            if (--deg[a] == 0) pq.emplace(cost[a], a);
        }
        order--;
    }
    cout << ans << endl;
    return 0;
}