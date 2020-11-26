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

const int N = 2e5 + 5;
int ans[N];
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, l;
    cin >> n >> m >> l;
    vector<pii> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y > l) continue;
        int d = x - y;
        v.emplace_back(x - l + y, -2);
        v.emplace_back(x + l - y + 1, -1);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        v.emplace_back(x, i);
    }
    sort(all(v));
    int cnt = 0;
    for (auto& u : v) {
        if (u.y == -2)
            cnt++;
        else if (u.y == -1)
            cnt--;
        else
            ans[u.y] = cnt;
    }
    assert(!cnt);
    for (int i = 0; i < m; i++) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}