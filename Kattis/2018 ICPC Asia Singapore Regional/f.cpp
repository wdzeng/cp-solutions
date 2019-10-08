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
#define mp(E, f) make_pair(E, f)

class SegmentTree {
   private:
    static const int DF = INT_MAX;
    vector<ll> a;
    int n;

    inline ll cal(ll a, ll b) { return min(a, b); }
    ll set(int i, int curl, int curr, int tar, ll v) {
        if (curr < tar || curl > tar) return a[i];
        if (curl == curr) return a[i] = v;
        int m = (curl + curr) / 2;
        ll l = set(i * 2 + 1, curl, m, tar, v);
        ll r = set(i * 2 + 2, m + 1, curr, tar, v);
        return a[i] = cal(l, r);
    }
    ll query(int i, int curl, int curr, int tarl, int tarr) {
        if (curr < tarl || curl > tarr) return DF;
        if (tarl <= curl && curr <= tarr) return a[i];
        int m = (curl + curr) / 2;
        ll l = query(i * 2 + 1, curl, m, tarl, tarr);
        ll r = query(i * 2 + 2, m + 1, curr, tarl, tarr);
        return cal(l, r);
    }

   public:
    SegmentTree(int n) : n(n) { a.assign(n * 4, DF); }
    void set(int i, ll v) { set(0, 0, n - 1, i, v); }
    ll query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

struct E {
    int v, i;
    bool b;
    E(int v, int i, bool b) : v(v), i(i), b(b) {}
    bool operator<(const E& o) const { return i < o.i; }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> l(n, -1), r(n, -1);
    vector<vector<int>> idx(n);

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        val--;
        if (l[val] == -1)
            l[val] = i;
        else
            r[val] = i, idx[val].push_back(i);
    }

    vector<E> e;
    for (int i = 0; i < n; i++) {
        if (l[i] == -1) continue;
        if (r[i] == -1) continue;
        e.emplace_back(i, l[i], 1);
    }
    for (int i = 0; i < n; i++) {
        if (r[i] == -1) continue;
        e.emplace_back(i, r[i], 0);
    }

    sort(iter(e));
    SegmentTree b(n);
    pii ans = mp(INT_MAX, INT_MAX);
    for (auto& sg : e) {
        if (sg.b) {
            int rloc = r[sg.v];
            int mn = b.query(sg.i + 1, rloc - 1);
            pii cand = mp(mn, sg.v);
            ans = min(ans, cand);
            for (int loc : idx[sg.v]) b.set(loc, sg.v);
        } else {
            for (int loc : idx[sg.v]) b.set(loc, INT_MAX);
        }
    }

    if (ans.x == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans.x + 1 << ' ' << ans.y + 1 << endl;
    return 0;
}