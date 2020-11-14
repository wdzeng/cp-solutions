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
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        int index1 = s.find_first_of('1');
        int index2 = s.find_last_of('1');
        if (index1 == -1) {
            cout << 0 << '\n';
            continue;
        }

        s = s.substr(index1, index2 -index1 + 1);
        int ansb = 0;
        int ansa = 1;
        int cnt = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                cnt++;
            }  //
            else {
                if (s[i - 1] == '1') continue;
                if (cnt * b <= a)
                    ansb += cnt;
                else
                    ansa++;
                cnt = 0;
            }
        }
        cout << ansa * a + ansb * b << '\n';
    }

    return 0;
}