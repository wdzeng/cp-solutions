#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

pair<ll, ll> calc(vector<pair<ll, ll>>& points) {
    ll ans = 0;
    ll ans2 = 0;
    unordered_map<ll, ll> tmap;
    unordered_map<ll, ll> tmap2;
    for (auto p : points) {
        tmap[p.y + p.x]++;
        tmap2[p.y - p.x]++;
        //cout << p.y + p.x << " " << p.y - p.x << endl;
    }

    for (auto t : tmap) {
        ans += t.y * (t.y - 1) / 2;
    }
    for (auto t : tmap2) {
        ans2 += t.y * (t.y - 1) / 2;
    }

    return {ans, ans2};
}

int main() {
    ll n;
    while (cin >> n) {
        vector<pii> v;
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            v.emplace_back(x, y);
        }
        auto a = calc(v);
        ll all = n * n;
        double ans = double(a.x + a.y) * 2 / all;
        printf("%.18lf\n", ans);
    }

    return 0;
}