#include <bits/stdc++.h>
using namespace std;
typedef long double lld;
typedef pair<lld, lld> pdd;
typedef pair<lld, lld> direction;
#define x first
#define y second

inline direction safedf(const pdd& a, const pdd& b, const direction& df) { return a == b ? df : direction(b.x - a.x, b.y - a.y); }
inline lld safeslope(const pdd& a, const pdd& b, const direction& df) {
    return a == b ? atan2(df.y, df.x) : atan2(b.y - a.y, b.x - a.x);
}
inline bool dirgr(const direction& a, const direction& b) { return b.x * a.y - b.y * a.x > 0; }
inline bool dirbtw(const direction& d, const direction& src, const direction& dst) {
    return dirgr(dst, src) ? (dirgr(d, src) && dirgr(dst, d)) : (dirgr(d, src) || dirgr(dst, d));
}
inline bool feq(lld a, lld b) { return abs(a - b) < 1e-6; }
inline lld area(const pdd& a, const pdd& b, const pdd& c) { return abs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)); }
inline lld dist2(const pdd& p, const pdd& q) {
    lld dx = p.x - q.x, dy = p.y - q.y;
    return dx * dx + dy * dy;
}

inline pdd extend(const pdd& p0, const direction& d0, pdd p1, const direction& d1) {
    p1.y -= p0.y, p1.x -= p0.x;
    lld t = (p1.y * d0.x - p1.x * d0.y) / (d0.y * d1.x - d0.x * d1.y);
    return pdd(p1.x + t * d1.x + p0.x, p1.y + t * d1.y + p0.y);
}

struct Segment {
    pdd s, d;
    Segment(const pdd& s, const pdd& d) : s(s), d(d) {}
    bool intersect(const pdd& a, const pdd& b) {
        lld rec = area(s, d, {s.x + b.x - a.x, s.y + b.y - a.y});
        return feq(area(s, a, b) + area(d, a, b), rec) && feq(area(s, d, a) + area(s, d, b), rec);
    }
};

struct Arc {
    pdd center, src, dst;
    lld r2;
    Arc(const pdd& s, const pdd& d, const direction& dir) {
        direction dsd(d.x - s.x, d.y - s.y);
        src = dirgr(dsd, dir) ? s : d, dst = dirgr(dsd, dir) ? d : s;
        center = extend({(s.x + d.x) / 2, (s.y + d.y) / 2}, {-dsd.y, dsd.x}, s, {-dir.y, dir.x});
        r2 = dist2(center, s);
    }
    pdd chord(const pdd& a, const pdd& b) {
        if (area(a, b, center) == 0) return center;
        direction dab(b.x - a.x, b.y - a.y);
        return extend(a, dab, center, {a.y - b.y, b.x - a.x});
    }
    bool intersect(const pdd& a, const pdd& b) {
        pdd chd = chord(a, b);
        if (dist2(chd, center) > r2) return false;
        direction dab(b.x - a.x, b.y - a.y);
        lld dist2ac = dist2(a, center), dist2bc = dist2(b, center);
        if (dist2ac > r2 && dist2bc > r2 && feq(safeslope(chd, a, dab), safeslope(chd, b, {-dab.x, -dab.y}))) return false;
        direction dcs(src.x - chd.x, src.y - chd.y), dcd(dst.x - chd.x, dst.y - chd.y);
        if (dist2ac > r2) {
            if (dirbtw(safedf(chd, a, dab), dcs, dcd)) return true;
        }
        if (dist2bc > r2) {
            if (dirbtw(safedf(chd, b, {-dab.x, -dab.y}), dcs, dcd)) return true;
        }
        return false;
    }
};

vector<pdd> guards, arts;
vector<Segment> segments;
vector<Arc> arcs;

const int maxn = 202;
int graph[maxn][maxn];
int artlv[maxn], guardlv[maxn];
int nart, nguard, nwall, nflow;

void get_input() {
    int x, y, dx, dy;
    char c;
    nflow = 0;
    for (int i = 0; i < nwall; i++) {
        int ww;
        cin >> ww >> x >> y;
        pdd initp(x, y), prev = initp;

        for (int j = 0; j < ww; j++) {
            if (j == ww - 1) {
                cin >> c;
                if (c == 's')
                    segments.push_back(Segment(prev, initp));
                else {
                    cin >> dx >> dy;
                    arcs.push_back(Arc(prev, initp, direction(dx, dy)));
                }
                break;
            }
            cin >> c;
            if (c == 's') {
                cin >> x >> y;
                pdd curr(x, y);
                segments.push_back(Segment(prev, curr));
                prev = curr;
            }  //
            else {
                cin >> dx >> dy >> x >> y;
                pdd curr(x, y);
                arcs.push_back(Arc(prev, curr, direction(dx, dy)));
                prev = curr;
            }
        }
    }

    for (int i = 0; i < nart; i++) {
        cin >> x >> y;
        arts.push_back(pdd(x, y));
        cin >> artlv[i];
        nflow += artlv[i];
    }

    for (int i = 0; i < nguard; i++) {
        cin >> x >> y;
        guards.push_back(pdd(x, y));
        cin >> guardlv[i];
    }
}

bool visible(const pdd& a, const pdd& b) {
    for (auto& w : segments)
        if (w.intersect(a, b)) return false;
    for (auto& w : arcs)
        if (w.intersect(a, b)) return false;
    return true;
}

void build_graph() {
    for (int i = 0; i < nguard; i++) {
        graph[0][i + 1] = guardlv[i];
        for (int j = 0; j < nart; j++)
            if (visible(guards[i], arts[j])) graph[i + 1][nguard + j + 1] = 1;
    }
    for (int i = 0; i < nart; i++) graph[nguard + i + 1][nguard + nart + 1] = artlv[i];
}

vector<int> bfs() {
    vector<int> path(nguard + nart + 2, -1);
    path[0] = -2;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < nguard + nart + 2; i++) {
            if (path[i] == -1 && graph[v][i] > 0) {
                path[i] = v;
                if (i == nguard + nart + 1) return path;
                q.push(i);
            }
        }
    }
    return {};
}

bool judge() {
    int maxflow = 0;
    vector<int> path = bfs();
    while (!path.empty()) {
        for (int i = nguard + nart + 1; i; i = path[i]) {
            graph[path[i]][i]--;
            graph[i][path[i]]++;
        }
        maxflow++;
        path = bfs();
    }
    return maxflow == nflow;
}

bool solve() {
    get_input();
    build_graph();
    return judge();
}

int main() {
    int cs = 0;
    while (cin >> nwall >> nart >> nguard && (nwall || nart || nguard)) {
        printf("Case %d: %s\n", ++cs, solve() ? "Yes" : "No");
        guards.clear();
        arts.clear();
        segments.clear();
        arcs.clear();
        memset(graph, 0, sizeof(graph));
    }
    return 0;
}