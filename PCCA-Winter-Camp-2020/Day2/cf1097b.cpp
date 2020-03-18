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
    int mask = (1 << n) - 1;
    vector<int> degs;
    for (int i = 0; i < n; i++) {
        int deg;
        cin >> deg;
        degs.push_back(deg);
    }

    while (mask >= 0) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (((mask >> i) & 1) == 1)
                sum += degs[i];
            else
                sum -= degs[i];
        }
        if (sum % 360 == 0) {
            cout << "YES\n";
            return 0;
        }
        mask--;
    }

    cout << "NO\n";
    return 0;
}