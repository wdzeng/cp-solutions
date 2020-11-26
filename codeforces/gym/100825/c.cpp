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
    int n, m, tar;
    char op;
    cin >> n >> m >> tar >> op;
    vector<pii> g(m);

    for (auto& p : g) cin >> p.x >> p.y;

    if (op == '-') {
        assert(m == 2);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (i - j == tar) ans++;
                if (j - i == tar) ans++;
            }
        }
        cout << ans << endl;
        return 0;
    }

    if (op == '/') {
        assert(m == 2);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (tar * j == i) ans++;
                if (tar * i == j) ans++;
            }
        }
        cout << ans << endl;
        return 0;
    }

    

    return 0;
}