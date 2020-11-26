#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int N = 1e3 + 5;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;

    pii ansp;
    ll minans = 1e9;
    for (int i = 0; i < n; i++) {
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] != '1') continue;
            ans = max(ans, abs(i - j));
        }
        for (int j = 0; j < n; j++) {
            if (b[j] != '1') continue;
            ans = max(ans, k + i + j + 2);
        }
        if (ans < minans) {
            minans = ans;
            ansp = {2, i};
        }
    }
    for (int i = 0; i < n; i++) {
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (b[j] != '1') continue;
            ans = max(ans, abs(i - j));
        }
        for (int j = 0; j < n; j++) {
            if (a[j] != '1') continue;
            ans = max(ans, k + i + j + 2);
        }
        if (ans < minans) {
            minans = ans;
            ansp = {1, i};
        }
    }

    cout << minans << endl;
    cout << ansp.x << ' ' << ansp.y + 1 << endl;

    return 0;
}