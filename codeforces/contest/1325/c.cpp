#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int maxn = 1e5 + 10;
unordered_set<int> adj[maxn];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    map<pii, int> m, ans;

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a > b) swap(a, b);
        m[pii(a, b)] = i;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (adj[i].size() == 1)
            q.push(i);

    for (int i = 0; i < n - 1; i++) {
        int v = q.front();
        q.pop();
        assert(adj[v].size() == 1);
        int a = *(adj[v].begin());
        adj[v].erase(a);
        adj[a].erase(v);
        if (adj[a].size() == 1) q.push(a);
        if (a > v) swap(a, v);
        ans[{a, v}] = i;
    }

    vector<int> output(n - 1);
    assert(ans.size() == n - 1);
    for (auto& p : ans) {
        output[m[p.x]] = p.y;
    }

    for (auto i : output) cout << i << '\n';
    return 0;
}