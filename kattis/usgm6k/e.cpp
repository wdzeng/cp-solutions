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

const int N = 2e5 + 5;
int deg[N];
int src[N];
int dst[N];
int vis[N];

ll give[N];
ll own[N];

ll ans = 0;
ll v1[N];
ll v2[N];

void dfs(int v) {
    vis[v] = 1;
    ll added = max(0ll, give[v] - own[v]);
    ans += added;
    own[dst[v]] += give[v];
    if (!--deg[dst[v]]) dfs(dst[v]);
}

int main() {
    fastio();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dst[i] >> give[i];
        dst[i]--;
        deg[dst[i]]++;
    }
    for (int i = 0; i < n; i++)
        if (!deg[i] && !vis[i]) dfs(i);

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;

        int x = i;
        do {
            src[dst[x]] = x;
            vis[x] = 1;
            x = dst[x];
        } while (x != i);

        x = i;
        ll v2sum = 0;
        do {
            v1[x] = max(give[x] - own[x], 0ll);
            v2[x] = max(give[x] - own[x] - give[src[x]], 0ll);
            v2sum += v2[x];
            x = dst[x];
        } while (x != i);

        x = i;
        ll minn = 1e18;
        do {
            minn = min(minn, v1[x] + v2sum - v2[x]);
            x = dst[x];
        } while (x != i);
        // minn = max(0ll, minn);
        ans += minn;
    }
    cout << ans << endl;
    return 0;
}