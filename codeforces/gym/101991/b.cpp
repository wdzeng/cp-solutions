#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const double PI = acos(-1);

void solve() {
    int n;
    cin >> n;
    long double a = 1e20;
    long double ang = PI * (n - 2) / n;
    long double m = cos((PI - ang) / 2);
    m *= m;
    long double s = 0;
    for (int i = 0; i < 10000; i++) {
        s += a;
        a *= m;
    }
    s = 10000 / (1 - m);
    cout << setprecision(5) << fixed << s << endl;
}

int main() {
    freopen("baklava.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
