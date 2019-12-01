#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
const double PII = 2 * PI;
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)
 
typedef pair<double, double> pdd;
 
bool in_range(pdd a, double u) {
    if (a.x < a.y)
        return a.x <= u && u <= a.y;
    else
        return a.x <= u || u <= a.y;
}
 
bool merge_angle(pdd& a, pdd u) {
    bool xin = in_range(a, u.x), yin = in_range(a, u.y);
    if (xin && yin)
        a = u;
    else if (xin && !yin)
        a.x = u.x;
    else if (!xin && yin)
        a.y = u.y;
    else {
        if (in_range(u, a.x))
            assert(in_range(u, a.y));
        else
            return false;
    }
    return true;
}
 
struct angle {
    bool first = true;
    bool foul = false;
    pdd a = {0, 0};
 
    angle() {}
    void merge(pdd u) {
        if (foul) {
            return;
        }
        if (first) {
            first = false;
            a = u;
            return;
        }
        foul = !merge_angle(a, u);
    }
    bool in(double u) {
        if (first) return true;
        if (foul) return false;
        return in_range(a, u);
    }
};
 
int N;
double D;
vector<pdd> loc;
vector<vector<int>> adj;
 
pdd to_range(pdd src, pdd dst) {
    double a = atan2(dst.y - src.y, dst.x - src.x);
    double diff = asin(D / hypot(dst.x - src.x, dst.y - src.y));
    return {remainder(a - diff, PII), remainder(a + diff, PII)};
}
 
int bfs() {
    queue<pii> q;
    q.push({0, 0});
    bool vis[N];
    ms(vis);
    vis[0] = 1;
 
    while (!q.empty()) {
        int u = q.front().y;
        int d = q.front().x;
        q.pop();
        if (u == N - 1) return d;
        for (int e : adj[u]) {
            if (vis[e]) continue;
            vis[e] = 1;
            q.push({d + 1, e});
        }
    }
    assert(false);
}
 
int main() {
    freopen("kingdom.in", "r", stdin);
    freopen("kingdom.out", "w", stdout);
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        pdd p;
        cin >> p.x >> p.y;
        loc.push_back(p);
    }
 
    bool good[N][N];
    ms(good);
 
    for (int i = 0; i < N; i++) {
        angle a;
        for (int j = i + 1; j < N; j++) {
            if (a.in(atan2(loc[j].y - loc[i].y, loc[j].x - loc[i].x))) {
                good[i][j] = 1;
            }
            if (hypot(loc[j].x - loc[i].x, loc[j].y - loc[i].y) > D) {
                auto r = to_range(loc[i], loc[j]);
                a.merge(r);
            }
        }
        angle b;
        for (int j = i - 1; j > -1; j--) {
            if (b.in(atan2(loc[j].y - loc[i].y, loc[j].x - loc[i].x))) {
                good[i][j] = 1;
            }
            if (hypot(loc[j].x - loc[i].x, loc[j].y - loc[i].y) > D) {
                auto r = to_range(loc[i], loc[j]);
                b.merge(r);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        vector<int> e;
        for (int j = i + 1; j < N; j++) {
            if (good[i][j] && good[j][i]) {
                e.push_back(j);
            }
        }
        adj.push_back(e);
    }
 
    cout << bfs() + 1 << endl;
    return 0;
}