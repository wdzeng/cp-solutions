#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

const int N = 1e5 + 5;
int col[N];
map<int, int> m;

inline void split(int l) {
    if (m.count(l)) return;
    auto a = prev(m.lower_bound(l));
    m[l] = a->y;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, c, q;
    cin >> n >> c >> q;
    col[1] = n;
    m[-1] = 0;
    m[0] = 1;
    m[n] = 0;
    while (q--) {
        int c, cc, a, b;
        cin >> c >> cc >> a >> b;
        ll s = col[c];
        int l = (a + s * s) % n;
        int r = (a + (s + b) * (s + b)) % n;
        if (l > r) swap(l, r);
        r++;

        split(l);
        split(r);
        auto it = m.lower_bound(l);
        while (it->x < r) {
            auto nx = next(it);
            int c = it->y;
            col[c] -= nx->x - it->x;
            m.erase(it);
            it = nx;
        }
        m[l] = cc;
        col[cc] += r - l;
    }

    cout << *max_element(col + 1, col + c + 1) << endl;
    return 0;
}