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
    int n, m;
    cin >> n >> m;
    vector<pii> range(n);
    vector<pii> pp;
    while (m--) {
        int x, y;
        cin >> x >> y;
        pp.emplace_back(x, y);
    }

    for (int i = 0; i < n; i++) range[i] = {i, i};
    sort(iter(pp));
    for (auto& p : pp) {
        int a = p.y;
        int b = a - 1;
        range[a].x = min(range[a].x, range[b].x);
        range[b].x = min(range[a].x, range[b].x);
        range[a].y = max(range[a].y, range[b].y);
        range[b].y = max(range[a].y, range[b].y);
    }
    for (auto& p : range) cout << p.y - p.x + 1 << ' ';
    cout << endl;
    return 0;
}
