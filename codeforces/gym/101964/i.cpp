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

const int N = 105;
unordered_set<int> adj[N];
int deg[N];
ll dp[N];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        adj[a].insert(b);
        deg[b]++;
    }

    vector<int> p;
    int vis[N] = {0};
    for (int t = 0; t < n; t++) {
        int i = -1;
        for (i = 1; i <= n; i++) {
            if (!deg[i] && !vis[i]) {
                break;
            }
        }
        assert(~i);
        p.push_back(i);
        vis[i] = 1;
        for (int a : adj[i]) {
            if (!vis[a]) deg[a]--;
        }
    }

    int maxx = 500;
    for (int i = 0; i < n; i++) {
        if (p[i] < maxx) {
            maxx = p[i];
            dp[i] = 1;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int lim = 500;
        for (int j = i + 1; j < n; j++) {
            if (p[j] > p[i] && p[j] < lim) {
                lim = p[j];
                dp[j] += dp[i];
            }
        }
        if (lim == 500) ans += dp[i];
    }

    cout << ans << endl;

    return 0;
}