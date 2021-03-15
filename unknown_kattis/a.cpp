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

#define ls i << 1
#define rs i << 1 | 1
class RangeUpdateSegmentTree {
   private:
    struct node {
        int l, r, adt = 0, x = 0;
    };
    vector<node> a;  // 萬萬不可以用普通陣列，要用 vector
    void push(int i) {
        if (a[i].adt) {
            a[ls].adt += a[i].adt, a[rs].adt += a[i].adt;
            a[ls].x += a[i].adt, a[rs].x += a[i].adt;
            a[i].adt = 0;
        }
    }
    void pull(int i) {
        a[i].x = max(a[ls].x, a[rs].x);
    }
    void build(int l, int r, int i) {
        a[i].l = l, a[i].r = r;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(l, mid, ls), build(mid + 1, r, rs);
    }

   public:
    RangeUpdateSegmentTree(int n) : a(n << 2) {
        build(1, n, 1);
    }
    void add(int l, int r, ll val, int i = 1) {
        if (a[i].l >= l && a[i].r <= r) {
            a[i].x += val;
            a[i].adt += val;
            return;
        }
        push(i);
        int mid = (a[i].l + a[i].r) >> 1;
        if (l <= mid) add(l, r, val, ls);
        if (r > mid) add(l, r, val, rs);
        pull(i);
    }
    ll maxx(int l, int r, int i = 1) {
        if (l <= a[i].l && a[i].r <= r) return a[i].x;
        push(i);
        ll ret = -9e18;
        int mid = (a[i].l + a[i].r) >> 1;
        if (l <= mid) ret = max(ret, maxx(l, r, ls));
        if (r > mid) ret = max(ret, maxx(l, r, rs));
        pull(i);
        return ret;
    }
};

const int inf = 1e8;
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    assert(n <= 100000);
    vector<pii> range;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b > d) swap(b, d);
        range.emplace_back(b, -inf);
        range.emplace_back(d, b);
        nums.push_back(b);
        nums.push_back(d);
    }
    sort(all(nums));
    nums.erase(unique(all(nums)), nums.end());

    for (auto& r : range) {
        if (r.x != -inf) r.x = lower_bound(all(nums), r.x) - nums.begin() + 2;
        if (r.y != -inf) r.y = lower_bound(all(nums), r.y) - nums.begin() + 2;
    }

    sort(all(range));
    RangeUpdateSegmentTree st(200010);
    int ans = 0;
    int c = 0;
    for (auto& r : range) {
        assert(c >= 0);
        int close = r.y != -inf;
        if (close) {
            c--;
            st.add(r.y, r.x, 1);
            continue;
        }
        c++;
        int s = c + st.maxx(1, r.x - 1);
        ans = max(ans, s);
    }
    cout << ans << '\n';
    return 0;
}