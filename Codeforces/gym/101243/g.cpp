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
    int cnt = 0;
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i % i == 0) {
                cout << "NO\n";
                return 0;
            }
            if (++cnt > 3) {
                cout << "NO\n";
                return 0;
            }
            n /= i;
        }
    }
    if (n > 1) cnt++;
    cout << (cnt == 3 ? "YES" : "NO") << endl;
    return 0;
}