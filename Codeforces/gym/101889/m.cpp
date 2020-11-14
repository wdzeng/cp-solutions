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

const int N = 5e5 + 5;
const int V = 1e5 + 5;
const int A = 310;
const int M = 1e9 + 7;
const int D = 365;

namespace SA {

#define pushS(x) sa[--b[s[x]]] = x
#define pushL(x) sa[b[s[x]]++] = x
#define induce_sort(v)                                    \
    {                                                     \
        fill_n(sa, n, 0);                                 \
        copy_n(bb, A, b);                                 \
        for (i = n1 - 1; ~i; --i) pushS(v[i]);            \
        copy_n(bb, A - 1, b + 1);                         \
        for (i = 0; i < n; ++i)                           \
            if (sa[i] && !t[sa[i] - 1]) pushL(sa[i] - 1); \
        copy_n(bb, A, b);                                 \
        for (i = n - 1; ~i; --i)                          \
            if (sa[i] && t[sa[i] - 1]) pushS(sa[i] - 1);  \
    }

template <typename T>
void sais(const T s, int n, int *sa, int *bb, int *p, bool *t, int A) {
    int *r = p + n, *s1 = p + n / 2, *b = bb + A;
    int n1 = 0, i, j, x = t[n - 1] = 1, y = r[0] = -1, cnt = -1;
    for (i = n - 2; ~i; --i) t[i] = (s[i] == s[i + 1] ? t[i + 1] : s[i] < s[i + 1]);
    for (i = 1; i < n; ++i) r[i] = t[i] && !t[i - 1] ? (p[n1] = i, n1++) : -1;
    fill_n(bb, A, 0);
    for (i = 0; i < n; ++i) ++bb[s[i]];
    for (i = 1; i < A; ++i) bb[i] += bb[i - 1];
    induce_sort(p);
    for (i = 0; i < n; ++i)
        if (~(x = r[sa[i]]))
            j = y < 0 || memcmp(s + p[x], s + p[y], (p[x + 1] - p[x]) * sizeof(s[0])), s1[y = x] = cnt += j;
    if (cnt + 1 < n1)
        sais(s1, n1, sa, b, r, t + n, cnt + 1);
    else
        for (i = 0; i < n1; ++i) sa[s1[i]] = i;
    for (i = 0; i < n1; ++i) s1[i] = p[sa[i]];
    induce_sort(s1);
}

int sa[N];
int b[N + A], p[N * 2];
bool t[N * 2];

// 計算 suffix array ，字串須為 char[] 或 int[]， 不可為 string 或 vector
// s = 字串
// n = 字串長度(含$)
// 結果存在 SA::sa
template <typename T>
void build(const T s, int n) { sais(s, n, sa, b, p, t, A); }

}  // namespace SA

vector<int> v[V], vr[V];
int STR[N];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x--) {
            int a;
            cin >> a;
            assert(1 <= a && a <= 300);
            v[i].push_back(a);
            vr[i].push_back(0);
        }
    }

    vector<pii> SRC;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < zz(v[i]); j++) {
            STR[cnt++] = v[i][j];
            SRC.emplace_back(i, j);
        }
        STR[cnt++] = 301;
        SRC.emplace_back(-1, -1);
    }
    STR[cnt++] = 0;
    SA::build(STR, cnt);

    for (int i = 0; i < cnt; i++) {
        int loc = SA::sa[i];
        if (STR[loc] == 0 || STR[loc] == 301) continue;
        auto &src = SRC[loc];
        vr[src.x][src.y] = i;
    }

    typedef pair<int, pii> piii;
    priority_queue<piii, vector<piii>, greater<piii>> q;
    for (int i = 0; i < n; i++) reverse(all(vr[i])), reverse(all(v[i]));
    for (int i = 0; i < n; i++) q.push({vr[i].back(), {v[i].back(), i}}), v[i].pop_back(), vr[i].pop_back();

    ll ans = 0;
    while (!q.empty()) {
        auto u = q.top();
        q.pop();
        int val = u.y.x, src = u.y.y;
        ans += val;
        ans *= D;
        ans %= M;
        if (!v[src].empty()) q.push({vr[src].back(), {v[src].back(), src}}), v[src].pop_back(), vr[src].pop_back();
    }
    cout << ans << endl;
    return 0;
}