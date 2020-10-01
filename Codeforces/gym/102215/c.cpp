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
    ll p, n;
    cin >> p >> n;
    n = min(n, p);

    vector<bool> vis(p, false);
    vis[0] = 1;
    int loc = 0;
    for (int i = 1; i <= n; i++) {
        loc += i;
        loc %= p;
        vis[loc] = 1;
    }

    int c = 0;
    for (bool val : vis) c += val;
    cout << c << endl;

    return 0;
}