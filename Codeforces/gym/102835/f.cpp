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

const int N = 2e5 + 5;
int n, m;
vector<int> adj[N];
int dpt[N][2];
int dpr[N][2];

void dfs(int v, int p) {
    dpt[v][1] = 1;
    for (int a : adj[v]) {
        if (a == p || a < n) continue;
        dfs(a, v);
        dpt[v][0] += dpt[a][1];
        dpt[v][1] += min(dpt[a][1], dpt[a][0]);
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) dfs(i, -1);
    memset(dpr, 0x3f3f3f3f, sizeof(dpr));
    int ans = 1e8;
    // install at node 0
    dpr[0][1] = dpt[0][1];
    for (int i = 1; i < n; i++) {
        dpr[i][0] = min(dpr[i][0], dpr[i - 1][1] + dpt[i][0]);
        dpr[i][1] = min(dpr[i][1], dpr[i - 1][1] + dpt[i][1]);
        dpr[i][1] = min(dpr[i][1], dpr[i - 1][0] + dpt[i][1]);
    }
    ans = min(ans, dpr[n - 1][0]);
    ans = min(ans, dpr[n - 1][1]);

    memset(dpr, 0x3f3f3f3f, sizeof(dpr));
    dpr[0][0] = dpt[0][0];
    // not install at node 0
    for (int i = 1; i < n; i++) {
        dpr[i][0] = min(dpr[i][0], dpr[i - 1][1] + dpt[i][0]);
        dpr[i][1] = min(dpr[i][1], dpr[i - 1][1] + dpt[i][1]);
        dpr[i][1] = min(dpr[i][1], dpr[i - 1][0] + dpt[i][1]);
    }
    // ans = min(ans, dpr[n - 1][0]);
    ans = min(ans, dpr[n - 1][1]);

    cout << ans << '\n';
    return 0;
}