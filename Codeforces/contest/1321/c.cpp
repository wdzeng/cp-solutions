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
    int len;
    string str;
    cin >> len >> str;

    map<char, int> m;
    for (char c : str) m[c]++;
    while (str.size()) {
        const char big = m.rbegin()->x;
        // cout << big << endl;
        bool ok = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == big && (i - 1 >= 0 && str[i - 1] == big - 1 || i + 1 < str.size() && str[i + 1] == big - 1)) {
                ok = 1;
                str.erase(str.begin() + i);
                if (m[big] == 1)
                    m.erase(big);
                else
                    m[big]--;
                break;
            }
        }
        if (!ok) {
            if (m[big] == 1)
                m.erase(big);
            else
                m[big]--;
        }
        if (m.empty()) {
            cout << len - str.size() << endl;
            break;
        }
    }

    return 0;
}