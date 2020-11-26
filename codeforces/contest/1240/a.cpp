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

vector<ll> p;
int x, y;
ll a, b, k;
int n;

bool judge(int len) {
    int most = len / (a * b / __gcd(a, b));
    int more = len / a - most;
    int less = len / b - most;
    ll sum = 0;
    for (ll i : p) {
        if (sum >= k) return 1;
        if (most)
            sum += i * (x + y), most--;
        else if (more)
            sum += i * x, more--;
        else if (less)
            sum += i * y, less--;
        else
            break;
    }
    return sum >= k;
}

int solve() {
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) cin >> p[i], p[i] /= 100;
    sort(iter(p), greater<int>());
    cin >> x >> a >> y >> b;
    cin >> k;
    if (x < y) swap(x, y), swap(a, b);
    int l = 1, r = n;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (judge(m))
            r = m - 1;
        else
            l = m + 1;
    }
    if (l > n) return -1;
    return l;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) cout << solve() << '\n';
    return 0;
}