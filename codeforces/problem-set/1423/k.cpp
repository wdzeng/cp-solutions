#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int N = 1e6 + 10;
int isp[N];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    memset(isp, 1, sizeof(isp));
    vector<int> p;
    for (int i = 2; i < N; i++) {
        if (!isp[i]) continue;
        p.push_back(i);
        for (int j = i + i; j < N; j += i) isp[j] = 0;
    }

    vector<int> ans = {0};
    for (int i = 1; i < N; i++) {
        int q = floor(sqrt(i));
        int inc = upper_bound(all(p), i) - p.begin();
        int exc = upper_bound(all(p), q) - p.begin();
        ans.push_back(inc - exc);
    }

    int q;
    cin >> q;
    while (q--) {
        int r;
        cin >> r;
        cout << ans[r] + 1 << '\n';
    }
    return 0;
}