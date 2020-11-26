#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
#define x first
#define y second
#define all(locId) locId.begin(), locId.end()
#define ms(locId) memset(locId, 0, sizeof(locId))
#define mss(locId) memset(locId, -1, sizeof(locId))
#define zz(locId) int(locId.size())

const int D = 125000;
const int P = 3;
const int N = 55;
vector<pii> adj[P][N];
int dst[P];
ll mincost[3][D + 5][N];
const ll inf = 1e12;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int p;
    cin >> p;
    for (int i = 0; i < p; i++) {
        int n, m;
        cin >> n >> m;
        for (int j = 0; j < n; j++) {
            ll w;
            cin >> w;
            adj[i][j].emplace_back(w, j);
        }
        while (m--) {
            int a, b;
            ll w;
            cin >> a >> b >> w;
            a--, b--;
            adj[i][a].emplace_back(w, b);
        }
        cin >> dst[i];
        dst[i]--;
    }

    for (int i = 0; i < P; i++)
        for (int j = 0; j < D; j++)
            for (int k = 0; k < N; k++) mincost[i][j][k] = inf;
    for (int i = 0; i < P; i++) mincost[i][0][0] = 0;

    ll minans = inf;
    for (int day = 0; day < D; day++) {
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < N; j++) {
                for (auto& e : adj[i][j]) {
                    int u = e.y;
                    ll w = e.x;
                    ll& c = mincost[i][day + 1][u];
                    c = min(c, mincost[i][day][j] + w);
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i < p; i++) ans += mincost[i][day][dst[i]];
        minans = min(minans, ans);
    }
    cout << minans << endl;
    return 0;
}