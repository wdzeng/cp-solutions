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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pii> K(n);
    for (auto& k : K) cin >> k.x >> k.y;
    double ans = 0;
    double v = 0;
    for (auto& k : K) {
        ans += v * k.y + k.x * k.y * k.y / 2;
        v += k.x * k.y;
    }
    sort(all(K), greater<pii>());
    double ans1 = 0;
    v = 0;
    for (auto& k : K) {
        ans1 += v * k.y + k.x * k.y * k.y / 2;
        v += k.x * k.y;
    }
    printf("%.1lf\n", ans1 - ans);

    return 0;
}