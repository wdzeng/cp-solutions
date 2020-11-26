#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())
#define T double

inline bool eq(double a, double b) { return abs(a - b) < 1e-7; }
inline bool le(double a, double b) { return a < b || eq(a, b); }
inline bool ge(double a, double b) { return a > b || eq(a, b); }
inline bool lt(double a, double b) { return le(a, b) && !eq(a, b); }
inline bool gt(double a, double b) { return ge(a, b) && !eq(a, b); }

#define vec point
struct point {
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

const int N = 5010;
vector<int> adj2[N]; // 圓心距離 <=2 建邊 
vector<int> adj4[N]; // 圓心距離 <=4 建邊
point cc[N]; // 圓心座標

inline double dist2(point i, point j) {
    double dx = i.x - j.x;
    double dy = i.y - j.y;
    return dx * dx + dy * dy;
}

#define rr (r * r)
#define usevars                                            \
    double x1 = c.x, x2 = o.c.x, y1 = c.y, y2 = o.c.y;     \
    double r1 = r, r2 = o.r, r12 = r1 * r1, r22 = r2 * r2; \
    double dx = x2 - x1, dy = y2 - y1, dd = dx * dx + dy * dy, d = sqrt(dd);
const double PI = acos(-1);
struct circle {
    point c;   // 圓心
    double r;  // 半徑
    // 求圓與圓的交點並回傳交點數量。
    int meetCircle(circle o, point& ans1, point& ans2) {
        usevars;
        if (gt(d, r1 + r2)) return 0;       // 互斥
        if (lt(d, abs(r1 - r2))) return 0;  // 完全包含
        point A = {(x1 + x2) / 2, (y1 + y2) / 2};
        double f = (r12 - r22) / (2 * dd);
        point B = {dx * f, dy * f};
        double h = (r12 - r22);
        f = sqrt(2 * (r12 + r22) / dd - h * h / (dd * dd) - 1) / 2;
        point C = {dy * f, -dx * f};
        ans1 = A + B + C, ans2 = A + B - C;
        return eq(d, r1 + r2) ? 1 : 2;
    }
    int contains(point p) { // 問圓是否包含一點
        return le(dist2(c, p), rr);
    }
};

vector<pii> his; // 並查集記錄
int sz[N], fa[N];
int par(int v) {
    if (v == fa[v]) return v;
    return par(fa[v]);
}
int join(int a, int b) {
    a = par(a), b = par(b);
    if (a == b) {
        return 0;
    }
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    fa[b] = a;
    his.emplace_back(a, b);
    return 1;
}
void undo() { // 退回到上一次 mark 的位置
    assert(his.size());
    while (1) {
        auto h = his.back();
        his.pop_back();
        if (h.x == -1) break;
        int a, b;
        tie(a, b) = h;
        sz[a] -= sz[b];
        fa[b] = b;
        assert(his.size());
    }
}

#define mark his.emplace_back(-1, -1) // 做標記，之後可以讓並查集退回到這裡
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    for (int i = 0; i < N; i++) fa[i] = i, sz[i] = 1;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> cc[i].x >> cc[i].y;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d2 = dist2(cc[i], cc[j]);
            if (le(d2, 4.0)) { // 若距離平方小於4，建邊
                adj2[i].push_back(j), adj2[j].push_back(i);
                join(i, j);
            }
            if (le(d2, 16.0)) { // 若距離平方小於16，建邊
                adj4[i].push_back(j), adj4[j].push_back(i);
            }
        }
    }

    int ans = 2; // 答案至少為2
    for (int i = 0; i < n; i++) {
        for (int a : adj4[i]) {
            if (a < i) continue;
            circle ci = {cc[i], 2};
            circle ca = {cc[a], 2};
            point u, v; // 以 u 為圓心，則 a 與 i 必在圓周上； v 亦同
            int res = ci.meetCircle(ca, u, v);
            circle cu = {u, 2};
            circle cv = {v, 2};
            assert(cu.contains(cc[i]));
            assert(cu.contains(cc[a]));
            assert(cv.contains(cc[i]));
            assert(cv.contains(cc[a]));
            auto& k = adj4[i].size() < adj4[a].size() ? i : a;

            mark;
            join(i, a);
            for (int b : adj4[k]) {
                if (cu.contains(cc[b])) join(i, b);
            }
            ans = max(ans, sz[par(i)] + 1);
            undo();

            mark;
            join(i, a);
            for (int b : adj4[k]) {
                if (cv.contains(cc[b])) join(i, b);
            }
            ans = max(ans, sz[par(i)] + 1);
            undo();
        }
    }

    cout << ans << endl;
    return 0;
}