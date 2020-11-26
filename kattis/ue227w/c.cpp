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
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

const int N = 18;
int val[1 << N];

int issame(int l, int r) {
    for (int i = l; i < (l + r) / 2; i++) {
        if (val[i] != val[i + (r - l) / 2]) return 0;
    }
    return 1;
}

int dfs(int l, int r) {
    auto mn = *min_element(val + l, val + r);
    auto mx = *max_element(val + l, val + r);
    if(mn == mx) return 1;
    return dfs(l, (l + r) / 2) + dfs((l + r) / 2, r) + 1;
}

int reverse(int n, int i) {
    int ret = 0;
    for (int x = 0; x < n; x++) {
        int j = (i & 1);
        ret = ret * 2 + j;
        i >>= 1;
    }
    return ret;
}

int main() {
    fastio();
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        cin >> val[reverse(n, i)];
    }
    cout << dfs(0, 1 << n) << endl;
    return 0;
}