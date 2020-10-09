#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int M = 1e9 + 7;
const int K = 5e8 + 4;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        x /= 2;
        x += 2;
        ll y = (x / 2) % M;
        ll ans;
        if (x % 2)
            ans = y * y + y;
        else
            ans = y * y;
        ans %= M;
        cout << ans << ' ';
    }
    cout << endl;

    return 0;
}