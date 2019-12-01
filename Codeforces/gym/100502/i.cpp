#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define x first
#define y second

inline ll a2(pii a, pii b, pii c) {  //
    return abs((c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x));
}

inline ll d2(pii a, pii b) {
    ll dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

void gcd(pii& p) {
    if (p.x < 0) p.x = -p.x, p.y = -p.y;
    int g = __gcd(p.x, p.y);
    p.x /= g, p.y /= g;
}

int main() {
    int n;
    cin >> n;
    map<pii, vector<pii>> mmap;
    int x1, y1, x2, y2;
    while (n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            mmap[{0, 1}].emplace_back(x1, y1);
        } else if (y1 == y2) {
            mmap[{1, 0}].emplace_back(x1, y1);
        } else {
            pii m = {x2-x1, y2-y1};
            gcd(m);
            mmap[m].emplace_back(x1, y1);
        }
    }

    ll ans = 0;
    for (auto& p : mmap) {
        if (p.first.y <= 0) continue;

        auto m = p.first;
        auto& vec = p.second;
        map<pii, int> rec1;
        for (int i = 0; i < vec.size(); i++) {
            for (int j = i + 1; j < vec.size(); j++) {
                pii p1 = vec[i], p2 = {p1.x + m.x, p1.y + m.y}, p3 = vec[j];
                ll area = a2(p1, p2, p3);
                ll dist = d2(p1, p2);
                pii len = {area, dist};
                gcd(len);
                rec1[len]++;
            }
        }
      //  for(auto p: rec1) printf("(%lld,%lld)=%d ", p.first.x, p.first.y, p.second); cout << endl;


        pii mm = {m.y, -m.x};
        map<pii, int> rec2;
        vec = mmap[mm];
        for (int i = 0; i < vec.size(); i++) {
            for (int j = i + 1; j < vec.size(); j++) {
                pii p1 = vec[i], p2 = {p1.x + mm.x, p1.y + mm.y}, p3 = vec[j];
                ll area = a2(p1, p2, p3);
                ll dist = d2(p1, p2);
                pii len = {area, dist};
                gcd(len);
                rec2[len]++;
            }
        }
       // for(auto p: rec2) printf("(%lld,%lld)=%d ", p.first.x, p.first.y, p.second); cout << endl;

        for(auto& p: rec1) {
            auto d = p.first;
            ll c1 = p.second;
            ll c2 = rec2[d];
            ans += c1 * c2; 
        }
    }

    cout << ans << endl;
    return 0;
}