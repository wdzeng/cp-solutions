#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> piii;
typedef bitset<1000> B;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

vector<B> ss;
unordered_map<B, int> rec;
void dfs1(int i, const B& b, int step) {
    if (i == zz(ss) * 2 / 3) {
        if (rec.count(b))
            rec[b] = min(rec[b], step);
        else
            rec[b] = step;
        return;
    }
    dfs1(i + 1, b ^ ss[i], step + 1);
    dfs1(i + 1, b, step);
}
int dfs2(int i, const B& b, int step) {
    if (i == zz(ss)) return rec.count(b) ? (step + rec[b]) : 100;
    return min(dfs2(i + 1, b ^ ss[i], step + 1),
               dfs2(i + 1, b, step));
}
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        B s = 0;
        while (t--) {
            int a;
            cin >> a;
            a--;
            s.set(a);
        }
        ss.push_back(s);
    }
    dfs1(0, {}, 0);

    while (q--) {
        B b;
        int t;
        cin >> t;
        while (t--) {
            int a;
            cin >> a;
            a--;
            b.set(a);
        }
        int ans = dfs2(zz(ss) * 2 / 3, b, 0);
        cout << (ans == 100 ? -1 : ans) << '\n';
    }
    return 0;
}