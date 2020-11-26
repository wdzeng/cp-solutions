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
    string str;
    cin >> str;
    vector<int> v = {0};
    for (char c : str) v.push_back(c == 'B' ? 1 : -1);
    int pl = 0, nl = 0;
    int px = 0, nx = 0;
    int s = 0;
    int maxdiff = -1;
    pii ans;
    for (int i = 1; i < zz(v); i++) {
        s += v[i];
        if (s > 0) {
            int diff = s - nx;
            if (diff > maxdiff)
                maxdiff = diff, ans = {nl + 1, i};
            else if (diff == maxdiff)
                ans = min(ans, {nl + 1, i});
            if(s > px) pl = i, px = s;
        } else {
            int diff = px - s;
            if (diff > maxdiff)
                maxdiff = diff, ans = {pl + 1, i};
            else if (diff == maxdiff)
                ans = min(ans, {pl + 1, i});
            if(s < nx) nl = i, nx = s;
        }
        // cout << i << ',' << s << "  " << pl << ' ' << nl << endl;
    }
    assert(maxdiff > 0);
    // cout << maxdiff << endl;
    cout << ans.x << ' ' << ans.y << endl;

    return 0;
}