#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define x first
#define y second

pii operator-(const pii& a, const pii& b) { return {a.x - b.x, a.y - b.y}; }
ll cross(const pii& a, const pii& b) { return a.x * b.y - a.y * b.x; }
ll crossfrom(const pii& o, const pii& a, const pii& b) { return cross(a - o, b - o); }
ll dd(const pii& a, const pii& b) {
    ll dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// 給平面上任意個點，求其凸包。返回順序為逆時針。請 include cross 和 operator- 。
vector<pii> makepoly(vector<pii>& pp) {
    int n = pp.size();
    sort(pp.begin(), pp.end());
    vector<pii> ret;
    for (int i = 0; i < n; i++) {
        while (ret.size() >= 2 && crossfrom(ret[ret.size() - 2], ret.back(), pp[i]) <= 0) ret.pop_back();
        ret.push_back(pp[i]);
    }
    for (int i = n - 2, t = ret.size() + 1; i >= 0; i--) {
        while (ret.size() >= t && crossfrom(ret[ret.size() - 2], ret.back(), pp[i]) <= 0) ret.pop_back();
        ret.push_back(pp[i]);
    }
    if (n >= 2) ret.pop_back();
    return ret;
}

// 給凸包，問其兩點最遠距離。若要問平面上任意個點的兩點最遠距離，請先轉成凸包。請 include corss, d2, operator-
// 。若要問距離平方，則可以保證為整數，請把兩處回傳值的 sqrt 去除。
double maxdist(vector<pii>& poly) {
    int k = 1, n = poly.size();
    if (n == 2) return 0;
    double ans = 5e18;
    for (int i = 0; i < n; i++) {
        while (abs(crossfrom(poly[(k + 1) % n], poly[i], poly[(i + 1) % n])) >= abs(crossfrom(poly[k], poly[i], poly[(i + 1) % n])))
            k = (k + 1) % n;
        ans = min(ans, abs(crossfrom(poly[k], poly[i], poly[(i + 1) % n])) / sqrt(dd(poly[i], poly[(i + 1) % n])));
    }
    return ans;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, r;
    cin >> n >> r;
    vector<pii> v(n);
    while (n--) cin >> v[n].x >> v[n].y;
    auto poly = makepoly(v);
    printf("%.6lf\n", maxdist(poly));
    return 0;
}
