#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int r, p;
    cin >> r >> p;
    if (p <= 1) {
        while (r--) cout << "YES\n";
        return 0;
    }

    vector<pii> s;
    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x >> y;
        s.emplace_back(x, y);
    }
    sort(iter(s));
    for (auto& p : s) p.x -= s.back().x, p.y -= s.back().y;

    bool trans = 0;
    if (s[0].x == 0) {
        trans = 1;
        assert(s[0].y != 0);
        for (auto& p : s) p.x += p.y;
    }

    for (int i = 0; i < r; i++) {
        vector<pii> ss;
        for (int i = 0; i < p; i++) {
            int x, y;
            cin >> x >> y;
            ss.emplace_back(x, y);
        }
        sort(iter(ss));
        for (auto& p : ss) p.x -= ss.back().x, p.y -= ss.back().y;
        if (trans)
            for (auto& p : ss) p.x += p.y;

        bool good = 1;
        for (int j = 0; j < p; j++) {
            if (ss[j].x * s[0].x != ss[0].x * s[j].x || ss[j].y * s[0].x != ss[0].x * s[j].y) good = 0;
        }
        cout << (good ? "YES\n" : "NO\n");
    }
    return 0;
}
