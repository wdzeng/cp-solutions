#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int N = 2e5 + 10;
vector<int> adj[N];
int col[N];
int vis[N];
vector<int> ans;

int dfs(int s) {
    vis[s] = 1;
    int ret = 0;
    for (int a : adj[s]) {
        if (vis[a]) continue;
        ret |= dfs(a);
    }
    if (ret) ans.push_back(s);
    return col[s] ? 1 : ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    while (k--) {
        int a;
        cin >> a;
        col[a] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int root;
    for (int i = 1; i <= n; i++)
        if (!col[i]) {
            root = i;
            break;
        }

    dfs(root);

    cout << ans.size() << endl;
    for (int a : ans) cout << a << ' ';
    cout << endl;

    return 0;
}