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

ll judge(ll x) {
    string s = to_string(x);
    ll ans = 0;
    for (int c : s) ans += (ll)(c - '0') * (c - '0');
    return ans;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (int i = 0; i < 1000000; i++) {
        ll x = judge(n);
        if (x == 1) {
            cout << "HAPPY\n";
            return 0;
        }
        n = x;
    }
    cout << "UNHAPPY\n";
    return 0;
}