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

void solve() {
    int n, r;
    cin >> n >> r;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    int many = 0;
    while (r--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        deg[b]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!deg[i]) {
            q.push(i);
        }
    if (q.size() > 1) many = 1;
    vector<int> ans;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        int f = 0;
        for (int a : adj[u]) {
            deg[a]--;
            if (deg[a] == 0) f++;
            if (deg[a] == 0) q.push(a);
        }
        if (f > 1) many = 1;
    }
    if (ans.size() < n) {
        cout << "recheck hints" << endl;
        return;
    }
    if (many) {
        cout << "missing hints" << endl;
        return;
    }
    for (int a : ans) cout << a + 1 << ' ';
    cout << endl;
}

int main() {
    fastio();
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}