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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<int> row, col;
        while (R--) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        while (C--) {
            int x;
            cin >> x;
            col.push_back(x);
        }
        sort(all(row));
        sort(all(col));
        int ans = 0;
        for (int i = 0; i < 16; i++) {
            vector<int> rm, cm;
            for (int x = 0; x < 4; x++) {
                if ((i >> x) & 1) {
                    rm.push_back(x / 2 % 2);
                    cm.push_back(x % 2);
                }
            }
            sort(all(rm));
            sort(all(cm));
            rm.erase(unique(all(rm)), rm.end());
            cm.erase(unique(all(cm)), cm.end());
            if (rm == row and cm == col) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}