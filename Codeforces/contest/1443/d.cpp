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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> vec(n);
        for (auto& val : vec) cin >> val;
        ll inc = 0, dec = 1e18, ok = 1;
        for (auto val : vec) {
            if (val < inc) {
                ok = 0;
                break;
            }
            int nxtdec = val - inc;
            if (nxtdec > dec) {
                int nxtinc = val - dec;
                if (nxtinc < inc) {
                    ok = 0;
                    break;
                }
                inc = nxtinc;
            } else {
                dec = nxtdec;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}