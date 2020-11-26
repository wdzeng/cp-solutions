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

#define ii (i + 1) % n  // 打字加速！
inline pii operator-(const pii& a, const pii& b) {
    return {a.x - b.x, a.y - b.y};
}  // const 不可省略
inline double operator*(const pii& a, const pii& b) {
    return a.x * b.y - a.y * b.x;
}
inline pii operator+(const pii& a, const pii& b) {
    return {a.x + b.x, a.y + b.y};
}
inline pii operator*(double d, const pii& p) {
    return {d * p.x, d * p.y};
}
inline double crzf(const pii& o, const pii& a, const pii& b) {
    return (a - o) * (b - o);
}
inline double dd(const pii& a, const pii& b) {
    auto dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}
// 給平面上任意個點，求其凸包。返回順序為逆時針。此方法會移除重複點。
#define jud \
    crzf(ret[ret.size() - 2], ret.back(), pp[i]) <= 0
vector<pii> makepoly(vector<pii>& pp) {
    int n = pp.size();
    sort(pp.begin(), pp.end());
    pp.erase(unique(pp.begin(), pp.end()), pp.end());
    vector<pii> ret;
    for (int i = 0; i < n; i++) {
        while (ret.size() >= 2 && jud) ret.pop_back();
        ret.push_back(pp[i]);
    }
    for (int i = n - 2, t = ret.size() + 1; i >= 0; i--) {
        while (ret.size() >= t && jud) ret.pop_back();
        ret.push_back(pp[i]);
    }
    if (n >= 2) ret.pop_back();
    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    double C;
    cin >> n >> C;
    vector<pii> v;
    for (int i = 0; i < n; i++) {
        double c, h, p;
        cin >> c >> h >> p;
        h *= C / c, p *= C / c;
        v.emplace_back(h, p);
    }
    double ans = -1;
    if (v.size() == 1) {
        ans = v[0].x * v[0].y;
    } else {
        v = makepoly(v);
        n = v.size();
        v.push_back(v[0]);
        for (int i = 0; i < n; i++) {
            ans = max(ans, v[i].x * v[i].y);
        }
        for (int i = 0; i < n; i++) {
            auto p = v[i], q = v[i + 1];
            double alpha = (q.x * (q.y - p.y) - q.y * (p.x - q.x)) / ((p.y - q.y) * (p.x - q.x) * 2);
            if (alpha <= 0.0 or alpha >= 1.0) continue;
            pii s = alpha * p + (1 - alpha) * q;
            ans = max(ans, s.x * s.y);
        }
    }
    printf("%.2f\n", ans);
    return 0;
}