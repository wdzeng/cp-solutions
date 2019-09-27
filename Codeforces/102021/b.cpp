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

double dist_to_cirlce(pdd& p, pdd& c, double r) {
    double dx = p.x - c.x, dy = p.y - c.y;
    return sqrt(dx * dx + dy * dy - r * r);
}

pdd ext(pdd& src, double dir, double l) { return {src.x + l * cos(dir), src.y + l * sin(dir)}; }

double dangle(double a, double b) {
    a = abs(a - b);
    a = fmod(a, 2 * PI);
    if (a > PI) a = 2 * PI - a;
    return a;
}

pair<double, double> dir_act(pdd& p, pdd& center, double r) {
    double cp = hypot(p.x - center.x, p.y - center.y);
    double theta = acos(r / cp);
    double dir = atan2(p.y - center.y, p.x - center.x);
    double dir1 = dir + theta, dir2 = dir - theta;
    return {dir1, dir2};
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    double discard;
    pdd c;
    double r;
    pdd src, dst;
    cin >> src.x >> src.y >> dst.x >> dst.y >> discard >> discard >> discard >> c.x >> c.y >> r;

    double ps = dist_to_cirlce(src, c, r);
    double pd = dist_to_cirlce(dst, c, r);

    auto s = dir_act(src, c, r);
    auto d = dir_act(dst, c, r);

    double ang[4];
    ang[0] = dangle(s.x, d.x);
    ang[1] = dangle(s.x, d.y);
    ang[2] = dangle(s.y, d.x);
    ang[3] = dangle(s.y, d.y);

    double minang = *min_element(ang, ang + 4);
    double hoo = r * minang;
    double ans = ps + pd + hoo;
    printf("%.9lf\n", ans);
    return 0;
}