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

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int n, l;
    while (cin >> n >> l and n and l) {
        vector<int> loc;
        vector<bool> right;
        while (n--) {
            char d;
            int x;
            cin >> d >> x;
            loc.push_back(x);
            right.push_back(d == 'R');
        }

        int rem = loc.size();
        int ans = 0;
        int ansant;
        while (rem) {
            vector<int> col(l);
            vector<int> leaves;
            for (int i = 0; i < loc.size(); i++) {
                if (loc[i] == 0 or loc[i] == l) continue;
                if (right[i])
                    loc[i]++;
                else
                    loc[i]--;
                if (loc[i] == 0 or loc[i] == l)
                    rem--, leaves.push_back(i);
                else
                    col[loc[i]]++;
            }
            for (int i = 0; i < loc.size(); i++) {
                if (loc[i] == 0 or loc[i] == l) continue;
                if (col[loc[i]] > 1) right[i] = !right[i];
            }
            ans++;
            if (!rem) {
                if (leaves.size() == 1)
                    ansant = leaves[0];
                else
                    ansant = right[leaves[0]] ? leaves[1] : leaves[0];
            }
        }

        cout << ans << ' ' << ansant + 1 << '\n';
    }
    return 0;
}
