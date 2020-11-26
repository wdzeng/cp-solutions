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

int upto(int t, int w, int r, int now) {
    if (now < t) return t;
    while (t + w < now) t += w + r;
    return t;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    vector<pii> me(10);
    for (auto& p : me) cin >> p.x >> p.y;
    vector<pii> other(10);
    vector<int> t(10);
    for (int i = 0; i < 10; i++) cin >> other[i].x >> other[i].y >> t[i];

    int x = 3;
    int ans = 0;
    while (x--) {
        for (int i = 0; i < 10; i++) {
            t[i] = upto(t[i], other[i].x, other[i].y, ans);
            int oo = t[i];
            if (ans < oo) {
                int end = ans + me[i].x;
                ans += me[i].x + me[i].y;
                t[i] = max(end, t[i]);
            }  //
            else {
                int end = oo + other[i].x;
                ans = end + me[i].x + me[i].y;
                t[i] = max(end + me[i].x, oo + other[i].x + other[i].y);
            }
        }
    }
    cout << ans - me[9].y << endl;

    return 0;
}