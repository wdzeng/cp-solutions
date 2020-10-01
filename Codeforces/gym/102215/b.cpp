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
    string up, down;
    cin >> up >> down;
    int n = up.size();
    int u = 0, d = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (up[i] == '#') {
            if (down[i] == '#') {
                b++;
            } else {
                u++;
            }
        } else {
            if (down[i] == '#') {
                d++;
            }
        }
    }
    if (b == 0 && u > 0 && d > 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int x = 0;
    for (int i = 0; i < u; i++) {
        up[x] = '#';
        down[x] = '.';
        x++;
    }
    for (int i = 0; i < b; i++) {
        up[x] = '#';
        down[x] = '#';
        x++;
    }
    for (int i = 0; i < d; i++) {
        up[x] = '.';
        down[x] = '#';
        x++;
    }
    while (x < n) {
        up[x] = down[x] = '.';
        x++;
    }
    cout << up << endl
         << down << endl;
    return 0;
}