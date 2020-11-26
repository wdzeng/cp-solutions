#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

inline pii operator-(const pii& a, const pii& b) {
    return {a.x - b.x, a.y - b.y};
}

inline ll operator*(const pii& a, const pii& b) {
    return a.x * b.y - a.y * b.x;
}

inline ll crzf(const pii& o, const pii& a, const pii& b) {
    return (a - o) * (b - o);
}

inline ll dd(const pii& a, const pii& b) {
    ll dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

#define jud crzf(ret[ret.size() - 2], ret.back(), pp[i]) <= 0

vector<pii> makepoly(vector<pii>& pp) {
    int n = pp.size();
    sort(all(pp));
    pp.erase(unique(all(pp)), pp.end());
    vector<pii> ret;
    for (int i = 0; i < n; i++) {
        while (ret.size() >= 2 && jud) ret.pop_back();
        ret.push_back(pp[i]);
    }
    for (int i = n - 2, t = ret.size() + 1; i >= 0; i--) {
        while (ret.size() >= t && jud) ret.pop_back();
        ret.push_back(pp[i]);
    }

    if (n >= 2) ret.pop_back();
    return ret;
}

#define ii (i+1) % n
ll area(vector<pii>& poly) {
    int n = poly.size();
    ll ret = 0;
    for (int i = 0; i < n; i++) {
        ret += (poly[i].x * poly[ii].y);
    }
    for (int i = 0; i < n; i++) {
        ret -= (poly[i].y * poly[ii].x);
    }
    return abs(ret);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    ll ans = 0;
    int n;
    cin >> n;
    while (n--) {
        int p;
        cin >> p;
        vector<pii> poly(p);
        for (auto& pl : poly) cin >> pl.x >> pl.y;
        // poly = makepoly(poly);
        ans += area(poly);
    }

    cout << ans / 2 << endl;
    return 0;
}