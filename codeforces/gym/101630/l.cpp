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

const int N = 1e5 + 5;
const int K = 20;
vector<int> adj[N];

int chid[N], dfn[N], dep[N], son[N], sz[N], head[N];
int fa[N][K];

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    while (dep[a] > dep[b]) {
        int up = __lg(dep[a] - dep[b]);
        a = fa[a][up];
    }
    if (a == b) return a;
    for (int up = K - 1; ~up; up--) {
        if (fa[a][up] != fa[b][up]) a = fa[a][up], b = fa[b][up];
    }
    return fa[a][0];
}

void buildlca(int n) {
    for (int i = 1; i < K; i++) {
        for (int v = 1; v <= n; v++) {
            fa[v][i] = fa[fa[v][i - 1]][i - 1];
        }
    }
}

void dfs(int v, int f, int d) {
    dep[v] = d;
    fa[v][0] = f;
    sz[v] = 1;
    int mxsonsize = 0;
    for (int a : adj[v])
        if (a != f) {
            dfs(a, v, d + 1);
            sz[v] += sz[a];
            if (sz[a] > mxsonsize) {
                mxsonsize = sz[a];
                son[v] = a;
            }
        }
}

void builddfn(int v, int& id) {
    dfn[v] = ++id;
    if (son[v]) builddfn(son[v], id);
    for (int a : adj[v])
        if (a != fa[v][0] && a != son[v]) builddfn(a, id);
}

void buildhv(int n) {
    int vid = 0;
    builddfn(1, vid);

    int cid = 0;
    for (int i = 1; i <= n; i++) {
        if (son[fa[i][0]] != i) {
            cid++;
            for (int s = i; s; s = son[s]) chid[s] = cid, head[s] = i;
        }
    }
}

#define ls i << 1
#define rs i << 1 | 1
const ll rr = -0x6896639;  // 亂數，若跟題目碰撞會吃 WA 或 RE
class seg {
   private:
    struct node {  //s : sum, x : max
        int l, r;
        ll adt = 0, stt = rr, s = 0, x = 0;
    };
    vector<node> a;  // 萬萬不可以用普通陣列，要用 vector
    void push(int i) {
        if (a[i].stt != rr) {
            a[ls].stt = a[rs].stt = a[i].stt;
            a[ls].adt = a[rs].adt = 0;
            a[ls].x = a[rs].x = a[i].stt;
            a[ls].s = (a[ls].r - a[ls].l + 1) * a[i].stt;
            a[rs].s = (a[rs].r - a[rs].l + 1) * a[i].stt;
            a[i].stt = rr;
        }
        if (a[i].adt) {
            a[ls].adt += a[i].adt, a[rs].adt += a[i].adt;
            a[ls].x += a[i].adt, a[rs].x += a[i].adt;
            a[ls].s += a[i].adt * (a[ls].r - a[ls].l + 1);
            a[rs].s += a[i].adt * (a[rs].r - a[rs].l + 1);
            a[i].adt = 0;
        }
    }
    void pull(int i) {
        a[i].s = a[ls].s + a[rs].s;
        a[i].x = max(a[ls].x, a[rs].x);
    }
    void build(int l, int r, int i) {
        a[i].l = l, a[i].r = r;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(l, mid, ls), build(mid + 1, r, rs);
    }

   public:
    seg(int n) : a(n << 2) {
        build(1, n, 1);
    }
    void set(int l, int r, ll val, int i = 1) {
        if (a[i].l >= l && a[i].r <= r) {
            a[i].s = val * (a[i].r - a[i].l + 1);
            a[i].x = a[i].stt = val;
            a[i].adt = 0;
            return;
        }
        push(i);
        int mid = (a[i].l + a[i].r) >> 1;
        if (l <= mid) set(l, r, val, ls);
        if (r > mid) set(l, r, val, rs);
        pull(i);
    }
    ll maxx(int l, int r, int i = 1) {
        if (l <= a[i].l && a[i].r <= r) return a[i].x;
        push(i);
        ll ret = -9e18;
        int mid = (a[i].l + a[i].r) >> 1;
        if (l <= mid) ret = max(ret, maxx(l, r, ls));
        if (r > mid) ret = max(ret, maxx(l, r, rs));
        pull(i);
        return ret;
    }
};

int main() {
    fastio();
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0, 1);
    buildhv(n);
    buildlca(n);

    vector<pair<int, pii>> qs;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int lc = lca(a, b);
        int lenn = dep[a] - dep[lc] + dep[b] - dep[lc];
        qs.push_back({lenn, {a, b}});
    }
    sort(all(qs));
    reverse(all(qs));

    int col = 0;
    seg maxtree(n), mintree(n);
    for (auto& qr : qs) {
        col++;
        int a = qr.y.x, b = qr.y.y;
        int L = 1e9, H = -1e9;
        while (head[a] != head[b]) {
            if (dep[head[a]] < dep[head[b]]) swap(a, b);
            assert(dfn[head[a]] <= dfn[a]);
            int maxx = maxtree.maxx(dfn[head[a]], dfn[a]);
            int minn = -mintree.maxx(dfn[head[a]], dfn[a]);
            //cerr << "Q[" << head[a] << ", " << a << "] = [" << minn << ", " << maxx << "]" << endl;
            L = min(L, minn);
            H = max(H, maxx);
            maxtree.set(dfn[head[a]], dfn[a], col);
            mintree.set(dfn[head[a]], dfn[a], -col);
            a = fa[head[a]][0];
        }
        if (dep[a] < dep[b]) swap(a, b);
        int maxx = maxtree.maxx(dfn[b], dfn[a]);
        int minn = -mintree.maxx(dfn[b], dfn[a]);
        //cerr << "Q[" << head[a] << ", " << a << "] = [" << minn << ", " << maxx << "]" << endl;
        L = min(L, minn);
        H = max(H, maxx);
        assert(dfn[b] <= dfn[a]);
        maxtree.set(dfn[b], dfn[a], col);
        mintree.set(dfn[b], dfn[a], -col);

        if (L != H) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}