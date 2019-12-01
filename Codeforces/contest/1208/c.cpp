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
    int val[n][n];
    int c = 0;
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < n; j++) {
            val[i][j] = c++;
            val[i + 1][j] = c++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", val[i][j]);
        printf("\n");
    }
    return 0;
}