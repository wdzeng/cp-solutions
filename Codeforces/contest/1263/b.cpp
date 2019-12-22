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
    cin.tie(0), ios::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<string> v;
        unordered_map<string, int> m;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v.push_back(s);
            m[s]++;
        }

        int ans = 0;
        for (string& s : v) {
            if (m[s] == 1) continue;

            while (1) {
                string ss = s;
                ss[rand() % 4] = rand() % 10 + '0';
                if (m.count(ss) == 0) {
                    m[s]--;
                    m[ss]++;
                    s = ss;
                    ans++;
                    break;
                }
            }
        }
        cout << ans << '\n';
        for (string& s : v) cout << s << '\n';
    }
    return 0;
}
