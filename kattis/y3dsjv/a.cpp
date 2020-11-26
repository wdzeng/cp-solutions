#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> llll;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())




int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        ll n;
        cin >> n >> n;
        cout << i << ' ' << ((n+1) * (n + 2) / 2 - 1) << '\n';
    }

    return 0;
}