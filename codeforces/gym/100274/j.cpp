#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

vector<vector<int>> adj;
vector<int> dist;

int dfs(int v, int p) {
    for (int a : adj[v])
        if (a != p) {
            dist[a] = dist[v] + 1;
            dfs(a, v);
        }
}

int main() {
    fastio();
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        adj.assign(n, {});
        dist.assign(n, 0);
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0, -1);
        int farthest = 0;
        for (int i = 1; i < n; i++)
            if (dist[i] > dist[farthest]) farthest = i;
        dist.assign(n, 0);
        dfs(farthest, -1);
        int maxdist = farthest;
        for (int i = 0; i < n; i++)
            if (dist[i] > dist[maxdist]) maxdist = i;
        cout << (dist[maxdist] + 1) / 2 << endl;
    }
    return 0;
}