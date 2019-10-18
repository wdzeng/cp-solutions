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

const int R = 1, U = 2, L = 3, D = 4;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll r, c, k;
    cin >> r >> c >> k;
    ll w = 1;
    set<int> v[c], h[r];

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        h[a].insert(b);
        v[b].insert(a);
    }
    for (int i = 0; i < r; i++) h[i].insert(-1), h[i].insert(c);
    for (int i = 0; i < c; i++) v[i].insert(-1), v[i].insert(r);

    set<int> pv = {-1, (int)c}, ph = {-1, (int)r};
    pii loc = {0, 0};
    int dir = R;  //
    int a = min(*h[loc.x].upper_bound(loc.y), *pv.upper_bound(loc.y));
    if (a == loc.y + 1) dir = D;
    while (1) {
        // cout << loc.x << ' ' << loc.y << ' ' << dir << endl;
        if (dir == R) {
            int a = min(*h[loc.x].upper_bound(loc.y), *pv.upper_bound(loc.y));
            if (a == loc.y + 1) {
                break;
            }
            w += a - 1 - loc.y;
            ph.insert(loc.x);
            loc.y = a - 1;
            dir = D;
        } else if (dir == D) {
            int a = min(*v[loc.y].upper_bound(loc.x), *ph.upper_bound(loc.x));
            if (a == loc.x + 1) {
                break;
            }
            w += a - 1 - loc.x;
            pv.insert(loc.y);
            loc.x = a - 1;
            dir = L;
        } else if (dir == L) {
            int a = max(*prev(h[loc.x].lower_bound(loc.y)), *prev(pv.lower_bound(loc.y)));
            if (a == loc.y - 1) {
                break;
            }
            w += loc.y - a - 1;
            ph.insert(loc.x);
            loc.y = a + 1;
            dir = U;
        } else if (dir == U) {
            int a = max(*prev(v[loc.y].lower_bound(loc.x)), *prev(ph.lower_bound(loc.x)));
            if (a == loc.x - 1) {
                break;
            }
            w += loc.x - a - 1;
            pv.insert(loc.y);
            loc.x = a + 1;
            dir = R;
        }
    }
    if (w != r * c - k)
        cout << "No\n";
    else
        cout << "Yes\n";
    return 0;
}
