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

double solve() {
    int n, k;
    cin >> n >> k;

    ll den = n * n + n;
    den *= den;

    double sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            double v;
            cin >> v;
            double frate = (i + 1) * (n - i) * (j + 1) * (n - j) * 4;
            frate /= den;
            for (int x = 0; x < k; x++) v = (1 - v) * frate + v * (1 - frate);
            sum += v;
        }

    return sum;
}

int main() {
    freopen("fetiera.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) printf("%.5lf\n", solve());  // cout << solve() << '\n';
    return 0;
}