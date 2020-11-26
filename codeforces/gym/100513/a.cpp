#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int N = 2e5 + 10;
const int D = 1e5 + 5;
int p[N], sz[N];
vector<pair<pii, int>> k;
int ok = 1;
const int SQ = 350;

inline int par(int v) {
    return p[v] == v ? v : par(p[v]);
}

void join(int a, int b) {
    a = par(a), b = par(b);
    if (a == b) {
        k.push_back({{a, b}, ok});
        return;
    }
    if (sz[a] < sz[b]) swap(a, b);
    k.push_back({{a, b}, ok});
    sz[a] += sz[b];
    p[b] = a;
}

void undo() {
    auto u = k.back();
    k.pop_back();
    int a, b;
    tie(a, b) = u.x;
    ok = u.y;
    if (a == b) return;
    sz[a] -= sz[b];
    p[b] = b;
}

int main() {
    for (int i = 0; i < N; i++) p[i] = i, sz[i] = 1;

    cin.tie(0), ios::sync_with_stdio(0);
    int n, e, t;
    cin >> n >> e >> t;
    vector<pii> qar;
    vector<piii> req;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        qar.emplace_back(a, b);
    }

    vector<int> ans(t);
    vector<vector<piii>> bks(SQ);
    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        if (l / SQ != r / SQ) {
            req.push_back({{l, r}, i});
            continue;
        }
        while (l < r) {
            int a, b;
            tie(a, b) = qar[l];
            join(a, b + D);
            if (par(a) == par(a + D) or par(b) == par(b + D)) ok = 0;
            join(b, a + D);
            if (par(a) == par(a + D) or par(b) == par(b + D)) ok = 0;
            l++;
        }
        ans[i] = ok;
        while (!k.empty()) undo();
    }

    for (auto& q : req) {
        int index = q.x.x / SQ;
        bks[index].push_back(q);
    }

    for (int i = 0; i < SQ; i++) {
        while (!k.empty()) undo();
        const int BS = SQ * i + SQ;
        int cl = BS, cr = BS;
        sort(all(bks[i]), [](const piii& a, const piii& b) {
            if (a.x.y != b.x.y)
                return a.x.y < b.x.y;
            else
                return a.x.x < b.x.x;
        });
        for (auto& q : bks[i]) {
            int l, r;
            tie(l, r) = q.x;
            while (cr < r) {
                int a, b;
                tie(a, b) = qar[cr];
                join(a, b + D);
                if (par(a) == par(a + D) or par(b) == par(b + D)) ok = 0;
                join(b, a + D);
                if (par(a) == par(a + D) or par(b) == par(b + D)) ok = 0;
                cr++;
            }
            while (cl > l) {
                cl--;
                int a, b;
                tie(a, b) = qar[cl];
                join(a, b + D);
                if (par(a) == par(a + D) or par(b) == par(b + D)) ok = 0;
                join(b, a + D);
                if (par(a) == par(a + D) or par(b) == par(b + D)) ok = 0;
            }
            int c = q.y;
            ans[c] = ok;
            while (cl < BS) {
                undo();
                undo();
                cl++;
            }
        }
    }

    for (auto& a : ans) cout << (a ? "Possible" : "Impossible") << '\n';
    return 0;
}