#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
#define x first
#define y second
#define all(v) v.begin() + 1, v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

/** 普通線段樹，為了加速打字時間，所以只支援 1-based。 **/
/**
 * 把 df 設為:
 *   0     for 區間和/gcd/bit-or/bit-xor
 *   1     for 區間積/lcm
 *   9e18  for 區間最小值
 *   -9e18 for 區間最大值
 *   -1    for 區間 bit-and
 */
const int df = 0;
const int N = 3e5 + 10;  // maxn

vector<piii> vec;

#define ls i << 1  // 加速打字
#define rs i << 1 | 1
struct SegmentTree {
    int a[N << 2];
    inline int cal(int a, int b) {
        /**
         * 把回傳值設為對應的操作，例如 a+b 為區間和，還有像是
         * a*b, min(a,b), max(a,b), gcd(a,b), lcm(a,b),
         * a|b, a&b, a^b 等等。 */
        if (vec[a].x.y > vec[b].x.y)
            return a;
        else
            return b;
    }
    // 單點設值。外部呼叫的時候後三個參數不用填。注意只支援
    // 1-based ！
    int set(int q, int v, int i = 1, int l = 1, int r = N) {
        if (r < q || l > q) return a[i];
        if (l == r) return a[i] = v;
        int m = (l + r) >> 1;
        int lo = set(q, v, ls, l, m);
        int ro = set(q, v, rs, m + 1, r);
        return a[i] = cal(lo, ro);
    }
    // 查詢區間 [l, r] 總和
    // (或極值等等，看你怎麼寫)。外部呼叫的時
    // 候後三個參數不用填。注意只支援 1-based ！
    int query(int ql, int qr, int i = 1, int l = 1,
              int r = N) {
        if (r < ql || l > qr) return df;
        if (ql <= l && r <= qr) return a[i];
        int m = (l + r) >> 1;
        int lo = query(ql, qr, ls, l, m);
        int ro = query(ql, qr, rs, m + 1, r);
        return cal(lo, ro);
    }
    // 建立 size = N 的空線段樹，所有元素都是 0 。注意只支援
    // 1-based ！
    SegmentTree() { memset(a, 0, sizeof(a)); }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vec.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int a, h;
        cin >> a >> h;
        vec[i] = {{h, a}, i};
    }

    sort(all(vec));
    SegmentTree s;
    for (int i = 1; i <= n; i++) {
        s.set(i, i);
    }

    int ans = 0;
    pii ansi = {1, 2};
    for (int i = 1; i <= n; i++) {
        auto& p = vec[i];
        int hel = p.x.x;
        int att = p.x.y;
        piii f = {{att + 1, 0}, 0};
        auto a = lower_bound(all(vec), f);

        // cout << vec[i].y << ' ';

        if (a == vec.begin()) {
            // cout << 'x' << endl;
            continue;
        }

        a--;
        assert(att >= a->x.x);
        int tIndex = s.query(1, a->y);
        // cout << a->y << ' ' << tIndex << ' ' << flush;

        if (tIndex == i) {
            if (i == 1) {
                if (a->y == 1) {
                    // cout << endl;
                    continue;
                }
                tIndex = s.query(2, a->y);
            } else if (i == a->y) {
                tIndex = s.query(1, a->y - 1);
            } else {
                int index1 = s.query(1, tIndex - 1);
                int index2 = s.query(tIndex + 1, a->y);
                tIndex = (vec[index1].x.y > vec[index2].x.y) ? index1 : index2;
            }
        }

        assert(tIndex != i);
        // cout << vec[tIndex].x.y << ' ';
        int tAtt = vec[tIndex].x.y;
        int anz = tAtt;
        if (tAtt >= hel) anz += att;
        if (anz > ans) {
            ansi = {i, tIndex};
            ans = anz;
            // cout << '*';
        }
        // cout << endl;
    }
    cout << ans << '\n';
    cout << vec[ansi.x].y << ' ' << vec[ansi.y].y << '\n';
}
