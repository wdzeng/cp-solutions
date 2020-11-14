#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

int H;

struct P {
    vector<pii> r, l;
    int parl = 0, parr = 0;
    pii maxx = {-1, -1}, minx = {1e9, 1e9};
    P(vector<pii>& cs) {
        int n = cs.size();
        cs.push_back(cs[0]);
        cs.push_back(cs[1]);
        for (int i = 1; i <= n; i++) {
            if (cs[i + 1].y == cs[i].y) {
                if (cs[i].y == H)
                    r.push_back(cs[i]);
                else
                    l.push_back(cs[i]);
            }
            if (cs[i + 1].y > cs[i].y) {
                r.push_back(cs[i]);
                if (cs[i].x > maxx.x) maxx = cs[i];
                if (cs[i + 1].x == cs[i].x) parr = 1;
            } else {
                l.push_back(cs[i]);
                if (cs[i].x < minx.x) minx = cs[i];
                if (cs[i + 1].x == cs[i].x) parl = 1;
            }
        }
    }
    double adj(const P& p) const {
        if (parr && p.parl) return 0;
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<pii>> polys(n);
    while (n--) {
        int c;
        cin >> c;
        while (c--) {
            int x, y;
            cin >> x >> y;
            H = max(H, y);
            polys.back().emplace_back(x, y);
        }
    }

    vector<P> Ps;
    for (auto& p : polys) Ps.emplace_back(p);
    return 0;
}