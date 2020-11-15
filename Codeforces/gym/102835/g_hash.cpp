#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

const int N = 1e6 + 5;
const ll M = 1e9 + 9;
const ll M2 = 1e9 + 7;
vector<ll> randX;

pii rollhash(const vector<ll>& hs) {
    const ll X1 = randX[hs.size()], X2 = randX[hs.size() + 1];
    ll x1 = 1;
    ll x2 = 1;
    pii ret;
    pii hash;
    for (ll h : hs) {
        hash = {(hash.x * X1 + h) % M, (hash.y * X2 + h) % M2};
        x1 = x1 * X1 % M;
        x2 = x2 * X2 % M2;
    }
    for (ll h : hs) {
        hash = {(hash.x * X1 + h) % M, (hash.y * X2 + h) % M2};
        hash = {((hash.x - x1 * h) % M + M) % M, ((hash.y - x2 * h) % M2 + M2) % M2};
        ret = max(ret, hash);
    }
    return ret;
}

void solve() {
    int D;
    cin >> D;
    vector<vector<vector<int>>> adj(D);
    for (int i = 0; i < D; i++) {
        int k;
        cin >> k;
        adj[i].resize(k);
        while (k--) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            adj[i][a].push_back(b);
            adj[i][b].push_back(a);
        }
    }

    set<pii> ans;
    for (int i = 0; i < D; i++) {
        vector<int> stk;
        int k = adj[i].size();
        vector<int> vis(k);
        vector<int> ring;
        auto dfs = [&](auto self, int v, int fa) -> int {
            vis[v] = 1;
            stk.push_back(v);
            for (int a : adj[i][v]) {
                if (a == fa) continue;
                if (vis[a]) {
                    while (1) {
                        int v = stk.back();
                        ring.push_back(v);
                        if (v == a) return 1;
                        stk.pop_back();
                    }
                }
                if (self(self, a, v)) return 1;
            }
            stk.pop_back();
            return 0;
        };
        dfs(dfs, 0, -1);
        vector<int> isring(k);
        for (int r : ring) isring[r] = 1;

        auto ttok = [&](auto self, int v, int fa, int dep) -> ll {
            ll ret = randX[dep];
            vector<ll> ch;
            for (int a : adj[i][v]) {
                if (isring[a] || a == fa) continue;
                ch.push_back(self(self, a, v, dep + 1));
            }
            sort(all(ch));
            for (ll h : ch) ret = (ret * randX[dep] + h + randX[dep]) % M;
            return ret;
        };
        vector<ll> thash;
        for (int r : ring) thash.push_back(ttok(ttok, r, -1, 0));

        auto h = rollhash(thash);
        reverse(all(thash));
        h = max(h, rollhash(thash));
        ans.insert(h);
    }

    cout << ans.size() << '\n';
}

int main() {
    srand(time(0));
    cin.tie(0), ios::sync_with_stdio(0);
    for (int i = 0; i < N; i++) randX.push_back(rand() % M);
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}