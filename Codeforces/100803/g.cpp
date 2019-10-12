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

/**
 * Support single element setting and range query.
 *
 * Time Complexity: O(QlogN)
 * Space Complexity: O(N)
 */
class SegmentTree {
    vector<ll> a, px;
    int n;

    ll set(int i, int curl, int curr, int tar, ll v) {
        if (curr < tar || curl > tar) return a[i];
        if (curl == curr) return a[i] = px[i] = v;
        int m = (curl + curr) / 2;
        ll l = set(i * 2 + 1, curl, m, tar, v);
        ll r = set(i * 2 + 2, m + 1, curr, tar, v);
        px[i] = min(px[i * 2 + 1], px[i * 2 + 2] + a[i * 2 + 1]);
        return a[i] = l + r;
    }
    ll query(int i, int l, int r, ll sum) {
        if (l == r) return l;
        int m = (l + r) / 2;
        if (sum + a[i * 2 + 1] + px[i * 2 + 2] >= 2) return query(i * 2 + 1, l, m, sum);
        return query(i * 2 + 2, m + 1, r, sum + a[i * 2 + 1]);
    }

   public:
    SegmentTree(int n) : n(n) { a.resize(n * 4), px.resize(n * 4); }
    void set(int i, ll v) { set(0, 0, n - 1, i, v); }
    ll query() { return query(0, 0, n - 1, 0); }
};

set<int> l, r;
string s;
SegmentTree st(0);

void open(int i) {
    r.erase(i);
    l.insert(i);
    s[i] = '(';
    st.set(i, 1);
}
void close(int i) {
    l.erase(i);
    r.insert(i);
    s[i] = ')';
    st.set(i, -1);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    cin >> s;
    st = SegmentTree(n);

    for (int i = 0; i < n; i++) {
        (s[i] == '(' ? l : r).insert(i);
        st.set(i, s[i] == '(' ? 1 : -1);
    }

    while (q--) {
        int i;
        cin >> i;
        i--;

        if (s[i] == '(') {
            close(i);
            int ans = *r.begin();
            ans = min(i, ans);
            cout << ans + 1 << '\n';
            open(ans);
        }       //
        else {  // == )
            open(i);
            int ans = st.query();
            ans++;
            cout << ans + 1 << '\n';
            close(ans);
        }
    }
    return 0;
}