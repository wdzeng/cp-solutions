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
    string s;
    cin >> s;
    char x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);

    if (s[0] < x) {
        if (s.size() == 1) {
            cout << -1 << endl;
            return 0;
        }
        for (int i = 1; i < s.size(); i++) cout << y;
        cout << endl;
        return 0;
    }

    string ans;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] > y) {
            while (i < s.size()) ans.push_back(y), i++;
            break;
        }
        if (s[i] == y)
            ans.push_back(y);
        else if (s[i] > x) {
            ans.push_back(x);
            i++;
            while (i < s.size()) ans.push_back(y), i++;
            break;
        } else if (s[i] == x) {
            ans.push_back(x);
        } else {
            int j;
            for (j = i - 1; j >= 0; j--) {
                if (ans[j] == x)
                    ans[j] = y;
                else {
                    ans[j] = x;
                    break;
                }
            }
            if (j == -1) {
                ans.clear();
                for (int i = 1; i < s.size(); i++) ans.push_back(y);
                break;
            }
            while (i < s.size()) ans.push_back(y), i++;
            break;
        }
    }

    deque<char> q;
    for (char c : ans) q.push_back(c);
    while (q.size() && q.front() == '0') q.pop_front();
    if (q.empty())
        cout << -1 << endl;
    else {
        for (char c : q) cout << c;
        cout << endl;
    }
    return 0;
}