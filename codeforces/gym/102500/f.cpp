#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int N = 2e5 + 5;
vector<int> adj[N];
unordered_map<int, vector<int>> madj;

typedef pair<pii, int> piii;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int a;
            cin >> a;
            adj[i].push_back(a);
            madj[a].push_back(i);
        }
    }

    vector<piii> ans;
    vector<int> vis(n);
    vector<int> k = {0};
    vis[0] = 1;
    unordered_set<int> mvis;
    while (!k.empty()) {
        int v = k.back();
        k.pop_back();
        for (int a : adj[v]) {
            if (mvis.count(a)) continue;
            mvis.insert(a);
            for (int b : madj[a]) {
                if (vis[b]) continue;
                ans.push_back({{v, b}, a});
                vis[b] = 1;
                k.push_back(b);
            }
        }
    }

    if (ans.size() != n - 1) {
        cout << "impossible\n";
        return 0;
    }

    for (auto& p : ans) {
        cout << p.x.x + 1 << ' ' << p.x.y + 1 << ' ' << p.y << '\n';
    }

    return 0;
}