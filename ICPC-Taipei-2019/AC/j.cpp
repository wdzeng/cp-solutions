#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 15 + 2;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        int ans = m + 1;

        string EMPTY, FULL;
        for (int i = 0; i < n; i++) {
            EMPTY.push_back('0');
            FULL.push_back('1');
        }

        vector<string> s(m);
        for (int i = 0; i < m; i++) cin >> s[i];
        for (int i = 1; i < (1 << m); i++) {
            string t = EMPTY;
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    cnt++;
                    for (int k = 0; k < n; k++) t[k] = (t[k] == '1' || s[j][k] == '1') ? '1' : '0';
                }
            }
            if (t == FULL) ans = min(ans, cnt);
        }
        if (ans > m) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}
