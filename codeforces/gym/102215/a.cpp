#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int N = 5e5 + 10;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    vector<int> prev(N, -1);
    vector<int> vec(N, -1);
    vector<int> from(N, 0);
    int n;
    cin >> n;

    int lim = 0;
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
        if (vec[i] > 0) {
            int f = prev[vec[i]];
            if (f == -1) {
                from[i] = lim;
                continue;
            }
            lim = max(lim, f);
            from[i] = lim;
            continue;
        }
        from[i] = lim;
        prev[-vec[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            if (from[m] > i) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        int ff = l - 1;
        cout << ff - i << ' ';
    }
    cout << endl;
    return 0;
}