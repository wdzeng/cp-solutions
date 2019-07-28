#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> point;
#define x first
#define y second
#define mem(x) memset(x, 0, sizeof(x));
const double pi = acos(0) * 2;
const int maxn = 100;

inline double dist(point& p1, point& p2) {
    double dx = p1.x - p2.x, dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

inline point translate(point& c, double len, double dir) { return {c.x + len * cos(dir), c.y + len * sin(dir)}; }

inline double atan(point& a, point& b) { return atan2(a.y - b.y, a.x - b.x); }

point intersect(point& p0, double dir0, point& p1, double dir1) {
    double x0 = p0.x, y0 = p0.y, x1 = p1.x, y1 = p1.y;
    double s = ((x1 - x0) * sin(dir0) - (y1 - y0) * cos(dir0)) / (sin(dir1) * cos(dir0) - cos(dir1) * sin(dir0));
    return {x1 + s * cos(dir1), y1 + s * sin(dir1)};
}

struct segment {
    point src, dst;
    double dir;
    segment(point& s, point& d) : src(s), dst(d), dir(atan(d, s)) {}
    bool judge(point& p) { return remainder(atan(p, src) - dir, 2 * pi) > 0; }
    bool block(point& a, point& b) {
        segment s(a, b);
        return judge(a) != judge(b) && s.judge(src) != s.judge(dst);
    }
};

struct arc {
    point c;
    double r, src, dst;
    arc(point s, point d, double dy, double dx) {
        double sdir = atan2(dy, dx), edir = atan(d, s);
        double ddir = remainder(edir - sdir, 2 * pi);
        double dir = ddir > 0 ? (sdir + pi / 2) : (sdir - pi / 2);
        double xs = s.x, ys = s.y, xd = d.x, yd = d.y;
        r = (xd * xd + xs * xs + yd * yd + ys * ys - 2 * xd * xs - 2 * yd * ys) /
            (2 * xd * cos(dir) + 2 * yd * sin(dir) - 2 * xs * cos(dir) - 2 * ys * sin(dir));
        r = abs(r);
        c = {xs + r * cos(dir), ys + r * sin(dir)};

        // cout << ddir << endl;
        if (ddir < 0) swap(d, s);
        src = atan(s, c), dst = atan(d, c);
        // printf("Center: (%g, %g) Src: %g Dst %g\n", c.x, c.y, src, dst);
    }
    bool cover(double deg) {
        // check if a center can bee sen from outside at given degree
        if (src < dst) return deg > src && deg < dst;
        return deg > src || deg < dst;
    }
    pair<point, point> match(point& a, point& b) {
        double dira = atan(b, a), dirc = dira + pi / 2;
        point ins = intersect(c, dirc, a, dira);

        double d = dist(c, ins);
        double dir = atan(ins, c);
        double ddeg = acos(d / r);
        return {translate(c, r, dir - ddeg), translate(c, r, dir + ddeg)};
    }
    double block(point& a, point& b) {
        double dista = dist(a, c), distb = dist(b, c);
        // If both points are inside the circle, they can see each other
        if (dista < r && distb < r) return false;

        double dira = atan(b, a), dirc = dira + pi / 2;
        point ins = intersect(c, dirc, a, dira);
        // If the distance between line of two points and the center is greater than radius, they can sea each other
        if (dist(ins, c) > r) return false;
        double d = dist(c, ins);
        // If two points and the center form a line
        if (d == 0) {
            // If tow points are at one side and both outside the circle, they can see each other
            if (dista > r && distb > r && atan(a, c) == atan(b, c)) return false;
            // If both points can see the center, they can see each other
            return dista > r && cover(atan(a, c)) || distb > r && cover(atan(b, c));
        }
        segment s(c, ins);
        // If tow points are at one side and both outside the circle, they can see each other
        if (dista > r && distb > r && s.judge(a) == s.judge(b)) return false;

        double dir = atan(ins, c);
        double ddeg = acos(d / r);
        double dega = remainder(dir - ddeg, 2 * pi), degb = remainder(dir + ddeg, 2 * pi);
        point pa = translate(c, r, dega), pb = translate(c, r, degb);
        // If both points can see the center, they can see each other
        if (dista > r) {
            if (s.judge(a) == s.judge(pa) && cover(dega)) return true;
            if (s.judge(a) != s.judge(pa) && cover(degb)) return true;
        }
        if (distb > r) {
            if (s.judge(b) == s.judge(pa) && cover(dega)) return true;
            if (s.judge(b) != s.judge(pa) && cover(degb)) return true;
        }
        return false;
    }
};

struct obj {
    point p;
    int lv, cur = 0;
};

int W, A, G;
vector<segment> segvec;
vector<arc> arcvec;
vector<obj> artvec;
vector<obj> grdvec;

bool visible[maxn][maxn], keep[maxn][maxn];

bool try_see(int g, int a) {
    for (int i = 0; i < segvec.size(); i++)
        if (segvec[i].block(grdvec[g].p, artvec[a].p)) {
            //   cout << "Wall " << i << " blocked" << endl;
            return false;
        }
    for (int i = 0; i < arcvec.size(); i++)
        if (arcvec[i].block(grdvec[g].p, artvec[a].p)) {
            //   cout << "Arc " << i << " blocked" << endl;
            return false;
        }
    return true;
}

bool try_match(int a, vector<vector<bool>> forbid) {
    if (artvec[a].cur == artvec[a].lv) return true;
    // find empty
    for (int g = 0; g < G; g++) {
        if (visible[g][a] && grdvec[g].cur < grdvec[g].lv && !keep[g][a] && !forbid[g][a]) {
            grdvec[g].cur++;
            keep[g][a] = true;
            if (++artvec[a].cur == artvec[a].lv) return true;
        }
    }
    // find occupied
    for (int g = 0; g < G; g++) {
        if (!visible[g][a] || keep[g][a] || forbid[g][a]) continue;
        keep[g][a] = true;
        artvec[a].cur++;
        forbid[g][a] = true;
        bool success = false;
        for (int othera = 0; othera < A; othera++) {
            if (!visible[g][othera] || othera == a || !keep[g][othera] || forbid[g][othera]) continue;
            keep[g][othera] = false;
            forbid[g][othera] = true;
            artvec[othera].cur--;
            if (try_match(othera, forbid)) {
                success = true;
                break;
            }  //
            else {
                keep[g][othera] = true;
                // forbid[g][othera] = false;
                artvec[othera].cur++;
            }
        }
        if (success) {
            if (artvec[a].cur == artvec[a].lv) return true;
        }  //
        else {
            keep[g][a] = false;
            artvec[a].cur--;
            // forbid[g][a] = false;
        }
    }
    return false;
}

bool try_match_all() {
    mem(keep);

    vector<vector<bool>> b(G, vector<bool>(A, false));
    for (int i = 0; i < A; i++) {
        if (!try_match(i, b)) return false;
    }
    // cout << "\nSuccess\n";
    // for (int g = 0; g < G; g++) {
    //     for (int a = 0; a < A; a++) {
    //         printf("%2s", keep[g][a] ? "#" : ".");
    //     }
    //     cout << endl;
    // }
    return true;
}

bool solve() {
    for (int i = 0; i < W; i++) {
        int nw;
        cin >> nw;
        point first;
        cin >> first.x >> first.y;
        point prev = first;
        while (nw--) {
            char c;
            cin >> c;
            if (nw == 0) {
                if (c == 's')
                    segvec.push_back(segment(prev, first));
                else {
                    int dx, dy;
                    cin >> dx >> dy;
                    arcvec.push_back(arc(prev, first, dy, dx));
                }
                break;
            }
            point p;
            if (c == 's') {
                cin >> p.x >> p.y;
                segvec.push_back(segment(prev, p));
            }  //
            else {
                int dx, dy;
                cin >> dx >> dy;
                cin >> p.x >> p.y;
                arcvec.push_back(arc(prev, p, dy, dx));
            }
            prev = p;
        }
    }
    for (int i = 0; i < A; i++) {
        obj o;
        cin >> o.p.x >> o.p.y >> o.lv;
        artvec.push_back(o);
    }
    for (int i = 0; i < G; i++) {
        obj o;
        cin >> o.p.x >> o.p.y >> o.lv;
        grdvec.push_back(o);
    }

    for (int a = 0; a < artvec.size(); a++) {
        for (int g = 0; g < grdvec.size(); g++) {
            visible[g][a] = try_see(g, a);
            // printf("Guard %d can%s see Art %d\n", g, visible[g][a] ? "" : "not", a);
            // cout << visible[g][a];
        }
        // cout << endl;
    }

    return try_match_all();
}

int main() {
    int cs = 0;
    while (cin >> W >> A >> G && (W || A || G)) {
        printf("Case %d: %s\n", ++cs, solve() ? "Yes" : "No");
        segvec.clear();
        arcvec.clear();
        artvec.clear();
        grdvec.clear();
    }
    return 0;
}