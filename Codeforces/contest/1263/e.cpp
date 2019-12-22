#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
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

#define ls i << 1
#define rs i << 1 | 1
const ll rr = 0x6891139;  // 亂數，若跟題目碰撞會吃 WA 或 RE
class RangeUpdateSegmentTree {
   private:
    struct node {
        int l, r, adt = 0, stt = rr;
        ll s = 0, x = 0;
    };
    vector<node> a;
    int n;
    inline void push(int i) {
        if (a[i].stt != rr) {
            a[ls].stt = a[rs].stt = a[i].stt;
            a[ls].adt = a[rs].adt = 0;
            a[ls].x = a[rs].x = a[i].stt;
            a[ls].s = (a[ls].r - a[ls].l + 1) * a[i].stt;
            a[rs].s = (a[rs].r - a[rs].l + 1) * a[i].stt;
            a[i].stt = rr;
        }
        if (a[i].adt) {
            a[ls].adt += a[i].adt, a[rs].adt += a[i].adt;
            a[ls].x += a[i].adt, a[rs].x += a[i].adt;
            a[ls].s += a[i].adt * (a[ls].r - a[ls].l + 1);
            a[rs].s += a[i].adt * (a[rs].r - a[rs].l + 1);
            a[i].adt = 0;
        }
    }
    inline void pull(int i) {
        a[i].s = a[ls].s + a[rs].s;
        a[i].x = max(a[ls].x, a[rs].x);
    }
    void build(int l, int r, int i) {
        a[i].l = l, a[i].r = r;
        if (l == r) return;
        int stt = (l + r) >> 1;
        build(l, stt, ls), build(stt + 1, r, rs);
    }

   public:
    RangeUpdateSegmentTree(int n) : n(n), a(n << 2) { build(1, n, 1); }
    void add(int l, int r, ll val, int i = 1) {
        if (a[i].l >= l && a[i].r <= r) {
            a[i].s += val * (a[i].r - a[i].l + 1);
            a[i].x += val;
            a[i].adt += val;
            return;
        }
        push(i);
        int stt = (a[i].l + a[i].r) >> 1;
        if (l <= stt) add(l, r, val, ls);
        if (r > stt) add(l, r, val, rs);
        pull(i);
    }
    ll maxx(int l, int r, int i = 1) {
        if (l <= a[i].l && a[i].r <= r) return a[i].x;
        push(i);
        ll ret = -9e18;
        int stt = (a[i].l + a[i].r) >> 1;
        if (l <= stt) ret = max(ret, maxx(l, r, ls));
        if (r > stt) ret = max(ret, maxx(l, r, rs));
        pull(i);
        return ret;
    }
    ll sum(int l, int r, int i = 1) {
        if (l <= a[i].l && a[i].r <= r) return a[i].s;
        push(i);
        ll ret = 0;
        int stt = (a[i].l + a[i].r) >> 1;
        if (l <= stt) ret += sum(l, r, ls);
        if (r > stt) ret += sum(l, r, rs);
        pull(i);
        return ret;
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;

    int index = 1;
    string input;
    RangeUpdateSegmentTree seg(n + 11);
    RangeUpdateSegmentTree minseg = seg;
    for (int i = 0; i < n + 10; i++) input.push_back(' ');

    int ans = 0;
    for (char c : s) {
        if (c == 'R')
            index++;
        else if (c == 'L')
            index = max(1, index - 1);
        else {
            if (c != '(' and c != ')') c = ' ';
            if (input[index] != c) {
                if (input[index] == '(') {
                    seg.add(index, n + 5, c == ')' ? -2 : -1);
                    minseg.add(index, n + 5, c == ')' ? 2 : 1);
                } else if (input[index] == ')') {
                    seg.add(index, n + 5, c == '(' ? 2 : 1);
                    minseg.add(index, n + 5, c == '(' ? -2 : -1);
                } else if (c == '(') {
                    seg.add(index, n + 5, 1);
                    minseg.add(index, n + 5, -1);
                } else if (c == ')') {
                    seg.add(index, n + 5, -1);
                    minseg.add(index, n + 5, 1);
                }
                if (seg.sum(n + 5, n + 5) == 0 and minseg.maxx(1, n + 5) == 0)
                    ans = seg.maxx(1, n + 5);
                else
                    ans = -1;
            }
            input[index] = c;
        }
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}
