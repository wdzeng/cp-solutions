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
    int q;
    cin >> q;
    while (q--) {
        ll n;
        cin >> n;
        ll c = 1;
        bool nine = 1;
        while (c <= n) {
            c *= (nine ? 9 : 2);
            nine = !nine;
        }
        cout << (!nine ? "YES" : "NO") << endl;
    }

    return 0;
}