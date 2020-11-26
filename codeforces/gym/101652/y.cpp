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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    double k, p, x;
    cin >> k >> p >> x;
    double h = sqrt(k * p / x);
    int h0 = floor(h), h1 = ceil(h);
    double ans = min(k * p / h0 + h0 * x, k * p / h1 + h1 * x);
    printf("%.3f\n", ans);
    return 0;
}