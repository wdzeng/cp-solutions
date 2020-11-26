#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

int a, b, p, seedl, seedr, nroll, target;

void solve() {
    cin >> nroll >> target >> seedl >> seedr >> a >> b >> p;
    int vis[p];
    mss(vis);
    vis[target] = 0;

    for (int s = seedl; s <= seedr; s++) {
        ll h = -1;
        list<ll> tested;
        int counter = 0;
        while ((h == -1 || vis[h] == -1) && counter < nroll) {
            if (h != -1) vis[h] = -2;
            h = h == -1 ? s : ((h * a + b) % p);
            tested.push_back(h);
            counter++;
        }
        if (vis[h] == -1) vis[h] = -2;
        if (vis[h] == -2) continue;
        counter = vis[h];
        // cout << s << " " << h << endl;
        while (!tested.empty() && counter < nroll) {
            vis[tested.back()] = counter++;
            tested.pop_back();
        }
    }

    // for (int i = 0; i < p; i++) printf("%d ", vis[i]);
    // printf("\n");

    int bingo = 0;
    for (int i = seedl; i <= seedr; i++)
        if (0 <= vis[i] && vis[i] < nroll) bingo++;
    int len = seedr - seedl + 1;
    int g = __gcd(len, bingo);
    printf("%d/%d\n", bingo / g, len / g);
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}