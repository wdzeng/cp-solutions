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

const int maxn = 1e5 + 10;
int N, R, C;
vector<pii> adj[maxn];
const ll inf = 1e18;
bool vis[maxn];

ll minpath(int src, int n) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.emplace(0, src);
    ll ret = 0;
    int nvis = 0;
    while (q.size()) {
        ll d = q.top().first;
        int v = q.top().second;
        q.pop();
        if (vis[v]) continue;
        vis[v] = 1;
        ret += d;
        for (auto& e : adj[v])
            if (!vis[e.second]) q.push(e);
    }
    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> N >> R >> C;

    while (R--) {
        int a, b, w;
        cin >> a >> b >> w;
        if (w >= C) continue;
        adj[a].emplace_back(w, b);
        adj[b].emplace_back(w, a);
    }

    ll ans = 0;
    int p = 0;
    for (int i = 0; i < N; i++) {
        if (!vis[i]) ans += minpath(i, N), p++;
    }
    cout << ans + (p - 1) * C << '\n';
    return 0;
}
