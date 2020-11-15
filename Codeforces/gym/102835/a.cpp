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
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ok = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                int j = n / i;
                if (2 * i >= j) {
                    ok = 1;
                    break;
                }
            }
        }
        cout << ok << '\n';
    }

    return 0;
}