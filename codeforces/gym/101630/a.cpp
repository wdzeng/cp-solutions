#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifdef hy
#define fastio()
#define debug(a) cout << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

const int Q = 2e5 + 5;
const int N = Q * 2;
pii circles[Q];

int isin(pii& c, ll x, ll y) {
    ll dx = c.x - x, dy = c.y - y;
    return dx * dx + dy * dy < c.y * c.y;
}

namespace seg {

set<int> node[N << 2];

void insert(int l, int r, int id, int i = 0, int cl = 1, int cr = N) {
    if (cl >= r || cr <= l) return;
    if (l <= cl && cr <= r) {
        if (id < 0)
            node[i].erase(-id);
        else
            node[i].insert(id);
        return;
    }
    int m = (cl + cr) >> 1;
    insert(l, r, id, i * 2 + 1, cl, m);
    insert(l, r, id, i * 2 + 2, m, cr);
}

int query(int x, ll qx, ll qy, int i = 0, int cl = 1, int cr = N) {
    for (int cid : node[i]) {
        auto& c = circles[cid];
        if (isin(circles[cid], qx, qy)) return cid;
    }
    if (cl + 1 == cr) {
        return -1;
    }
    int m = (cl + cr) >> 1;
    if (cl <= x && x < m)
        return query(x, qx, qy, i * 2 + 1, cl, m);
    else
        return query(x, qx, qy, i * 2 + 2, m, cr);
}

};  // namespace seg

int main() {
    fastio();
    int q;
    cin >> q;
    vector<pair<int, pii>> qc;
    vector<ll> nums;
    while (q--) {
        int a;
        ll x, y;
        cin >> a >> x >> y;
        if (a == 2)
            nums.push_back(x);
        else
            nums.push_back(x - y), nums.push_back(x + y);
        qc.push_back({a, {x, y}});
    }
    nums.push_back(-1e18);  // index 0
    sort(all(nums));
    nums.erase(unique(all(nums)), nums.end());
    for (int id = 0; id < qc.size(); id++) {
        auto& qq = qc[id];
        if (qq.x == 1) {
            circles[id + 1] = {qq.y.x, qq.y.y};
            ll ql = qq.y.x - qq.y.y;
            ll qr = qq.y.x + qq.y.y;
            int l = lower_bound(all(nums), ql) - nums.begin();
            int r = lower_bound(all(nums), qr) - nums.begin();
            seg::insert(l, r, id + 1);
        }  //
        else {
            ll qx = qq.y.x;
            ll qy = qq.y.y;
            int sx = lower_bound(all(nums), qx) - nums.begin();
            int id = seg::query(sx, qx, qy);
            if (id == -1)
                cout << -1 << endl;
            else {
                cout << id << endl;
                ll cl = circles[id].x - circles[id].y;
                ll cr = circles[id].x + circles[id].y;
                int qcl = lower_bound(all(nums), cl) - nums.begin();
                int qcr = lower_bound(all(nums), cr) - nums.begin();
                seg::insert(qcl, qcr, -id);
            }
        }
    }
    return 0;
}