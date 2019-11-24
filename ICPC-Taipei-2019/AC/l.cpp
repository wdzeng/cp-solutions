#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;
typedef pair<ll, ll> pii;
pii operator-(const pii &a, const pii &b) { return {a.x - b.x, a.y - b.y}; }
ll cross(const pii &a, const pii &b) { return a.x * b.y - a.y * b.x; }
ll crzf(const pii &o, const pii &a, const pii &b) { return cross(a - o, b - o); }
ll dd(const pii &a, const pii &b) {
    ll dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

vector<pii> makepoly(vector<pii> &pp) {
    int n = pp.size();
    sort(pp.begin(), pp.end());
    vector<pii> ret;
    for (int i = 0; i < n; i++) {
        while (ret.size() >= 2 && crzf(ret[ret.size() - 2], ret.back(), pp[i]) <= 0) ret.pop_back();
        ret.push_back(pp[i]);
    }
    for (int i = n - 2, t = ret.size() + 1; i >= 0; i--) {
        while (ret.size() >= t && crzf(ret[ret.size() - 2], ret.back(), pp[i]) <= 0) ret.pop_back();
        ret.push_back(pp[i]);
    }
    if (n >= 2) ret.pop_back();
    return ret;
}

#define ii ((i + pts) % n)
#define kk1 ((k1 + 1) % n)
#define kk2 ((k2 + 1) % n)

ll area(vector<pii> &poly) {
    int n = poly.size();
    ll ans = 0;
    for (int pts = 2; pts < n - 1; pts++) {
        int k1 = 1, k2 = (pts + 1) % n;
        for (int i = 0; i < n; i++) {
            while (abs(crzf(poly[kk1], poly[i], poly[ii])) >= abs(crzf(poly[k1], poly[i], poly[ii])) && poly[kk1] != poly[ii])
                k1 = kk1;
            while (abs(crzf(poly[kk2], poly[i], poly[ii])) >= abs(crzf(poly[k2], poly[i], poly[ii])) && poly[kk2] != poly[ii])
                k2 = kk2;
            ans = max(ans, abs(crzf(poly[k1], poly[i], poly[ii])) + abs(crzf(poly[k2], poly[i], poly[ii])));
        }
    }
    return ans;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pii> pts(n);

        set<pii> s;
        set<pii> dul;
        for (int i = 0; i < n; i++) {
            cin >> pts[i].x >> pts[i].y;
            if (s.count(pts[i]))
                dul.insert(pts[i]);
            else
                s.insert(pts[i]);
        }

        vector<pii> distinct_points(s.begin(), s.end());
        auto poly = makepoly(distinct_points);

        if (poly.size() < 3) {
            printf("0\n");
            continue;
        }
        if (poly.size() > 3) {
            printf("%g\n", double(area(poly)) / 2);
            continue;
        }
        ll ans = 0, tri = abs(crzf(poly[0], poly[1], poly[2]));
        for (auto &p : pts)
            if (p != poly[0] && p != poly[1] && p != poly[2]) {
                ans = max(ans, tri - abs(crzf(p, poly[0], poly[1])));
                ans = max(ans, tri - abs(crzf(p, poly[1], poly[2])));
            }
        for (auto &p : dul) {
            ans = max(ans, tri - abs(crzf(p, poly[0], poly[1])));
            ans = max(ans, tri - abs(crzf(p, poly[1], poly[2])));
            ans = max(ans, tri - abs(crzf(p, poly[2], poly[0])));
        }
        printf("%g\n", double(ans) / 2);
    }
    return 0;
}
/*
7
5
0 0
1 0
3 1
1 2
0 1
4
0 0
4 0
0 4
1 1
4
0 0
1 1
2 2
1 1
8
0 0
0 0
5 0
5 0
3 8
3 8
0 2
0 2
4
0 0
0 0
0 0
0 0
4
0 0
4 0
0 4
1 2
4
0 0
1 0
0 1
3 2

*/
