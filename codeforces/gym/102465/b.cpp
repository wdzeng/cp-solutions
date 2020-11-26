#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifndef hy
#define endl '\n'
#endif

int main() {
#ifndef hy
    cin.tie(0), ios::sync_with_stdio(0);
#endif
    int n;
    cin >> n;
    vector<pii> vec;
    while (n--) {
        int l, r;
        cin >> l >> r;
        vec.push_back({l, r});
    }
    n = vec.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = n - 1;
        int x = vec[i].x, y = vec[i].y;
        while (l <= r) {
            int m = (l + r) >> 1;
            int h = m - i + 1;
            int w = min(vec[i].y, vec[m].y) - max(vec[m].x, vec[i].x) + 1;
            if (h > w)
                r = m - 1;
            else
                l = m + 1;
        }
        ans = max(ans, l - i);
    }
    cout << ans << endl;
    return 0;
}