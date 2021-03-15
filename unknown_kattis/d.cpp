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
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s.back() == 'a')
            s.push_back('s');
        else if (s.back() == 'i' || s.back() == 'y') {
            s.pop_back();
            s.push_back('i');
            s.push_back('o');
            s.push_back('s');
        } else if (s.back() == 'l') {
            s.push_back('e');
            s.push_back('s');
        } else if (s.back() == 'n') {
            s.pop_back();
            s += "anes";
        } else if (s[zz(s) - 2] == 'n' && s[zz(s) - 1] == 'e') {
            s.pop_back();
            s.pop_back();
            s += "anes";
        } else if (s.back() == 'o')
            s.push_back('s');
        else if (s.back() == 'r')
            s += "es";
        else if (s.back() == 't')
            s += "as";
        else if (s.back() == 'u')
            s += "s";
        else if (s.back() == 'w')
            s += "as";
        else if (s.back() == 'v')
            s += "es";
        else
            s += "us";
        cout << s << '\n';
    }

    return 0;
}