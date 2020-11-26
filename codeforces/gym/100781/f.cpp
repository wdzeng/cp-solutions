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

int dpr[105][10005], dpl[105][10005];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int f;
    cin >> f;
    while (f--) {
        ms(dpl), ms(dpr);
        int len, m;
        cin >> len >> m;
        vector<int> R;
        while (m--) {
            int l, r;
            cin >> l >> r;
            R.push_back(r - l);
        }
        for (int i = 0; i <= len; i++) dpr[0][i] = dpl[0][i] = 1;
        for (int i = 0; i < R.size(); i++) {
            int x = R[i];
            for (int loc = 0; loc + x <= len; loc++) {
                if (dpr[i][loc]) dpl[i + 1][loc + x] = dpr[i + 1][loc + x] = 1;
            }
            for (int loc = len; loc - x >= 0; loc--) {
                if (dpl[i][loc]) dpl[i + 1][loc - x] = dpr[i + 1][loc - x] = 1;
            }
        }
        int ok = 0;
        for (int i = 0; i <= len; i++) ok |= dpr[R.size()][i], ok |= dpl[R.size()][i];
        if (!ok) {
            cout << "impossible" << endl;
            return 0;
        }
    }
    cout << "possible" << endl;
    return 0;
}