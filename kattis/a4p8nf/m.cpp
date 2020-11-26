#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif
const double PI = acos(-1);
int main() {
    fastio();
    int a, b;
    cin >> a >> b;
    if (0 <= b && b <= 180)
        cout << "safe" << endl;
    else {
        b = 270 - b;
        double ab = b * PI / 180;
        double s = abs(cos(ab));
        cout << (int)floor(1.0 * a / s) << endl;
    }
    return 0;
}