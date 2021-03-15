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
#else
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

int main() {
    fastio();
    int i;
    int ok = 1;
    for (i = 100; i <= 1000; i += 100) {
        cout << "? " << i << endl;
        string s;
        cin >> s;
        if (s != "SAFE") {
            ok = 0;
            break;
        }
    }

    if (ok) {
        cout << "? " << 1001 << endl;
        string s;
        cin >> s;
        if (s == "SAFE") {
            cout << "! 1001" << endl;
            return 0;
        } else {
            cout << "! 1000" << endl;
            return 0;
        }
    }

    int j;
    for (j = i - 100 + 10; j <= i; j += 10) {
        cout << "? " << j << endl;
        string s;
        cin >> s;
        if (s != "SAFE") {
            break;
        }
    }

    int k;
    for (k = j - 10 + 1; k <= j; k++) {
        cout << "? " << k << endl;
        string s;
        cin >> s;
        if (s != "SAFE") {
            break;
        }
    }

    cout << "! " << k - 1 << endl;
    return 0;
}