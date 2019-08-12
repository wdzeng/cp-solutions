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
#define mss(a) memset(a, 1, sizeof(a))
#define mp(e, f) make_pair(e, f)

int solve() {
    string s;
    cin >> s;
    const int n = s.size();
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = s[i] - '0';

    for (int k = n; k > 1; k--) {
        for (int d = 0; d <= 9; d++) {
            vector<int> v = arr;
            list<int> inc;
            int diff = 0;
            int i;
            for (i = 0; i < n; i++) {
                if (i > k - 1) {
                    diff -= inc.front();
                    inc.pop_front();
                }
                v[i] += diff;
                // printf("[%d]=%d\n", i, v[i]);
                if (i <= n - k) {
                    inc.push_back(d - v[i]);
                    diff += inc.back();
                    v[i] += d - v[i];
                }
                // printf("%d\n", diff);
                // printf("[%d]=%d\n", i, v[i]);
                if ((v[i] - d) % 10 != 0) break;
            }
            if (i == n) return k;
        }
    }
    return 1;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    return 0;
}