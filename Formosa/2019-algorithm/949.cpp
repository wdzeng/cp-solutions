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

typedef pair<pii, int> cat;

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<cat> cats;
    for (int i = 1; i <= n; i++) {
        pii p;
        cin >> p.x >> p.y;
        cats.push_back({p, i});
    }

    sort(iter(cats), [](cat& a, cat& b) {
        if (a.first.x + a.first.y == b.first.x + b.first.y) {
            return a.second < b.second;
        }
        return a.first.x + a.first.y < b.first.x + b.first.y;
    });

    for (cat& c: cats) cout << c.second << '\n';
    return 0;
}