#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int inf = 1e9;

int d(const pii& a, const pii& b) {
    int dx = a.x - b.x, dy = a.y - b.y;
    return (int)ceil(sqrt(dx * dx + dy * dy));
}

int bfs(const vector<vector<piii>>& adj, int lim) {
    int n = adj.size() - 2;
    priority_queue<piii, vector<piii>, greater<piii>> q;
    q.push(piii(0, pii(n, 0)));  // cost, index, dist
    vector<vector<int>> mincost(n + 2, vector<int>(210, inf));
    mincost[n][0] = 0;

    while (!q.empty()) {
        auto v = q.top();
        q.pop();
        int curcost = v.x;
        int curindex = v.y.x;
        int curdist = v.y.y;

        //cout << "At " << curindex << " cost " << curcost << " dist " << curdist << endl;

        if (curindex == n + 1) return curcost;
        if (curcost > mincost[curindex][curdist]) continue;
        for (const auto& a : adj[curindex]) {
            int c = a.x;
            int d = a.y.y;
            int next = a.y.x;
            int newcost = c + curcost;
            int newdist = d + curdist;
            if (newdist > lim) continue;
            if (newcost >= mincost[next][newdist]) continue;
            mincost[next][newdist] = newcost;
            q.push({newcost, {next, newdist}});
        }
    }

    return -1;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    pii from, to;
    cin >> from.x >> from.y >> to.x >> to.y;

    int maxdist;
    cin >> maxdist;

    int c0;
    cin >> c0;
    int t;
    cin >> t;
    vector<int> tcost(t);
    for (auto& c : tcost) cin >> c;

    int n;
    cin >> n;
    vector<vector<int>> cost(n + 2, vector<int>(n + 2, inf));
    for (int i = 0; i < n; i++) {
        cost[n][i] = cost[i][n] = c0;
        cost[n + 1][i] = cost[i][n + 1] = c0;
    }
    cost[n][n + 1] = cost[n + 1][n] = c0;

    vector<vector<int>> dist(n + 2, vector<int>(n + 2, 0));
    vector<pii> locs;
    for (int i = 0; i < n; i++) {
        pii loc;
        cin >> loc.x >> loc.y;
        locs.push_back(loc);
        int m;
        cin >> m;
        while (m--) {
            int index, t;
            cin >> index;
            cin >> t;
            t--;
            cost[i][index] = min(cost[i][index], tcost[t]);
            cost[index][i] = min(cost[index][i], tcost[t]);
        }
    }

    locs.push_back(from);
    locs.push_back(to);
    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            dist[j][i] = dist[i][j] = d(locs[i], locs[j]);
        }
    }

    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            if (cost[i][j] == inf) continue;
            int c = cost[i][j] * dist[i][j];
            cost[i][j] = cost[j][i] = c;
        }
    }

    vector<vector<piii>> adj(n + 2);
    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            int c = cost[i][j];
            if (c == inf) continue;
            int d = dist[i][j];
            adj[i].push_back({c, {j, d}});
            adj[j].push_back({c, {i, d}});
        }
    }

    /*for (auto x : cost) {
        for (auto y : x) {
            cout << y << "\t";
        }
        cout << endl;
    }*/

    cout << bfs(adj, maxdist) << endl;

    return 0;
}