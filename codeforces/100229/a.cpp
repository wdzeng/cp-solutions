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
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#define ass(a) assert(a)
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#define ass(a)
#endif

int X, Y;
vector<vector<int>> g;
void solve() {
    cin >> X >> Y;
    g.resize(X);
    for (int i = 0; i < X; i++) {
        auto& gg = g[i];
        gg.resize(Y);
        for (int j = 0; j < Y; j++) {
            cin >> gg[j];
        }
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}