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

const double INF = 1e50;
const double EPS = 1e-7;
const int LIM = 100;

pdd intersect(const pii& p0, const pii& d0, const pii& p1, const pii& d1) {
    double t = double(p1.y * d0.x - p0.y * d0.x + p0.x * d0.y - p1.x * d0.y) / (d1.x * d0.y - d1.y * d0.x);
    return {
        p1.x + d1.x * t,
        p1.y + d1.y * t,
    };
}

inline int a2(const pii& a, const pii& b, const pii& c) {
    int dx1 = b.x - a.x, dx2 = c.x - a.x, dy1 = b.y - a.y, dy2 = c.y - a.y;
    return abs(dx1 * dy2 - dx2 * dy1);
}

inline int d2(const pii& a, const pii& b) {
    int dx = b.x - a.x, dy = b.y - a.y;
    return dx * dx + dy * dy;
}

inline bool isint(double d) { return abs(round(d) - d) < EPS; }

inline bool sameside(const pii& a, const pii& b, const pii& l0, const pii& l1) {
    int area = a2(l0, l1, {b.x + l0.x - a.x, b.y + l0.y - a.y});
    return a2(l0, l1, a) + a2(l0, l1, b) != area;
}

inline bool online(const pii& a, const pii& l0, const pii& l1) {
    int dx0 = a.x - l0.x, dx1 = a.x - l1.x, dy0 = a.y - l0.y, dy1 = a.y - l1.y;
    return dx0 * dy1 == dx1 * dy0;
}

vector<vector<pii>> find_points;

void init() {
    const int M = LIM * 2;
    find_points.resize(M * M + M * M);
    for (int x = 0; x <= M; x++) {
        for (int y = 0; y <= M; y++) {
            int len = x * x + y * y;
            find_points[len].push_back({x, y});
            if (x != 0) find_points[len].push_back({-x, y});
            if (y != 0) find_points[len].push_back({x, -y});
            if (x && y) find_points[len].push_back({-x, -y});
        }
    }
}

inline bool grt(double a, double b) { return a - b > EPS; }

struct pD {
    const pii A, B, C;
    const int area;
    const double distAC;
    bool in[LIM * 2 + 1][LIM * 2 + 1];

    pD(const pii& a, const pii& b, const pii& c) : A(a), B(b), C(c), area(a2(a, b, c)), distAC(sqrt(d2(A, C))) {
        int area = a2(a, b, c);
        for (int x = -LIM; x <= LIM; x++) {
            for (int y = -LIM; y <= LIM; y++) {
                pii p = {x, y};
                in[x + LIM][y + LIM] = a2(p, A, B) + a2(p, B, C) + a2(p, C, A) == area;
            }
        }
    }
    inline bool intri(const pii& p) { return in[p.x + LIM][p.y + LIM]; }
    inline bool inbound(int x) { return -LIM <= x && x <= LIM; }
    inline bool isvalid(const pii& p) { return inbound(p.x) && inbound(p.y) && !intri(p); }

    pair<pdd, pdd> findBC(const pii& AB, const pii& BC) {
        double i = sqrt(d2(AB, A));
        double j = sqrt(d2(BC, C));
        if (i + j < distAC) return {{0.5, 0.5}, {0.5, 0.5}};

        double cos_theta = (j * j + distAC * distAC - i * i) / (2 * j * distAC);
        double theta = acos(cos_theta);
        double dir = atan2(A.y - C.y, A.x - C.x);
        double dir1 = dir + theta, dir2 = dir - theta;
        return {
            {C.x + j * cos(dir1), C.y + j * sin(dir1)},
            {C.x + j * cos(dir2), C.y + j * sin(dir2)},
        };
    }

    double try3(const pii& AB, const pii& BC, const pii& CA) {
        assert(isvalid(AB) && isvalid(BC) && isvalid(CA));

        pii perpdirAB = {B.y - A.y, A.x - B.x};
        pii perpdirBC = {C.y - B.y, B.x - C.x};
        pdd under = intersect(AB, perpdirAB, BC, perpdirBC);
        double dx = under.x - A.x, dy = under.y - A.y;
        double d2uA = dx * dx + dy * dy;
        int d2_AB_A = d2(AB, A);
        if (!grt(d2_AB_A, d2uA)) return INF;
        double ret = sqrt(d2_AB_A - d2uA);
        return ret;
    }

    double try2(const pii& AB, const pii& BC) {
        assert(isvalid(AB) && isvalid(BC));

        double ret = INF;
        bool cand[LIM * 2 + 1][LIM * 2 + 1];
        ms(cand);
        int pa = d2(AB, A);
        int pc = d2(BC, C);
        for (auto& v : find_points[pa]) {
            pii p = {A.x + v.x, A.y + v.y};
            if (!isvalid(p)) continue;
            cand[p.x + LIM][p.y + LIM] = 1;
        }
        for (auto& p : find_points[pc]) {
            pii CA = {C.x + p.x, C.y + p.y};
            if (!isvalid(CA) || sameside(CA, B, C, A) || online(CA, C, A)) continue;
            if (cand[CA.x + LIM][CA.y + LIM]) ret = min(ret, try3(AB, BC, CA));
        }

        assert(ret > 0);
        return ret;
    }

    double try1(const pii& AB) {
        assert(isvalid(AB));
        double ret = INF;
        int len = d2(AB, B);
        for (auto& p : find_points[len]) {
            pii BC = {B.x + p.x, B.y + p.y};
            if (isvalid(BC) && !sameside(A, BC, B, C) && !online(BC, B, C)) {
                ret = min(ret, try2(AB, BC));
            }
        }

        assert(ret > 0);
        return ret;
    }

    void solve() {
        double ret = INF;
        for (int x = -LIM; x <= LIM; x++) {
            for (int y = -LIM; y <= LIM; y++) {
                pii AB = {x, y};
                if (isvalid(AB) && !sameside(AB, C, A, B) && !online(AB, A, B)) {
                    ret = min(ret, try1({x, y}));
                }
            }
        }
        if (ret == INF)
            printf("-1\n");
        else
            printf("%.9lf\n", ret);
    }
};

int main() {
    freopen("D.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    init();
    pii a, b, c;
    while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y && (a.x || b.x || c.x || a.y || b.x || b.y)) {
        pD(a, b, c).solve();
    }
    return 0;
}