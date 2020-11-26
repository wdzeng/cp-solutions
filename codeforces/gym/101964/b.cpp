#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef __int128_t lll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll a, b, c, n;
    cin >> a >> b >> c >> n;
    lll N = n;
    lll ans = (N * (N - 1) * (N - 2) / 6) - (((N - 1) / 2) * ((N - 1) / 2 - 1) / 2 * N);
    int s = unordered_set<ll>{a, b, c}.size();
    if (s == 2)
        ans *= 3;
    else if (s == 3)
        ans *= 6;
    cout << (ll)ans << endl;
    return 0;
}