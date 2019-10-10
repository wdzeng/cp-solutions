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
    // cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        int a, b, x;
        cin >> a >> b >> x;
        if (x % 3 == 0)
            cout << a << '\n';
        else if (x % 3 == 1)
            cout << b << '\n';
        else
            cout << (a ^ b) << '\n';
    }
    return 0;
}