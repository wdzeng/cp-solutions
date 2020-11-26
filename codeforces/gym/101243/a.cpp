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

int main() {
#ifndef hy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0), ios::sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    int z = a, o = 0;
    int ans = 0;
    while (z > 0 || o > 0) {
        if (z >= b)
            z -= b, o += b;
        else {
            o -= (b - z);
            o = max(o, 0);
            o += z;
            z = 0;
        }
        ans++;
    }
    cout << ans << endl;

    return 0;
}