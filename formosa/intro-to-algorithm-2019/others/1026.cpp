#include <iostream>
#include <vector>
using namespace std;

const long long INFINITY = 1e18;
vector<pair<long long, int>> adj[500];
int n;

vector<long long> dijk(int s) {
    vector<long long> min_cost(n, INFINITY);
    vector<bool> is_visited(n, false);
    min_cost[s] = 0;

    while (true) {
        int v = -1;
        long long minn = INFINITY;
        for (int i = 0; i < n; i++) {
            if (!is_visited[i]) {
                if (v == -1 || min_cost[i] < minn) {
                    v = i;
                    minn = min_cost[i];
                }
            }
        }
        if (v == -1) break;

        for (auto& a : adj[v]) {
            int u = a.second;
            long long cc = a.first;
            cc = max(min_cost[v], cc);
            min_cost[u] = min(min_cost[u], cc);
        }
        is_visited[v] = true;
    }

    return min_cost;
}

int main() {
    int m, q;
    cin >> n >> m >> q;

    int a, b, cost;
    while (m--) {
        cin >> a >> b >> cost;
        adj[a].push_back(pair<long long, int>(cost, b));
    }

    vector<vector<long long>> table;
    for (int i = 0; i < n; i++) {
        table.push_back(dijk(i));
    }

    int s, d;
    while (q--) {
        cin >> s >> d;
        long long ans = max(table[s][d], table[d][s]);
        if (ans == INFINITY) ans = -1;
        cout << ans << '\n';
    }
}
