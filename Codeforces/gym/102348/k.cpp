#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    cout << n * n * 3 / 4 << endl;
    for (int x = 1; x <= n; x += 2) {
        for (int y = 1; y <= n; y += 2) {
            printf("%d %d %d %d\n", 1, x, y + 1, 2);
            printf("%d %d %d %d\n", 1, x + 1, y, 2);
            printf("%d %d %d %d\n", 2, x, y, 1);
        }
    }

    return 0;
}