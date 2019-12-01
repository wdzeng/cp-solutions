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

unordered_map<int, int> m;

bool solve() {
    m.clear();
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        m[x]++;
    }
    for (int i = 1; i <= 1024; i *= 2) {
        int t = m[i];
        t = t / 2 * 2;
        m[i] -= t;
        m[i * 2] += (t / 2);
    }
    return m[2048] > 0;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) cout << (solve() ? "YES" : "NO") << '\n';
    return 0;
}
