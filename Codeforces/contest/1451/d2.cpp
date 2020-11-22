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

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        double d, k;
        cin >> d >> k;
        d /= k;
        ll x = floor(1e-8 + sqrt(d * d / 2));
        ll y = floor(1e-8 + sqrt(d * d - x * x));
        cout << (y == x ? "Utkarsh" : "Ashish") << endl;
    }
    return 0;
}