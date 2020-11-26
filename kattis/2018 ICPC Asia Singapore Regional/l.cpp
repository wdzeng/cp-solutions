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

const int maxn = 2e6 + 10;
vector<int> ans(maxn, 1);

void init() {
    for (int i = 2; i < maxn; i++) {
        for (int v = i; v < maxn; v += i) ans[v]++;
    }
    vector<bool> prime(maxn, 1);
    for (int i = 2; i < maxn; i++) {
        if (!prime[i]) continue;
        ans[i]--;
        for (int v = i * 2; v < maxn; v += i) prime[v] = 0, ans[v]--;
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    init();
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }
    return 0;
}