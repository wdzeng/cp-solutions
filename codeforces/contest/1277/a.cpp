#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        int n;
        cin >> n;
        int d = to_string(n).size();
        for (int len = 1; len <= d; len++) {
            for (int dig = 1; dig <= 9; dig++) {
                string num = "";
                for (int i = 0; i < len; i++) num.push_back('0' + dig);
                if (stoll(num) <= ll(n)) ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}