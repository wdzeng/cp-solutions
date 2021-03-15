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

struct C {
    double x, y, r;
    int ins(const C& c) const {
        double dx = x - c.x, dy = y - c.y;
        double d2 = dx * dx + dy * dy;
        double r2 = abs(r - c.r);
        r2 *= r2;
        double R2 = abs(r + c.r);
        R2 *= R2;
        return r2 <= d2 && d2 <= R2;
    }
};

int main() {
    fastio();
    int n;
    while (cin >> n) {
        if (n < 0) return 0;
        vector<vector<int>> adj(n);
        vector<C> Cs(n);
        for (auto& c : Cs) cin >> c.x >> c.y >> c.r;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (Cs[i].ins(Cs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n);
        int cnt = 0;
        auto dfs = [&](auto self, int v) -> void {
            vis[v] = 1;
            cnt++;
            for (int a : adj[v])
                if (!vis[a]) self(self, a);
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            cnt = 0;
            dfs(dfs, i);
            ans = max(ans, cnt);
        }
        if(ans==1) cout << "The largest component contains 1 ring." << endl;
        else cout << "The largest component contains " << ans << " rings." << endl;
    }
    return 0;
}