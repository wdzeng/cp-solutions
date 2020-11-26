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

const int M = 1e9 + 7;
const int N = 1e5 + 5;
ll dp[N][4];
int g[N];
vector<int> adj[N], ch[N];

void dfs(int v, int f) {
    for (int a : adj[v]) {
        if (a == f) continue;
        ch[v].push_back(a);
        dfs(a, v);
    }
}

void dfs1(int v) {
    if (!v) return;
    int a = ch[v][0], b = ch[v][1];
    dfs1(a), dfs1(b);
    if (g[v] == -1) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int r = !((i >> 1) & (j >> 1));
                int id = !((i & 1) & (j & 1));
                dp[v][r * 2 + id] += dp[a][i] * dp[b][j];
                dp[v][r * 2 + id] %= M;
            }
        }
    }  //
    else {
        int k = g[v];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int id = !((i & 1) & (j & 1));
                dp[v][k * 2 + id] += dp[a][i] * dp[b][j];
                dp[v][k * 2 + id] %= M;
            }
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a) adj[a].push_back(i), adj[i].push_back(a);
        if (b) adj[b].push_back(i), adj[i].push_back(b);
        g[i] = c;
    }

    dfs(1, -1);
    for (int i = 1; i <= n; i++)
        while (zz(ch[i]) < 2) ch[i].push_back(0);
    
    dp[0][0] = 1;
    dp[0][3] = 1;
    dfs1(1);
    
    cout << (dp[1][1] + dp[1][2]) % M << endl;
    return 0;
}