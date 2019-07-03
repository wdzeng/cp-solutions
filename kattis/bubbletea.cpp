#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    int tea[n + 1];
    for (int i = 1; i <= n; i++) cin >> tea[i];
    cin >> m;
    int top[m + 1];
    for (int i = 1; i <= m; i++) cin >> top[i];

    int x, k;
    int minn = __INT_MAX__;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        while (k--) {
            cin >> x;
            minn = min(minn, tea[i] + top[x]);
        }
    }

    int sum;
    int ans = 0;
    cin >> sum;
    cout << max(0, (sum / minn) -1 ) << endl;
    return 0;
}