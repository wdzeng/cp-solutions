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

int solve() {
    // cin.tie(0), ios::sync_with_stdio(0);
    string s;
    cin >> s;
    if (s.find("desmond") != -1) return 0;
    s = "        " + s + "        ";
    int q;
    cin >> q;
    int t = 0;
    while (q--) {
        int a;
        cin >> a;
        a += 7;
        char c;
        cin >> c;
        s[a] = c;
        t++;

        switch (c) {
        case 'd':
            if (s.substr(a, 7) == "desmond") return t;
            if (s.substr(a - 6, 7) == "desmond") return t;
            break;
        case 'e':
            if (s.substr(a - 1, 7) == "desmond") return t;
            break;
        case 's':
            if (s.substr(a - 2, 7) == "desmond") return t;
            break;
        case 'm':
            if (s.substr(a - 3, 7) == "desmond") return t;
            break;
        case 'o':
            if (s.substr(a - 4, 7) == "desmond") return t;
            break;
        case 'n':
            if (s.substr(a - 5, 7) == "desmond") return t;
            break;
        }
    }
    return -1;
}

int main() {
    int i = solve(); if(i == -1) {
        cout << "Goodbye, my love!\n";
    }
    else {
        cout << "I love you, Desmond!\n";
        cout << i << endl;
    }
    return 0;
}
