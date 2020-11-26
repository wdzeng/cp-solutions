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

const int N = 100;
int f[N], a[N], b[N], c[N];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    f[0] = 1;
    // f[1] = 2, a[1] = 2, b[2] = 1, c[2] = 0;
    // f[2] = 11, a[1] = 16, b[2] = 8, c[2] = 4;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; i - j >= 0; j++) {
            int s = i - j;
            if (j == 1)
                f[i] += f[s] * 2, a[i] += f[s] * 2 + a[s] * 2, b[i] += f[s] * 1 + b[s] * 2, c[i] += f[s] * 0 + c[s] * 2;
            else if (j == 2)
                f[i] += f[s] * 7, a[i] += f[s] * 8 + a[s] * 7, b[i] += f[s] * 4 + b[s] * 7, c[i] += f[s] * 4 + c[s] * 7;
            else if (j % 2 == 1) {
                int x = (j - 3) / 2;
                f[i] += f[s] * 8, a[i] += f[s] * 8 + a[s] * 8, b[i] += f[s] * (16 * x + 8) + b[s] * 8, c[i] += f[s] * 8 +  c[s] * 8;
            } else {
                int x = (j - 4) / 2;
                f[i] += f[s] * 8, a[i] += f[s] * 8 + a[s] * 8, b[i] += f[s] * (16 * x + 16) + b[s] * 8, c[i] += f[s] * 8 +  c[s] * 8;
            }
        }
    }
    cout << f[n] << ' ' << a[n] << ' ' << b[n] << ' ' << c[n] << endl;
    return 0;
}