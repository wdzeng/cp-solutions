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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll n, m;
    ll a;
    cin >> n >> m >> a;
    ll b = m * n - a;
    if (a % n == 0 || a % m == 0) {
        cout << "1\n";
        return 0;
    }

    for (ll i = 1; i < m; i++) {
        if (a % i == 0 && a / i < n || b % i == 0 && b / i < n) {
            cout << "2\n";
            return 0;
        }
    }

    cout << "3\n";
    return 0;
}