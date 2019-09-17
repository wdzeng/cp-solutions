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

typedef pair<int, pii> edge;

struct pF {
    const int N;
    vector<int> sz;
    vector<int> bel;
    vector<edge> edges;

    pF(int n, int e) : N(n) {
        while (e--) {
            int a, b, l;
            cin >> a >> b >> l;
            a--, b--;
            edges.push_back({l, {a, b}});
        }
        sort(iter(edges));
    }

    void init() {
        sz.assign(N, 1);
        bel.resize(N);
        for (int i = 0; i < N; i++) bel[i] = i;
    }

    void merge_host(int a, int b) {
        if (sz[a] < sz[b]) swap(a, b);
        bel[b] = a;
        sz[a] += sz[b];
        sz[b] = 0;
    }

    int host(int x) {
        if (bel[x] == x) return x;
        return bel[x] = host(bel[x]);
    }

    int solve(const int src) {
        init();
        int lk = 0;

        int dst = src;
        while (dst < edges.size()) {
            edge& e = edges[dst];
            int a = e.y.x, b = e.y.y;
            if (host(a) == host(b)) {
                dst++;
                continue;
            }
            merge_host(host(a), host(b));
            lk++;
            if (lk == N - 1) break;
            dst++;
        }
        if (lk != N - 1) throw "";
        return edges[dst].x - edges[src].x;
    }

    int solve() {
        int ret = INT_MAX;
        try {
            for (int i = 0; i < edges.size(); i++) {
                ret = min(ret, solve(i));
            }
        } catch (...) {
        }
        return ret == INT_MAX ? -1 : ret;
    }
};

int main() {
    // freopen("F.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    while (cin >> n >> m && n) {
        cout << pF(n, m).solve() << endl;
    }
    return 0;
}