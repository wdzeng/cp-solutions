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
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<ll> vec;
        for (int i = 0; i < n; i++) {
            double d;
            cin >> d;
            vec.push_back(round(d * 1000));
        }
        ll l = vec[0], r = vec[0];
        int ok = 0;
        sort(all(vec));
        for (int i = 1; i < vec.size(); i++) {
            auto val = vec[i];
            if (l <= val && val <= r) {
                ok = 1;
                break;
            }
            l = min(l)
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}