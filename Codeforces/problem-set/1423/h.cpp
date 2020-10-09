#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define xz(v) int(v.size())

const int N = 5e5 + 5, SQ = 750;
int p[N], z[N];
vector<pii> stk;

inline int par(int v) {
    return p[v] == v ? v : par(p[v]);
}

inline void join(int a, int b) {
    a = par(a), b = par(b);
    if (a == b) {
        stk.emplace_back(a, b);
        return;
    }
    if (z[a] < z[b]) swap(a, b);
    stk.emplace_back(a, b);
    z[a] += z[b];
    p[b] = a;
}

inline void undo() {
    int a, b;
    tie(a, b) = stk.back();
    stk.pop_back();
    if (a == b) return;
    z[a] -= z[b];
    p[b] = b;
}

int main() {
    for (int i = 0; i < N; i++) z[i] = 1, p[i] = i;
    cin.tie(0), ios::sync_with_stdio(0);
    int n, q, k;
    cin >> n >> q >> k;

    vector<pii> G;
    vector<int> pG = {0};
    vector<piii> req;

    while (q--) {
        int t;
        cin >> t;

        if (t == 3) {
            pG.push_back(G.size());
            continue;
        }

        if (t == 2) {
            int src;
            cin >> src;
            src--;
            int r = xz(G);
            int ed = max(0, xz(pG) - 1 - k + 1);
            int l = pG[ed];
            req.push_back({{l, r}, {xz(req), src}});
            continue;
        }

        int a, b;
        cin >> a >> b;
        a--, b--;
        G.emplace_back(a, b);
    }

    vector<piii> bks[SQ];
    vector<int> ans(req.size());
    for (auto& q : req) {
        int l, r, i, src;
        tie(i, src) = q.y;
        tie(l, r) = q.x;
        if (l / SQ != r / SQ) {
            bks[l / SQ].push_back(q);
            continue;
        }

        while (l < r) {
            auto e = G[l];
            join(e.x, e.y);
            l++;
        }
        ans[i] = z[par(src)];
        while (!stk.empty()) undo();
    }

    for (int i = 0; i < SQ; i++) {
        sort(all(bks[i]), [](const piii& a, const piii& b) { return a.x.y < b.x.y; });
        while (!stk.empty()) undo();

        const int BS = SQ * i + SQ;
        int curr = BS;
        for (auto& q : bks[i]) {
            int l, r, i, src;
            tie(l, r) = q.x;
            tie(i, src) = q.y;
            while (curr < r) {
                auto& e = G[curr];
                join(e.x, e.y);
                curr++;
            }
            int curl = BS;
            while (curl > l) {
                curl--;
                auto& e = G[curl];
                join(e.x, e.y);
            }

            ans[i] = z[par(src)];
            while (curl < BS) {
                undo();
                curl++;
            }
        }
    }

    for (auto& x : ans) cout << x << '\n';

    return 0;
}