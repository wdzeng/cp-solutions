#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

unordered_map<string, int> M;

int id(string& s) {
    if (!M.count(s)) return M[s] = M.size();
    return M[s];
}

void solve() {
    M.clear();
    int m;
    cin >> m;
    vector<int> adj[3010];
    while (m--) {
        string a, b;
        cin >> a >> b;
        adj[id(a)].push_back(id(b));
        adj[id(b)].push_back(id(a));
    }
    int n = M.size();
    int ans = 0;
    for (int i = 0; i < n and ans * 20 <= n; i++) {
        vector<int> len(n, 1e9);
        queue<int> q;
        q.push(i);
        len[i] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int a : adj[u]) {
                if (len[u] + 1 >= len[a]) continue;
                len[a] = len[u] + 1;
                q.push(a);
            }
        }
        int maxlen = *max_element(all(len));
        if (maxlen > 6) ans++;
    }
    cout << (ans * 20 <= n ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}