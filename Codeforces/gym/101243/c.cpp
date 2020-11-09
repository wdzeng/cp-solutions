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

vector<pii> ans;
void solve(int X, int Y) {
    if (X == 1 || Y == 1) return;

    if (X == 2) {
        for (int i = 1; i <= Y - 1; i++) ans.emplace_back(1, i);
    } else if (Y == 2) {
        solve(Y, X);
        for (auto& a : ans) swap(a.x, a.y);
    } else if (X % 2 == 0) {
        for (int i = 1; i <= X - 1; i += 2) {
            for (int j = 1; j <= Y - 2; j++) ans.emplace_back(i, j);
        }
        for (int i = 1; i <= X - 1; i++) ans.emplace_back(i, Y - 1);
    } else if (Y % 2 == 0) {
        solve(Y, X);
        for (auto& a : ans) swap(a.x, a.y);
    } else {
        for (int i = 1; i <= Y - 2; i += 2) {
            ans.emplace_back(X - 1, i);
        }
        solve(X - 1, Y);
    }
}

int main() {
#ifndef hy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0), ios::sync_with_stdio(0);
    int h, w;
    cin >> h >> w;
    solve(h, w);
    cout << ans.size() << '\n';
    for (auto& a : ans) cout << a.x << ' ' << a.y << '\n';

    return 0;
}