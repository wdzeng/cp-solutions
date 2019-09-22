#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 300 + 10;

double ans, p, res;

int t, n, k, total, crt, fij;

int main() {
    freopen("fetiera.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0); 
    cin >> t;
    while (t--) {
        cin >> n >> k, ans = 0;
        total = n * (n + 1) / 2;
        total *= total;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> fij, res = fij;
                crt = (i + 1) * (n - i) * (j + 1) * (n - j);
                p = (double)crt / total;
                for (int tt = 0; tt < k; tt++)
                    res = (1 - p) * res + p * (1 - res);
                ans += res;
            }
        cout << setprecision(5) << fixed << ans << '\n';
    }
    return 0;
}
