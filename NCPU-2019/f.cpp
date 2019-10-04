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

string solve(const string& s) {

    string ret = "";
    int cl = 0;
    int m;
    string unknown;
    for (char c : s) {
        if (isupper(c))
            (cl ? unknown : ret).push_back(c);
        else if (isdigit(c)) {
            if (cl)
                unknown.push_back(c);
            else
                m = c - '0';
        } else if (c == '[') {
            if (cl) unknown.push_back(c);
            cl++;
        } else if (c == ']') {
            cl--;
            if (cl == 0) {
                unknown = solve(unknown);
                for (int i = 0; i < m; i++) ret += unknown;
                unknown = "";
            } else {
                unknown.push_back(c);
            }
        }
    }

    return ret;
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}