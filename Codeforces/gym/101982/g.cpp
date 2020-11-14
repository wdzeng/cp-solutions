#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double, double> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

double dd(pii a, pii b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); }
pii operator+(pii a, pii b) { return {a.x + b.x, a.y + b.y}; }
pii operator-(pii a, pii b) { return {a.x - b.x, a.y - b.y}; }
double operator*(pii a, pii b) { return a.x * b.y - a.y * b.x; }
double operator%(pii a, pii b) { return a.x * b.x + a.y * b.y; }
pii operator*(double d, pii p) { return {d * p.x, d * p.y}; }

double dd(pii p, pii a, pii b) {
    if (a > b) swap(a, b);
    if (a.y == b.y && a.y == p.y) return 1e18;
    if (a.x == b.x && a.x == p.x) return 1e18;
    pii ap = p - a;
    pii ab = b - a;
    pii s = ap % ab / dd(a, b) * ab + a;
    if (s < a || s > b) return 1e18;
    return dd(p, s);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    pii a, b, c, d, p;
    cin >> p.x >> p.y >> a.x >> a.y >> c.x >> c.y;
    b = {a.x, c.y};
    d = {c.x, a.y};
    double ans = 1e18;
    ans = min(ans, dd(p, a));
    ans = min(ans, dd(p, b));
    ans = min(ans, dd(p, c));
    ans = min(ans, dd(p, d));
    ans = min(ans, dd(p, a, b));
    ans = min(ans, dd(p, b, c));
    ans = min(ans, dd(p, c, d));
    ans = min(ans, dd(p, d, a));
    printf("%.3f\n", sqrt(ans));
    return 0;
}