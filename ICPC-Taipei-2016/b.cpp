#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
typedef pair<ll, ll> pii;
const ll inf = 1e18;

// helper functions ，照抄
ll dd(pii& a, pii& b) {  // 回傳距離平方避免精度遺失
    ll dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}
ll dac(vector<pii>& p, int l, int r) {
    if (l >= r) return inf;
    int m = (l + r) / 2;
    ll d = min(dac(p, l, m), dac(p, m + 1, r));
    vector<pii> t;
    for (int i = m; i >= l && p[m].x - p[i].x < d; i--) t.push_back(p[i]);
    for (int i = m + 1; i <= r && p[i].x - p[m].x < d; i++) t.push_back(p[i]);
    sort(t.begin(), t.end(), [](pii& a, pii& b) { return a.y < b.y; });
    int n = t.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 1; j < 4 && i + j < n; j++) d = min(d, dd(t[i], t[i + j]));  // 這裡可以知道是哪兩點是最小點對
    return d;
}

// 給一堆點，求最近點對的距離平方。注意 pp 會被 sort 。
ll closest_pair(vector<pii>& pp) {
    sort(pp.begin(), pp.end());
    return dac(pp, 0, pp.size() - 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pii> p;
        while (n--) {
            int x, y;
            cin >> x >> y;
            p.emplace_back(x, y);
        }
        printf("%.2f\n", floor(sqrt(closest_pair(p) * 10000)) / 100);
    }
    return 0;
}

/*
2
5
1 0
2 0
4 0
1 2
3 2
5
1 1
4 1
2 3
5 2
3 6
*/
