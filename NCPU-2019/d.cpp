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

void solve() {
    int n;
    cin >> n;
    vector<pair<int, string>> v;
    while (n--) {
        string s;
        int val;
        cin >> s >> val;
        val *= -1;
        int t;
        cin >> t;
        if (t > 1000) continue;
        v.emplace_back(val, s);
    }
    sort(iter(v));
    for (int i = 0; i < min(3, (int)v.size()); i++) {
        cout << v[i].y << ' ' << -v[i].x << '\n';
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}