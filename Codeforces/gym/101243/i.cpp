#pragma GCC optimize("Ofast", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

#define T double
inline bool eq(double a, double b) { return abs(a - b) < 1e-7; }

#define point vec
struct vec {
    T x, y;  // 向量或坐標的x,y值
    vec operator+(vec o) { return {x + o.x, y + o.y}; }
    vec operator-(vec o) { return {x - o.x, y - o.y}; }
    vec operator*(T o) { return {x * o, y * o}; }
    vec operator/(T o) { return {x / o, y / o}; }
    T operator%(vec o) { return x * o.x + y * o.y; }      // 內積
    T operator*(vec o) { return x * o.y - y * o.x; }      // 外積
    T abs() { return x * x + y * y; }                     // 絕對值平方
    bool samedir(vec o) { return eq(x * o.y, y * o.x); }  // 兩向量方向是否相同或相反
};
vec makevec(point src, point dst) { return {dst.x - src.x, dst.y - src.y}; }

#define seg line
struct line {
    point s, t;  // 此直線經過s,t；或此線段始於s且止於t
    vec d;       // 此直線的向量
    T a, b, c;   // ax+by=c

    line(point p, point q) {  // 此直線經過p,q；或此線段為始於p且止於q
        s = p, t = q, d = makevec(p, q);
        a = p.y - q.y, b = q.x - p.x, c = a * p.x + b * p.y;
    }
    // 點是否在直線上
    bool passLine(point p) { return d.samedir(p - s); }
    bool passSeg(point p) {  // 點是否在線段上
        vec ap = makevec(s, p), bp = makevec(t, p);
        return passLine(p) && ap % bp < 0;
    }
    // 兩直線是否重合
    bool sameLine(line o) { return d.samedir(o.d) && passLine(o.s); }
    // 兩直線是否平行且不重合
    bool para(line o) { return d.samedir(o.d) && !passLine(o.s); }
    point proj(point p) {  // 求某點在此直線上的投影座標
        vec e = {p - s};
        T t = e % d / d.abs();
        vec dst = {d.x * t, d.y * t};
        return s + dst;
    }
    // 點與直線距離平方
    T dist2(point p) { return (proj(p) - p).abs(); }
    // 兩平行直線距離平方
    T dist2(line o) { return (o.proj(s) - s).abs(); }
    // 此直線是否將兩點隔開
    bool split(point p, point q) { return (a * p.x + b * p.y < 0) != (a * q.x + b * q.y < 0); }
    // 兩非平行線段是否相交
    bool meet(seg o) { return split(o.s, o.t) && o.split(s, t); }
    point intersect(line o) {  // 兩非平行直線相交座標
        return {(c * o.b - b * o.c) / (a * o.b - b * o.a),
                (a * o.c - c * o.a) / (a * o.b - b * o.a)};
    }
    double cosangle(line o) {  // 兩直線夾角之 cos 值
        return (d % o.d) / (sqrt(d.abs() * o.d.abs()));
    }
};

double dist2(point a, point b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
#ifndef hy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<point> poly;
    while (n--) {
        double x, y;
        cin >> x >> y;
        poly.push_back({x, y});
    }
    n = poly.size();

    double ans = 1e18;
    if (n + 2 == m + k) {
        for (int i = 0; i < n; i++) {
            ans = min(ans, dist2(poly[i], poly[(i + m - 1) % n]));
        }
    }
    //
    else if (n + 3 == m + k) {
        vector<int> cands = {m, k};
        for (int a : cands) {
            for (int i = 0; i < n; i++) {
                line l(poly[(i + a - 2) % n], poly[(i + a - 1) % n]);
                point j = l.proj(poly[i]);
                if (l.passSeg(j)) {
                    ans = min(ans, l.dist2(poly[i]));
                } else {
                    ans = min(ans, dist2(poly[i], l.s));
                    ans = min(ans, dist2(poly[i], l.t));
                }
            }
        }
    }  //
    else if (n + 4 == m + k) {
        vector<int> cands = {m, k};
        for (int a : cands) {
            for (int i = 0; i < n; i++) {
                line l(poly[(i + a - 2) % n], poly[(i + a - 1) % n]);
                point j = l.proj(poly[i]);
                if (l.passSeg(j)) {
                    ans = min(ans, l.dist2(poly[i]));
                } else {
                    ans = min(ans, dist2(poly[i], l.s));
                    ans = min(ans, dist2(poly[i], l.t));
                }
                j = l.proj(poly[(i + 1) % n]);
                if (l.passSeg(j)) {
                    ans = min(ans, l.dist2(poly[(i + 1) % n]));
                } else {
                    ans = min(ans, dist2(poly[(i + 1) % n], l.s));
                    ans = min(ans, dist2(poly[(i+1)%n], l.t));
                }
            }
        }
    }  //
    else {
        printf("-1\n");
        return 0;
    }
    printf("%.3f\n", sqrt(ans));
    return 0;
}