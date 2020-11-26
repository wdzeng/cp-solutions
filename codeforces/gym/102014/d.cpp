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

int H;

bool operator>=(const pii& p, int i) { return p.x / p.y >= i; }
bool operator<(const pii& p, int i) { return p.x / p.y < i; }
bool operator>=(const pii& p, const pii& q) { return p.x * q.y >= p.y * q.x; }
bool operator==(const pii& p, const pii& q) { return p.x * q.y == p.y * q.x; }
pii operator+(const pii& p, const pii& q) { return {p.x * q.y + p.y * q.x, p.y * q.y}; }
pii operator-(const pii& p, const pii& q) { return {p.x * q.y - p.y * q.x, p.y * q.y}; }
pii operator/(const pii& p, int i) { return {p.x, p.y * i}; }

bool isint(pii p) { return p.x % p.y == 0; }

pii solve1(int h, int m) {
    pii ret = {60 * m * H + 3600 * h + 60 * m, 119 * H - 1};
    return ret;
}

pii solve3(int h, int m) {
    pii ret = {60 * m * H + 3600 * h + 60 * m - 3600 * H, 119 * H - 1};
    if (ret.x < 0) ret.x += ret.y;
    return ret;
}

pii solve2(int h, int m) {
    pii ret = {60 * m * H + 3600 * h + 60 * m + 3600 * H, 119 * H - 1};
    if (ret.x / ret.y >= 60) return solve3(h, m);
    return ret;
}

pii hang(int h, int m, pii s) { return {(3600 * h + 60 * m) * s.y + s.x, 3600 * H * s.y}; }
pii mang(int h, int m, pii s) { return {(60 * m) * s.y + s.x, 3600 * s.y}; }
pii sang(int h, int m, pii s) { return {s.x, s.y * 60}; }
bool judge(pii h, pii m, pii s) { return (h + m) / 2 == s or isint((h + m) / 2 + mp(1, 2) - s); }
bool judge(int h, int m, pii s) { return judge(hang(h, m, s), mang(h, m, s), sang(h, m, s)); }
bool invalid(int h, int m, pii s) { return hang(h, m, s) == mang(h, m, s); }

void next(int& h, int& m) {
    m++;
    if (m == 60) {
        m = 0;
        h++;
        if (h == H) h = 0;
    }
}

void red(pii& p) {
    int g = __gcd(p.x, p.y);
    p.x /= g, p.y /= g;
}

void solve() {
    int h, m, s;
    cin >> H >> h >> m >> s;
    if (!H and !h and !m and !s) exit(0);
    bool first = 1;
    while (1) {
        auto ans1 = solve1(h, m), ans2 = solve2(h, m);
        if (ans2 >= 60) ans2 = solve3(h, m);
        if (ans1 > ans2) swap(ans1, ans2);
        if (!first or ans1 >= s) {
            if (!invalid(h, m, ans1) and judge(h, m, ans1)) {
                red(ans1);
                cout << h << ' ' << m << ' ' << ans1.x << ' ' << ans1.y << endl;
                return;
            }
        }
        if (!first or ans2 >= s) {
            if (!invalid(h, m, ans2) and judge(h, m, ans2)) {
                red(ans2);
                cout << h << ' ' << m << ' ' << ans2.x << ' ' << ans2.y << endl;
                return;
            }
        }
        first = 0;
        next(h, m);
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    while (1) solve();
    return 0;
}
