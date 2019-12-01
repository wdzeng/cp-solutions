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
    string s;
    cin >> s;

    int z = 0, o = 0;
    for (char c : s) (c == '0' ? z : o)++;
    char popped = 0;
    if (z == o) {
        popped = s.back();
        s.pop_back();
        if (popped == '0')
            z--;
        else
            o--;
    }
    char src = z > o ? '0' : '1';
    char dst = z > o ? '1' : '0';
    for (char& c : s)
        if (c == src) c = dst;
    if (popped) {
        if (popped == '0')
            s.push_back('1');
        else
            s.push_back('0');
    }
    cout << s << '\n';
    return 0;
}