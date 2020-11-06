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

int judge(ll n, ll x) {
    ll s = (n - 1) * n / 2;
    if (s % 2 == 0)
        s /= 2;
    else
        s = s / 2 + 1;
    ll s1 = (n + n - 1 - x) * x / 2;
    return s1 >= s;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    int l = 1, r = n;
    while (l <= r) {
        int x = (l + r) >> 1;
        if (judge(n, x))
            r = x - 1;
        else
            l = x + 1;
    }
    cout << l << endl;
    return 0;
}