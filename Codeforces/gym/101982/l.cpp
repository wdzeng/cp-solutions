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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pii> v;
    while (n--) {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    int ans = -1;
    for (int t = 1; t <= v.size(); t++) {
        int cnt = 0;
        for (auto& r : v)
            if (r.x <= t && t <= r.y) cnt++;
        if (cnt == t) ans = t;
    }
    cout << ans << endl;

    return 0;
}