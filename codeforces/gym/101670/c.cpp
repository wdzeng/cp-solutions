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

int n;

inline int horse() {
    if (n <= 2) return 1;
    return 2;
}

inline int king() {
    return n == 1 ? 1 : 4;
}

inline int car() {
    return n;
}

inline int bishop() {
    return n;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    while (cin >> n) {
        char c;
        cin >> c;
        if (c == 'N')
            cout << horse() << '\n';
        else if (c == 'R')
            cout << car() << '\n';
        else if (c == 'B')
            cout << bishop() << '\n';
        else if (c == 'K')
            cout << king() << '\n';
    }
    return 0;
}