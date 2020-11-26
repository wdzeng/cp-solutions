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
    string s;
    cin >> s;
    int l = 0, r = 0, u = 0, d = 0;
    int x = 0, y = 0;
    s = "  " + s;
    vector<pii> ans;
    vector<pii> path = {{0, 0}};
    for (int i = 2; i < s.size(); i++) {
        char c = s[i];
        if (c == 'L') {
            if (s[i - 1] == 'R' && s[i - 2] == 'L') {
                x = l + 1;
            }  //
            else {
                l -= 2;
                x = l + 1;
                ans.push_back({l, y});
            }
        } else if (c == 'R') {
            if (s[i - 1] == 'L' && s[i - 2] == 'R') {
                x = r - 1;
            }  //
            else {
                r += 2;
                x = r - 1;
                ans.push_back({r, y});
            }
        } else if (c == 'U') {
            if (s[i - 1] == 'D' && s[i - 2] == 'U') {
                y = u - 1;
            }  //
            else {
                u += 2;
                y = u - 1;
                ans.push_back({x, u});
            }
        } else if (c == 'D') {
            if (s[i - 1] == 'U' && s[i - 2] == 'D') {
                y = d + 1;
            }  //
            else {
                d -= 2;
                y = d + 1;
                ans.push_back({x, d});
            }
        }
        path.emplace_back(x, y);
    }

    for (pii& p : path) p.x -= x, p.y -= y;
    for (int i = 1; i < path.size() - 1; i++) {
        pii prv = path[i - 1], now = path[i];
        if (prv.x == 0 && now.x == 0) {
            if (prv.y * now.y <= 0) {
                cout << "impossible" << endl;
                return 0;
            }
        }
        if (prv.y == 0 && now.y == 0) {
            if (prv.x * now.x <= 0) {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }
    cout << -x << ' ' << -y << '\n';
    cout << ans.size() << '\n';
    for (auto& p : ans) {
        cout << p.x - x << ' ' << p.y - y << '\n';
    }

    return 0;
}