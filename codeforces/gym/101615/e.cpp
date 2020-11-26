#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
typedef long double ld;
const ld PI = acos(-1.0);
typedef pair<int, ld> pii;

int n, xx;
ld vel;
vector<pii> v;

bool test(ld angle) {
    ld vx = vel * cos(angle);
    ld vy = vel * sin(angle);

    ld time = xx / vx;
    ld e = time * vy;
    for (auto& ss : v) {
        ld t = ss.x / vx;
        e += t * ss.y;
    }
    return e > 0;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> xx >> vel;

    for (int i = 0; i < n; i++) {
        int a, b;
        ld vv;
        cin >> a >> b >> vv;
        v.emplace_back(b - a, vv);
    }

    ld base_time = ld(xx) / vel;
    ld lim = base_time * 2;

    ld up = PI / 2, down = -PI / 2;
    while (up - down > 1e-7) {
        ld m = (up + down) / 2;
        if (test(m)) {
            up = m;
        } else {
            down = m;
        }
    }

    ld angle = (up + down) / 2;
    ld time = xx / (vel * cos(angle));
    if (time > lim) {
        cout << "Too hard\n";
    }
    else {
        printf("%.3Lf\n", time);
    }
    return 0;
}