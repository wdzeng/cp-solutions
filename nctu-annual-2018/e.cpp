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
    int n;
    cin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first;
    for (int i = 0; i < n; i++) cin >> v[i].second;
    vector<pii> updated;
    for (pii& p : v) {
        if (p.x && p.y) updated.push_back(p);
    }
    updated.swap(v);
    sort(iter(v), [](pii i, pii j) { return double(i.y) / i.x > double(j.y) / j.x; });

    ll s = 0;
    ll t = 0;
    for (int i = 0; i < v.size(); i++) {
        t += s * v[i].y;
        s += v[i].x;
    }
    cout << t << endl;
    return 0;
}