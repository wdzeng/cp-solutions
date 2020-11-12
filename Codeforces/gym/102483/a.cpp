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

const int N = 1e5 + 5;

namespace G {
double x[N], y[N];
double ansx[N], ansy[N];
}  // namespace G
void solve(int n, double p[N], double ans[N]) {
    vector<pair<double, int>> k;
    for (int i = 0; i < n; i++) {
        double val = p[i];
        int cnt = 1;
        while (!k.empty() && val < k.back().x) {
            auto u = k.back();
            k.pop_back();
            val = (val * cnt + u.x * u.y) / (cnt + u.y);
            cnt += u.y;
        }
        k.emplace_back(val, cnt);
    }
    int i = n - 1;
    while (!k.empty()) {
        auto u = k.back();
        k.pop_back();
        int t = u.y;
        double val = u.x;
        while (t--) ans[i--] = val;
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> G::x[i] >> G::y[i];
    solve(n, G::x, G::ansx);
    solve(n, G::y, G::ansy);
    double out = 0;
    for (int i = 0; i < n; i++) {
        double dx = G::x[i] - G::ansx[i];
        double dy = G::y[i] - G::ansy[i];
        out += dx * dx + dy * dy;
    }
    printf("%.18f\n", out);
    return 0;
}