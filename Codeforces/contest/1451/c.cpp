#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifndef hy
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#else
#define fastio()
#define debug(a) cout << #a << ": " << a << endl
#endif

int solve() {
    int n, k;
    string src, dst;
    cin >> n >> k >> src >> dst;
    vector<int> fa(128), fb(128);
    for (int c : src) fa[c]++;
    for (int c : dst) fb[c]++;
    for (int i = 'a'; i < 'z'; i++) {
        if (fa[i] < fb[i]) return 0;
        int diff = fa[i] - fb[i];
        if (diff % k) return 0;
        fa[i] -= diff, fa[i + 1] += diff;
    }
    return fa['z'] == fb['z'];
}

int main() {
    fastio();
    int q;
    cin >> q;
    while (q--) cout << (solve() ? "Yes" : "No") << endl;
    return 0;
}