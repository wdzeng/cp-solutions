#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int N = 1000;
vector<pii> adj[N];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = n * (n - 1) / 2; i; i--) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        adj[a].emplace_back(w, b);
        adj[b].emplace_back(w, a);
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sort(all(adj[i]));
        for (int j = 1; j < adj[i].size(); j += 2) ans += adj[i][j].first;
    }
    cout << ans << endl;

    return 0;
}