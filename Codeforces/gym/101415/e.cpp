#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(l0) memset(l0, 0, sizeof(l0))
#define mss(l0) memset(l0, -1, sizeof(l0))
#define mp(e, f) make_pair(e, f)

typedef pair<pii, pii> line;
typedef pair<double, pair<int, int>> info;

inline bool between(int v, int l0, int l1) {
    if (l0 > l1) swap(l0, l1);
    return l0 <= v && v <= l1;
}

inline bool online(const pii& p, const line& l) {
    if (!between(p.x, l.first.x, l.second.x)) return false;
    if (!between(p.y, l.first.y, l.second.y)) return false;
    int dax = l.first.x - p.x;
    int day = l.first.y - p.y;
    int dbx = l.second.x - p.x;
    int dby = l.second.y - p.y;
    return dax * dby == dbx * day;
}

inline ll d2(const pii& l0, const pii& l1) {
    ll dx = l0.x - l1.x, dy = l0.y - l1.y;
    return dx * dx + dy * dy;
}

struct pE {
    const int N;
    vector<pii> points;
    vector<pii> streets;
    vector<line> signs;
    vector<vector<int>> adj;
    map<pii, int> p2i;
    set<pii> issign;

    pE(int n) : N(n) {}

    int pii2index(const pii& p) {
        if (p2i.count(p) == 0) {
            p2i[p] = p2i.size();
            points.push_back(p);
        }
        return p2i[p];
    }

    int dir(const line& street, const line& sign) {
        if (sign.x == street.y) return -dir({street.y, street.x}, sign);
        if (sign.y == street.y) return -dir({street.y, street.x}, {sign.y, sign.x});
        if (sign.y == street.x) return dir(street, {sign.y, sign.x});

        // -1 src cannot to dst
        // +1 dst cannot to src
        ll sd = d2(street.x, street.y);
        ll se = d2(street.x, sign.y);
        ll ed = d2(sign.y, street.y);
        if (sd + se == ed) return 0;
        return (ed < sd + se) ? -1 : 1;
    }

    void breakdown(vector<line>& lines) {
        vector<line> u;
        vector<vector<pii>> breakpoints;
        for (int i = 0; i < N; i++) {
            line& l0 = lines[i];
            set<pii> bpts = {l0.x, l0.y};
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                line& l1 = lines[j];
                if (online(l1.x, l0)) {
                    bpts.insert(l1.x);
                }  //
                else if (online(l1.y, l0)) {
                    bpts.insert(l1.y);
                }
            }
            breakpoints.push_back(vector<pii>(iter(bpts)));
        }
        for (auto& l1 : breakpoints) {
            for (int i = 0; i < l1.size() - 1; i++) {
                u.push_back({l1[i], l1[i + 1]});
            }
        }
        lines.swap(u);
    }

    void classify(const vector<line>& lines) {
        vector<line> lstreets;
        map<pii, int> freq;

        for (auto& l : lines) {
            freq[l.x]++;
            freq[l.y]++;
        }
        for (auto& l : lines) {
            if (freq[l.x] > 1 && freq[l.y] > 1)
                lstreets.push_back(l);
            else {
                signs.push_back(l);
                issign.insert(l.x);
                issign.insert(l.y);
            }
        }

        for (auto& l : lstreets) {
            streets.push_back({pii2index(l.x), pii2index(l.y)});
        }
    }

    void build_map() {
        vector<unordered_set<int>> e(points.size());
        for (auto& s : streets) {
            e[s.x].insert(s.y);
            e[s.y].insert(s.x);
        }

        for (auto& s : streets) {
            const pii& src = points[s.x], dst = points[s.y];
            line st = {src, dst};
            for (auto& sg : signs) {
                if (online(sg.x, st) || online(sg.y, st)) {
                    int d = dir(st, sg);
                    if (d <= 0) e[s.x].erase(s.y);
                    if (d >= 0) e[s.y].erase(s.x);
                }
            }
        }

        for (int i = 0; i < e.size(); i++) {
            adj.push_back(vector<int>(iter(e[i])));
        }
    }

    vector<int> bfs(int src, int dst) {
        vector<int> dad(points.size(), -2);
        priority_queue<info> q;
        q.push({0.0, {-1, src}});

        while (!q.empty()) {
            const double dist = q.top().x;
            const int v = q.top().y.y;
            const int d = q.top().y.x;
            q.pop();
            if (dad[v] != -2) continue;
            
            dad[v] = d;
            if (v == dst) break;
            
            const pii& p0 = points[v];
            for (int a : adj[v]) {
                if (dad[a] != -2) continue;
                const pii& p1 = points[a];
                double updated_dist = dist - hypot(p0.x - p1.x, p0.y - p1.y);
                q.push({updated_dist, {v, a}});
            }
        }

        if (dad[dst] == -2) return {};

        vector<int> ret;
        int loc = dst;
        for (loc = dst; loc != -1; loc = dad[loc]) {
            if (issign.count(points[loc])) continue;
            ret.push_back(loc);
        }
        return ret;
    }

    void solve() {
        pii src, dst;
        cin >> src.x >> src.y >> dst.x >> dst.y;

        vector<line> lines(N);
        for (int i = 0; i < N; i++) {
            line& l = lines[i];
            cin >> l.x.x >> l.x.y >> l.y.x >> l.y.y;
        }

        breakdown(lines);
        classify(lines);
        build_map();
        auto path = bfs(pii2index(src), pii2index(dst));

        if (path.empty()) {
            cout << "-1\n";
            return;
        }

        while (!path.empty()) {
            pii& p = points[path.back()];
            cout << p.x << ' ' << p.y << '\n';
            path.pop_back();
        }
        cout << "0\n";
    }
};

int main() {
    freopen("E.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    while (cin >> N && N != 0) {
        pE(N).solve();
    }
    return 0;
}