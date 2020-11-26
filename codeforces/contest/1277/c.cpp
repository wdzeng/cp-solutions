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
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        s = "     " + s + "     ";
        int ans = 0;
        vector<int> removal;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 't' and s[i + 1] == 'w' and s[i + 2] == 'o' and s[i + 3] == 'n' and s[i + 4] == 'e') {
                ans++;
                removal.push_back(i + 2);
                i += 4;
            } else if (s[i] == 't' and s[i + 1] == 'w' and s[i + 2] == 'o') {
                ans++;
                removal.push_back(i + 1);
            } else if (s[i] == 'o' and s[i + 1] == 'n' and s[i + 2] == 'e') {
                ans++;
                removal.push_back(i + 1);
            }
        }
        cout << ans << endl;
        for (int loc : removal) cout << loc - 4 << ' ';
        cout << endl;
    }

    return 0;
}