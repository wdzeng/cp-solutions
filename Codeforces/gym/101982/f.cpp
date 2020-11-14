#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

const int N = 2e5 + 5;
ll seg[N];

struct node {
    bool rev = 0;
    ll elen, olen = 0;
} a[N << 2];

void update(int l, int r, int i = 1, int cl = 0, int cr = N) {
    if (a[i].rev) {
        a[i].rev = 0;
        swap(a[i].elen, a[i].olen);
        if (i * 2 < N * 4) {
            a[i * 2].rev = !a[i * 2].rev;
            a[i * 2 + 1].rev = !a[i * 2 + 1].rev;
        }
    }
    if (cl >= r || cr <= l) {
        return;
    }
    if (cl >= l && cr <= r) {
        if (i * 2 < N * 4) {
            a[i * 2].rev = !a[i * 2].rev;
            a[i * 2 + 1].rev = !a[i * 2 + 1].rev;
        }
        swap(a[i].elen, a[i].olen);
        // cout << "swap " << cl << ',' << cr << endl;
        // cout << "update range " << cl << ',' << cr << " to " << a[i].olen << "+" << a[i].elen << endl;
        return;
    }
    int cm = (cl + cr) >> 1;
    update(l, r, i * 2, cl, cm);
    update(l, r, i * 2 + 1, cm, cr);
    a[i].elen = a[i * 2].elen + a[i * 2 + 1].elen;
    a[i].olen = a[i * 2].olen + a[i * 2 + 1].olen;
    // cout << "update range " << cl << ',' << cr << " to " << a[i].olen << "+" << a[i].elen << endl;
}

ll build(int i = 1, int cl = 0, int cr = N) {
    if (cl + 1 == cr) {
        a[i].elen = seg[cl];
        return a[i].elen;
    }
    int cm = (cl + cr) >> 1;
    a[i].elen = build(i * 2, cl, cm) + build(i * 2 + 1, cm, cr);
    return a[i].elen;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    vector<ll> nums;
    int n;
    cin >> n;
    vector<pair<pii, pii>> task;
    while (n--) {
        pii p, q;
        cin >> p.x >> p.y >> q.x >> q.y;
        if (p.x > q.x) swap(p.x, q.x);
        if (p.y > q.y) swap(p.y, q.y);
        nums.push_back(p.y);
        nums.push_back(q.y);
        task.push_back({{p.x, 1}, {p.y, q.y}});
        task.push_back({{q.x, 0}, {p.y, q.y}});
    }
    sort(all(nums));
    nums.erase(unique(all(nums)), nums.end());
    for (int i = 0; i < nums.size() - 1; i++) seg[i] = nums[i + 1] - nums[i];
    build();

    ll prvx = 0;
    ll ans = 0;
    sort(all(task));
    for (auto& t : task) {
        auto x = t.x.x;
        auto l = t.y.x, r = t.y.y;
        l = lower_bound(all(nums), l) - nums.begin();
        r = lower_bound(all(nums), r) - nums.begin();
        // cout << a[1].olen << endl;
        ans += (x - prvx) * a[1].olen;
        // cout << "update" << l << ' ' << r << endl;
        update(l, r);
        prvx = x;
    }
    cout << ans << endl;
    return 0;
}