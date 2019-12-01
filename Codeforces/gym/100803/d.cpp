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
typedef long double ld;

ld D;
int B;
vector<pii> wall;

bool judge(ld vx, ld vy, ld u) {
    for (auto& w : wall) {
        ld x = w.x - (int)(w.x / u) * u;
        ld t = x / vx;
        ld h = (vy + vy - t) * t / 2;
        if (h < w.y) return 0;
    }
    return 1;
}

bool judge(ld v, ld u) {
    if (v * v - u < 0) return 0;
    ld l = sqrt(v * v - u);
    ld r = sqrt(v * v + u);
    ld v0 = (r + l) / 2;
    ld v1 = (r - l) / 2;
    return judge(v0, v1, u) || judge(v1, v0, u);
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> D >> n >> B;
    while (n--) {
        int x, y; cin >> x >> y;
        wall.emplace_back(x, y);
    }

    ld ans = 1e10;
    for (int i = 1; i <= B + 1; i++) {
        ld u = D / i, l = 0, r = 1e10;
        while (r - l >= 1e-8) {
            ld m = (l + r) / 2;
            if (judge(m, u)) r = m;
            else l = m;
        }
        ans = min(ans, (l + r) / 2);
    }

    printf("%.14LF\n", ans);
    return 0;
}
