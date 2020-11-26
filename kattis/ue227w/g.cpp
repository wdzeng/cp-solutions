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
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

int main() {
    fastio();
    int n, k;
    cin >> n >> k;
    unordered_map<string, unordered_set<int>> m;
    unordered_map<string, int> up;
    for (int i = 0; i < k; i++) {
        int a, b;
        string sa, sb;
        cin >> a >> b >> sa >> sb;
        m[sa].insert(a);
        m[sb].insert(b);
        if (sa == sb) up[sa] = 1;
    }
    int cup = up.size();
    int k1 = 0;
    int k2 = 0;
    for (auto& p : m) {
        auto& pic = p.x;
        if (!up[pic]) {
            if (p.y.size() == 2)
                k2++;
            else if (p.y.size() == 1)
                k1++;
        }
    }
    int k0 = n / 2 - cup - k1 - k2;
    debug(k0);
    debug(k1);
    debug(k2);
    debug(cup);
    if (k0 == 0 || k0 == 1 && k1 == 0) {
        cout << n / 2 - cup << endl;
    }
    else {
        cout << k2 << endl;
    }
    return 0;
}