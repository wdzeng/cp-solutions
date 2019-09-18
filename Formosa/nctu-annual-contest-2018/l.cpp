#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        int arr[3][3];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) cin >> arr[i][j];

        int aei = arr[0][0] * arr[1][1] * arr[2][2];
        int bfg = arr[0][1] * arr[1][2] * arr[2][0];
        int cdh = arr[0][2] * arr[1][0] * arr[2][1];
        int ceg = arr[0][2] * arr[1][1] * arr[2][0];
        int bdi = arr[0][1] * arr[1][0] * arr[2][2];
        int afh = arr[0][0] * arr[1][2] * arr[2][1];

        ll x = (ll)aei + bfg + cdh, y = (ll)ceg + bdi + afh;
        cout << x - y << ' ' << x + y << '\n';
    }
    return 0;
}