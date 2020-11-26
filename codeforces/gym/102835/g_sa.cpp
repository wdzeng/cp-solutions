#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

// 卦長的 IS suffix array ，0-based only
// N = 字串最大長度 , A = 最大字元 ascii
// 複雜度 O(N+A)
const int N = 1e6 + 5;
const int A = 127;
const int NN = 3e6;
namespace SA {
const int N = NN;
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
void sais(const T s, int n, int* sa, int* bb, int* p, bool* t, int A) {
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

vector<int> adj[N];
int isring[N];
int vis[N];
int fa[N];

vector<int> findring(int src) {
    vector<pair<int, int>> stk;
    stk.push_back({src, -1});
    while (!stk.empty()) {
        int u, f;
        tie(u, f) = stk.back();
        stk.pop_back();
        if (vis[u]) continue;
        vis[u] = 1;
        fa[u] = f;
        for (int a : adj[u]) {
            if (a == f) continue;
            if (vis[a]) {
                int v = u;
                vector<int> ret;
                while (1) {
                    isring[v] = 1;
                    ret.push_back(v);
                    if (v == a) return ret;
                    v = fa[v];
                }
                assert(0);
            }
            stk.push_back({a, u});
        }
    }
    assert(0);
}

string treetok(int v, int p = -1) {
    vector<string> ch;
    for (int a : adj[v]) {
        if (a == p || isring[a]) continue;
        ch.push_back(treetok(a, v));
    }
    sort(all(ch));
    string ret = "<";
    for (auto& val : ch) ret += val;
    ret += ">";
    return ret;
}

string decktok0(const vector<string>& treetoks) {
    static char seq[NN];
    int pos = 0;
    for (auto& tt : treetoks) {
        seq[pos++] = '%';
        for (char c : tt) seq[pos++] = c;
    }
    for (auto& tt : treetoks) {
        seq[pos++] = '%';
        for (char c : tt) seq[pos++] = c;
    }
    seq[pos++] = '$';
    int hpos = (pos >> 1);
    SA::build(seq, pos);
    int startpos = -1;
    for (int i = 0; i < pos; i++) {
        if (SA::sa[i] < hpos) {
            startpos = SA::sa[i];
            break;
        }
    }
    assert(~startpos);
    assert(seq[startpos] == '%');
    string ret(seq + startpos, seq + startpos + hpos);
    return ret;
}

string decktok(vector<string>& treetoks) {
    string ret = decktok0(treetoks);
    reverse(all(treetoks));
    return min(ret, decktok0(treetoks));
}

void reset() {
    for (auto& vec : adj) vec.clear();
    ms(isring);
    ms(vis);
    ms(fa);
}

int solve() {
    reset();
    int D;
    cin >> D;
    int totdeclen = 0;
    vector<int> decloc, declen;
    for (int d = 0; d < D; d++) {
        int k;
        cin >> k;
        decloc.push_back(totdeclen);
        declen.push_back(k);
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            a += totdeclen;
            b += totdeclen;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        totdeclen += k;
    }

    unordered_set<string> ans;
    for (int d = 0; d < D; d++) {
        vector<int> ring = findring(decloc[d]);
        vector<string> ttoks;
        for (int i : ring) ttoks.push_back(treetok(i));
        ans.insert(decktok(ttoks));
    }
    cout << ans.size() << '\n';
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}