#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int maxn = 2e5 + 10;
vector<int> adj[maxn], radj[maxn];
vector<int> dist(maxn, 2e5 + 100);

void bfs(int dst) {
    queue<int> q;
    unordered_set<int> vis;
    q.push(dst);
    dist[dst] = 0;

    while (q.size()) {
        int v = q.front();
        q.pop();
        if (vis.count(v)) continue;
        vis.insert(v);

        for (int a : radj[v]) {
            dist[a] = min(dist[a], dist[v] + 1);
            q.push(a);
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    int rn;
    cin >> rn;
    vector<int> route;
    while (rn--) {
        int a;
        cin >> a;
        route.push_back(a);
    }
    bfs(route.back());
    int minn = 0, maxx = 0;

    for (int i = 0; i < route.size() - 1; i++) {
        // cout << dist[route[i]] << ' ' << dist[route[i + 1]] << endl;
        if (dist[route[i]] != dist[route[i + 1]] + 1) {
            minn++, maxx++;
        } else {
            for (int a : adj[route[i]]) {
                if (a != route[i + 1] && dist[a] == dist[route[i]] - 1) {
                    // cout << a << endl;
                    maxx++;
                    break;
                }
            }
        }
    }

    cout << minn << ' ' << maxx << endl;
    return 0;
}