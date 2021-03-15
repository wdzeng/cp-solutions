#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#define ass(a) assert(a)
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#define ass(a)
#endif

int main() {
    fastio();
    vector<int> a, b;
    for (int i = 0; i < 6; i++) {
        int v;
        cin >> v;
        a.push_back(v);
    }
    for (int i = 0; i < 6; i++) {
        int v;
        cin >> v;
        b.push_back(v);
    }
    int win = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (a[i] > b[j]) win++;
        }
    }
    int dd = 36;
    int g = __gcd(win, dd);
    win /= g;
    dd /= g;
    cout << win << '/' << dd << endl;
    return 0;
}