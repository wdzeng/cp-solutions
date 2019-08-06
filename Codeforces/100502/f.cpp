#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
typedef pair<double, double> pdd;
#define mp(x, y) make_pair(x, y)
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))
#define x first
#define y second

const int maxn = 500;

inline int dist(const point& a, const point& b) {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

inline int segnify(int p1, int p2) { return p1 * maxn+ p2; }

int& root(int segment, bool setval = false) {
    static int seg[maxn * maxn];
    if (setval) return seg[segment];
    if (seg[segment] == segment) return seg[segment];
    return seg[segment] = root(seg[segment]);
}

unordered_set<int>& sons(int segment) {
    static unordered_set<int> sonn[maxn * maxn];
    return sonn[segment];
}

int& ans(int segment) {
    static int answer[maxn * maxn];
    return answer[segment];
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int n;
    cin >> n;
    point pnt[n];
    for (int i = 0; i < n; i++) {
        cin >> pnt[i].x >> pnt[i].y;
    }
    int m;
    cin >> m;
    vector<pair<int, pair<int, int>>> base_edge;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        for (int p = 0; p < n; p++) {
            int d = min(dist(pnt[u], pnt[p]), dist(pnt[v], pnt[p]));
            base_edge.push_back({d, {segnify(p, v), segnify(p, u)}});
            base_edge.push_back({d, {segnify(v, p), segnify(u, p)}});
        }
    }
    sort(iter(base_edge)), reverse(iter(base_edge));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int segment = segnify(i, j);
            root(segment, true) = segment;
            sons(segment).insert(segment);
        }

    for (const auto& info : base_edge) {
        int d = info.first;
        int seg1 = info.second.first, seg2 = info.second.second;
        seg1 = root(seg1), seg2 = root(seg2);
        if (seg1 == seg2) continue;
        if (sons(seg1).size() < sons(seg2).size()) swap(seg1, seg2);
        for (int sonseg : sons(seg2)) {
            int revseg = segnify(sonseg % maxn, sonseg / maxn);
            if (sons(seg1).count(revseg)) {
                ans(sonseg) = ans(revseg) = d;
            }
        }
        root(seg2) = seg1, sons(seg1).insert(iter(sons(seg2)));
    }

    int q;
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        i--, j--;
        printf("%.8f\n", sqrt(ans(segnify(i, j))));
    }
    return 0;
}