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

const int N = 1e4 + 5;
vector<pair<ll, pii>> edges;
pair<ll, int> adj[N];
int fa[N], sz[N];

void reset() {
    for (int i = 0; i < N; i++) fa[i] = i, sz[i] = 1;
}

int par(int v) {
    if (fa[v] == v) return v;
    return fa[v] = par(fa[v]);
}

int join(int a, int b) {
    a = par(a), b = par(b);
    if (a == b) return 0;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    fa[b] = a;
    return 1;
}

int judge(int n, ll m) {
    reset();
    int i = lower_bound(all(edges), pair<ll, pii>{m, {-1, -1}}) - edges.begin();
    int link = 0;
    for (; i < edges.size(); i++) {
        link += join(edges[i].y.x, edges[i].y.y);
        if (link == n - 1) return 1;
    }
    return 0;
}

vector<pair<ll, pii>> solve(int n, ll m) {
    reset();
    vector<pair<ll, pii>> ret;
    int i = lower_bound(all(edges), pair<ll, pii>{m, {-1, -1}}) - edges.begin();
    int link = 0;
    for (; i < edges.size(); i++) {
        if (join(edges[i].y.x, edges[i].y.y)) {
            link++;
            ret.push_back(edges[i]);
        }
        if (link == n - 1) return ret;
    }
    assert(0);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a > b) swap(a, b);
        ll w;
        cin >> w;
        edges.push_back({w, {a, b}});
    }
    sort(all(edges));
    reverse(all(edges));
    reset();
    int link = 0;
    for (auto& e : edges) {
        int a, b;
        tie(a, b) = e.y;
        if (join(a, b)) {
            if (++link == n - 1) {
                while (edges.back() != e) edges.pop_back();
                break;
            }
        }
    }

    reverse(all(edges));
    reset();
    vector<pair<ll, pii>> used;
    link = 0;
    for (auto& e : edges) {
        int a, b;
        tie(a, b) = e.y;
        if (join(a, b)) {
            used.push_back(e);
            if (++link == n - 1) break;
        }
    }

    reverse(all(used));
    reset();
    ll ans = 0;
    for (auto& e : used) {
        ll w = e.x;
        int a, b;
        tie(a, b) = e.y;
        ans += w * sz[par(a)] * sz[par(b)];
        join(a, b);
    }
    cout << ans << endl;
    return 0;
}