#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int, ll> s;
        while (n--) {
            ll val;
            cin >> val;
            ll c = 0;
            while (val % 2 == 0) {
                val >>= 1;
                c++;
            }
            s[val] = max(s[val], c);
        }
        int ans = 0;
        for (auto& p : s) ans += p.y;
        cout << ans << endl;
    }

    return 0;
}