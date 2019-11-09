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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    int q;
    cin >> n >> q;
    bool r[n], c[n];
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        r[i] = v % 2;
    }
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        c[i] = v % 2;
    }

    int rid[n], cid[n];
    rid[0] = cid[0] = 0;
    for (int i = 1; i < n; i++) {
        rid[i] = rid[i - 1] + 1 - (r[i] == r[i - 1]);
        cid[i] = cid[i - 1] + 1 - (c[i] == c[i - 1]);
    }

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        if(rid[a] == rid[c] && cid[b] == cid[d]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
