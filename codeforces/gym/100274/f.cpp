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
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

int main() {
    fastio();
    int q;
    cin >> q;
    string line;
    getline(cin, line);
    while (q--) {
        getline(cin, line);
        vector<int> freq(100);
        for (char c : line)
            if (isalpha(c)) freq[c]++;
        char isE = 'A';
        int cnt = 1;
        for (char c = 'B'; c <= 'Z'; c++) {
            if (freq[c] == freq[isE])
                cnt++;
            else if (freq[c] > freq[isE])
                isE = c, cnt = 1;
        }
        if (cnt > 1) {
            cout << "NOT POSSIBLE" << endl;
            continue;
        }
        int d = isE - 'E';
        if (d < 0) d += 26;
        cout << d << ' ';
        for(char c: line) {
            if(isalpha(c)) {
                c-=d;
                if(c < 'A') c+=26;
                cout << c;
            }
            else {
                cout << c;
            }
        }
        cout << endl;
    }
    return 0;
}