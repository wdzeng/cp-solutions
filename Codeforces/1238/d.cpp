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
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;

    int pa = -1, pb = -1;
    for (int i = 0; i < n; i++) {
        int pme = s[i] == 'A' ? pa : pb;
        int pit = s[i] == 'B' ? pa : pb;
        if (pme == -1) {
            
        } else if (pit == -1)
            ans += i;
        else {
            if (pme < pit)
                ans += (pme + 1);
            else
                ans += (pit) + (i - pit - 1);
        }
        if (s[i] == 'A')
            pa = i;
        else
            pb = i;
    }
    cout << ans << endl;
    return 0;
}