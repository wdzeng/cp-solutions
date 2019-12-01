#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

void read(int& s) {
    s = 0;
    for (int i = 0; i < 9; i++) {
        int c;
        cin >> c;
        s = s * 10 + c;
    }
}

inline pii blank(int s) {
    for (int i = 0; i < 9; i++, s /= 10) {
        if (s % 10 == 0) {
            return mp(i / 3, i % 3);
        }
    }
    assert(false);
}

inline int at(int s, int x, int y) {
    int c = x * 3 + y;
    for (int i = 0; i < c; i++) s /= 10;
    return s % 10;
}

inline int setat(int s, int x, int y, int v) {
    int c = x * 3 + y;
    int m = 1;
    for (int i = 0; i < c; i++) m *= 10;
    int org = at(s, x, y);
    s -= org * m;
    s += m * v;
    return s;
}

const pii A = {2, 2};
const pii B = {2, 1};
const pii C = {2, 0};
const pii D = {1, 2};
const pii E = {1, 1};
const pii F = {1, 0};
const pii G = {0, 2};
const pii H = {0, 1};
const pii I = {0, 0};

vector<pii> adj(pii p) {
    if (p == A) return {B, I, G, D};
    if (p == B) return {C, A, H, E};
    if (p == C) return {D, B, I, F};
    if (p == D) return {E, C, A, G};
    if (p == E) return {F, D, B, H};
    if (p == F) return {G, E, C, I};
    if (p == G) return {H, F, D, A};
    if (p == H) return {I, G, E, B};
    if (p == I) return {A, H, F, C};
    assert(0);
}

void solve() {
    int hcost, vcost;
    cin >> hcost >> vcost;
    if (!hcost and !vcost) exit(0);

    int src, dst;
    read(src);
    read(dst);

    priority_queue<pii> q;
    q.emplace(0, src);
    unordered_set<int> vis;

    while (q.size()) {
        pii v = q.top();
        q.pop();
        const int orgcost = v.x;
        const int s = v.y;
        if (vis.count(s)) continue;
        if (s == dst) {
            cout << -orgcost << endl;
            return;
        }
        vis.insert(s);
        const pii b = blank(s);
        // cout << s << ' ' << b.x << ' ' << b.y << endl;

        auto test = [&](pii p, int cost) {
            int x = p.x, y = p.y;
            x = (x + 3) % 3;
            y = (y + 3) % 3;
            int d0 = at(s, x, y);
            int d1 = at(s, b.x, b.y);
            int u = setat(s, x, y, d1);
            u = setat(u, b.x, b.y, d0);

            if (!vis.count(u)) {
                q.emplace(orgcost - cost, u);
            }
        };

        auto a = adj(b);
        test(a[0], hcost);
        test(a[1], hcost);
        test(a[2], vcost);
        test(a[3], vcost);
    }
    assert(0);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    while (1) solve();
    return 0;
}
