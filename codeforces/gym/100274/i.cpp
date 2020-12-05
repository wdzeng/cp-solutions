#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
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

const ll inf = 5e18;
class Dinic {
    struct edge {
        int d, r;
        ll c;
    };
    vector<vector<edge>> adj;
    vector<int> lv, ve;
    int n;
    int mklv(int s, int d) {
        lv.assign(n, -1);
        lv[s] = 0;
        queue<int> q({s});
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& e : adj[v]) {
                if (e.c == 0 || lv[e.d] != -1) continue;
                lv[e.d] = lv[v] + 1, q.push(e.d);
            }
        }
        return lv[d] > 0;
    }
    ll aug(int v, ll f, int d) {
        if (v == d) return f;
        for (; ve[v] < adj[v].size(); ve[v]++) {
            auto& e = adj[v][ve[v]];
            if (lv[e.d] != lv[v] + 1 || !e.c) continue;
            ll sent = aug(e.d, min(f, e.c), d);
            if (sent > 0) {
                e.c -= sent, adj[e.d][e.r].c += sent;
                return sent;
            }
        }
        return 0;
    }

   public:
    Dinic(int n) : n(n + 1) { clear(); }
    void clear() { adj.assign(n, {}); }
    void add_edge(int src, int dst, ll cap) {
        edge ss{dst, (int)adj[dst].size(), cap};
        edge dd{src, (int)adj[src].size(), 0};
        adj[src].push_back(ss), adj[dst].push_back(dd);
    }
    ll max_flow(int s, int d) {
        ll ret = 0;
        while (mklv(s, d)) {
            ve.assign(n, 0);
            while (ll f = aug(s, inf, d)) ret += f;
        }
        return ret;
    }
};

void solve() {
    int a, b;
    cin >> a >> b;
    vector<pair<pii, pii>> birds(a);
    for (auto& p : birds) cin >> p.x.x >> p.x.y >> p.y.y >> p.y.x;
    vector<pair<pii, ll>> thicks(b);
    for (auto& p : thicks) cin >> p.x.x >> p.x.y >> p.y;
    vector<int> iswillie(b);
    vector<int> dump(b, 1);

    auto& w = birds[0];
    ll willieown = w.y.y;

    for (int i = 0; i < b; i++) {
        ll dx = w.x.x - thicks[i].x.x, dy = w.x.y - thicks[i].x.y;
        ll dd = dx * dx + dy * dy;
        if (dd <= w.y.x * w.y.x) iswillie[i] = 1, willieown += thicks[i].y;
    }
    debug(willieown);
    for (int i = 1; i < a; i++) {
        if (birds[i].y.y > willieown) {
            cout << "Lonesome Willy" << endl;
            return;
        }
    }

    Dinic dinic(a + b + 1);
    for (int i = 0; i < b; i++) {
        if (iswillie[i]) continue;
        auto& tk = thicks[i];
        for (int j = 1; j < a; j++) {
            auto& bd = birds[j];
            ll dx = bd.x.x - tk.x.x, dy = bd.x.y - tk.x.y;
            ll dd = dx * dx + dy * dy;
            if (dd <= bd.y.x * bd.y.x) {
                // cout << "bird" << j + 1 << " -> thick " << i + 1 << endl;
                dinic.add_edge(a + i + 1, j + 1, tk.y);
                dump[i] = 0;
            }
        }
    }

    ll expect = 0;
    for (int i = 0; i < b; i++) {
        if (dump[i]) continue;
        dinic.add_edge(1, a + i + 1, thicks[i].y);
        expect += thicks[i].y;
    }

    for (int i = 1; i < a; i++) {
        ll rem = willieown - birds[i].y.y;
        if (rem > 0) dinic.add_edge(i + 1, a + b + 1, rem);
    }

    ll f = dinic.max_flow(1, a + b + 1);
    debug(f);
    debug(expect);
    if (f < expect)
        cout << "Lonesome Willy" << endl;
    else
        cout << "Suiting Success" << endl;
}

int main() {
    fastio();
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}