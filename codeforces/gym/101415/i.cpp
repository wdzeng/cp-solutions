#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double, double> pii;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)
const double EPS = 1e-10;

inline pii operator-(const pii& p) { return {-p.x, -p.y}; }
inline pii operator+(const pii& a, const pii& b) { return {a.x + b.x, a.y + b.y}; }
inline pii operator-(const pii& a, const pii& b) { return a + -b; }
inline pii operator*(const pii& p, double m) { return {p.x * m, p.y * m}; }
inline pii operator*(double m, const pii& p) { return p * m; }
inline double operator*(const pii& a, const pii& b) { return a.x * b.y - b.x * a.y; }  // cross
inline pii operator/(const pii& p, double m) { return {p.x / m, p.y / m}; }
inline pii operator~(const pii& p) { return {-p.y, p.x}; }  // left orthogality
inline double len2(const pii& p) { return p.x * p.x + p.y * p.y; }
inline double len(const pii& p) { return hypot(p.x, p.y); }
inline pii normal(const pii& p) { return p / len(p); }
inline double angle(const pii& p) { return atan2(p.y, p.x); }
inline bool operator>(const pii& p, const pii& q) { return angle(p) > angle(q); }
inline bool operator<(const pii& p, const pii& q) { return angle(p) < angle(q); }
inline bool operator||(const pii& a, const pii& b) { return abs(a.x * b.y - b.x * a.y) < EPS; }

typedef pair<pii, pii> seg;
#define loc first
#define vec second

inline bool left(const pii& p, const seg& v) { return v.vec * (p - v.loc) > EPS; }
inline bool right(const pii& p, const seg& v) { return v.vec * (p - v.loc) < -EPS; }

inline pii intersect(const seg& a, const seg& b) { return a.loc + a.vec * (b.vec * (a.loc - b.loc)) / (a.vec * b.vec); }

bool is_intersected(vector<seg>& segments) {
    const int N = segments.size();
    deque<pii> p;
    deque<seg> q;
    for (auto& s : segments) {
        if (q.empty()) {
            q.push_back(s);
            continue;
        }
        while (!p.empty() && right(p.back(), s)) p.pop_back(), q.pop_back();
        while (!p.empty() && right(p.front(), s)) p.pop_front(), q.pop_front();
        seg pushed = s;
        if (p.empty() && (q.back().vec || s.vec)) {
            if (right(s.loc, q.back())) s = q.back();
            q.pop_back();
        }
        if (!q.empty()) p.push_back(intersect(q.back(), pushed));
        q.push_back(pushed);
    }
    while (!p.empty() && right(p.back(), q.front())) q.pop_back(), p.pop_back();
    return q.size() >= 3;
}

struct pI {
    int N;
    vector<seg> segs;

    pI(int n) : N(n) {
        vector<pii> locs(N);
        for (int i = 0; i < N; i++) cin >> locs[i].x >> locs[i].y;

        for (int i = 0; i < N; i++) {
            seg s;
            s.loc = locs[i];
            s.vec = normal(locs[(i + 1) % N] - locs[i]);
            segs.push_back(s);
        }
    }

    double solve() {
        double l = 0, r = 15000;
        while (r - l > EPS) {
            double m = (l + r) / 2;
            if (judge(m))
                l = m;
            else
                r = m;
        }
        return l;
    }

    bool judge(double d) {
        vector<seg> segds;
        for (seg& s : segs) {
            seg ss;
            ss.loc = s.loc + d * (~s.vec);
            ss.vec = s.vec;
            segds.push_back(ss);
        }

        return is_intersected(segds);
    }
};

int main() {
    freopen("I.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    while (cin >> n && n) printf("%.6lf\n", pI(n).solve());
    return 0;
}