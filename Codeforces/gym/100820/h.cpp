#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double, double> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

#define TOP_LEFT 1
#define TOP_RIGHT 3
#define BOTTOM_LEFT 0
#define BOTTOM_RIGHT 2

typedef pair<pii, string> point;

int getid(int src, int dst, int loc) {
    if (loc == src) return 0;
    if (loc == dst) return 3;
    if (loc + src == 3) return 2;
    return 1;
}

pair<int, int> nextdir(int src, int dst, int id) {
    const int D = src ^ dst;
    assert(D == 1 || D == 2);
    const int DP = D ^ 3;
    if (id == 0)
        return {src, src ^ DP};
    else if (id == 1)
        return {src, src ^ D};
    else if (id == 2)
        return {src, src ^ D};
    else
        return {3 - src, src ^ D};
}

void solve(int src, int dst, vector<point>& v) {
    if (v.size() <= 1) return;

    vector<point> groups[4];
    for (auto& a : v) {
        pii p = a.x;
        int right = p.x > 0.5;
        int top = p.y > 0.5;
        int loc = right * 2 + top;
        int gid = getid(src, dst, loc);
        assert(0 <= gid <= 3);

        if (right) p.x -= 0.5;
        if (top) p.y -= 0.5;
        groups[gid].push_back({{p.x * 2, p.y * 2}, a.y});
    }

    v.clear();
    for (int id = 0; id < 4; id++) {
        pair<int, int> nd = nextdir(src, dst, id);
        assert(nd.x ^ nd.y == 1 || nd.x ^ nd.y == 2);
        solve(nd.x, nd.y, groups[id]);
        v.insert(v.end(), all(groups[id]));
    }
}

int main() {
    int n;
    double s;
    cin >> n >> s;
    vector<point> v;
    while (n--) {
        double x, y;
        string name;
        cin >> x >> y >> name;
        x /= s, y /= s;
        v.push_back({{x, y}, name});
    }
    solve(0, 2, v);
    for (auto& a : v) cout << a.y << '\n';
}