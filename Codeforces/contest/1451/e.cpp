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
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#else
#define fastio()
#define debug(a) cout << #a << ": " << a << endl
#endif

const int N = 1 << 16 + 5;
int xorv[N];
int ans[N];

int bitat(int x, int i) {
    return (x >> i) & 1;
}

int main() {
    fastio();
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        cout << "XOR 1 " << i << endl;
        cin >> xorv[i];
    }

    int a = -1;
    vector<int> m(1 << 16, -1);
    for (int i = 2; i <= n; i++) {
        if (!xorv[i]) {
            a = 1;
            cout << "AND " << 1 << ' ' << i << endl;
            cin >> ans[1];
            break;
        }
        if (~m[xorv[i]]) {
            a = i;
            cout << "AND " << m[xorv[i]] << ' ' << i << endl;
            cin >> ans[a];
            break;
        }
        m[xorv[i]] = i;
    }
    debug(a);

    if (a == -1) {
        a = 1;
        int b = find(xorv + 2, xorv + n + 1, n - 1) - xorv;
        assert(2 <= b && b <= n);
        int c = b == 2 ? 3 : 2;
        debug(b);
        debug(c);
        // a & b = 0
        int ab = 0, ac, bc;
        cout << "AND 1 " << c << endl;
        cin >> ac;
        cout << "AND " << b << ' ' << c << endl;
        cin >> bc;
        int axb = xorv[b], axc = xorv[c], bxc = xorv[b] ^ xorv[c];
        int apb = axb + 2 * ab;
        int apc = axc + 2 * ac;
        int bpc = bxc + 2 * bc;
        ans[a] = (apb + apc - bpc) / 2;
    }

    if (a != 1) ans[1] = ans[a] ^ xorv[a];
    cout << "! " << ans[1];
    for (int i = 2; i <= n; i++)
        cout << ' ' << (ans[1] ^ xorv[i]);
    cout << endl;
    return 0;
}