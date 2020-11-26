#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

const int maxn = 2e5 + 10;
unordered_set<int> adj[maxn];
bool vis[maxn];

void dfs(int src) {
    vis[src] = 1;
    for (int e : adj[src]) {
        if (vis[e]) continue;
        dfs(e);
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> vv[26];
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        unordered_set<char> s(iter(str));
        for (char c : s) vv[c - 'a'].push_back(i);
    }

    for (auto& v : vv) {
        for (int i = 1; i < v.size(); i++) {
            adj[v[i]].insert(v[i - 1]);
            adj[v[i - 1]].insert(v[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i), ans++;
    }

    cout << ans << '\n';
    return 0;
}
