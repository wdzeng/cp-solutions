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
const int K = 20;

int dep[N];
int anc[N][K];
int nc[N];
vector<int> g[N];

void ffa(int r, int fa) {
    nc[r] = 1;
    dep[r] = dep[fa] + 1;
    anc[r][0] = fa;
    for (int c : g[r]) {
        if (c != fa) {
            ffa(c, r);
            nc[r] += nc[c];
        }
    }
}

void init(int n) {
    for (int k = 1; k < K; k++)
        for (int i = 1; i <= n; i++) {
            anc[i][k] = anc[anc[i][k - 1]][k - 1];
        }
}

int flca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int k = 0; dep[a] - dep[b]; k++)
        if (((dep[a] - dep[b]) >> k) & 1) a = anc[a][k];
    if (a == b) return b;
    for (int k = K - 1; k >= 0; k--) {
        if (anc[a][k] != anc[b][k]) {
            a = anc[a][k];
            b = anc[b][k];
        }
    }
    return anc[a][0];
}

int main() {
    fastio();
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ffa(1, 0);
    init(n);
    assert(nc[1] == n);
    while (q--) {
        int a, b;
        cin >> a >> b;
        int lca = flca(a, b);
        int ca, cb;
        if (lca == a) {
            ca = n - nc[a], cb = nc[b] - 1;
        } else if (lca == b) {
            ca = nc[a] - 1, cb = n - nc[b];
        } else {
            ca = nc[a] - 1, cb = nc[b] - 1;
        }
        int dlcaa = abs(dep[a] - dep[lca]) + 1;
        int dlcab = abs(dep[b] - dep[lca]) + 1;
        int d = dlcaa + dlcab - 1;
        int rem = n -d - ca - cb;
        assert(dlcaa >= 0);
        assert(dlcab >= 0);
        assert(d >= 0);
        assert(ca >= 0);
        assert(cb >= 0);
        assert(rem >= 0);
        debug(ca);
        debug(cb);
        debug(d);
        debug(rem);
        ll ans = 1ll * d * (d-1) / 2 + d+ ca + cb + rem;
        assert(ans >= 1);
        cout << ans << endl;
    }
    return 0;
}