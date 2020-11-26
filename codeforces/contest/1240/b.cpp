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

int solve() {
    int n;
    cin >> n;
    vector<pii> v(n, mp(1e9, -1e9));
    set<int> s;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        val--;
        v[val].x = min(v[val].x, i);
        v[val].y = max(v[val].y, i);
        s.insert(val);
    }

    auto a = s.begin();
    int c = 1;
    int ans = 1;
    while (1) {
        auto b = next(a);
        if (b == s.end()) break;
        if (v[*b].x < v[*a].y)
            c = 1;
        else
            c++;
        ans = max(c, ans);
        a++;
    }
    return s.size() - ans;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) cout << solve() << '\n';
    return 0;
}