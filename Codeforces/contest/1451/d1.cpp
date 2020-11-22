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
        ll d, k;
        cin >> d >> k;

        ll x2 = d * d / k / k / 2;
        ll x = floor(sqrt(x2));
        ll y2 = (d * d - x * x * k * k) / k / k;
        ll y = floor(sqrt(y2));
        if (abs(x - y) % 2 == 1) {
            cout << "Ashish" << endl;
        } else {
            cout << "Utkarsh" << endl;
        }
    }
    return 0;
}