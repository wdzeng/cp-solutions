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

int table[][2] = {
    {11, 11},
    {4, 4},
    {3, 3},
    {20, 2},
    {10, 10},
    {14, 0},
};

int main() {
    fastio();
    int n;
    char s;
    cin >> n >> s;
    ll ans = 0;
    for (int i = 0; i < n * 4; i++) {
        string str;
        cin >> str;
       
        switch(str[0]) {
            case 'A': ans += str[1] ==s ? 11:11; break;
            case 'K': ans += str[1] ==s ? 4:4; break;
            case 'Q': ans += str[1] ==s ? 3:3; break;
            case 'J': ans += str[1] ==s ? 20:2; break;
            case 'T': ans += str[1] ==s ? 10:10; break;
            case '9': ans += str[1] ==s ? 14:0; break;
        }
        
    }
    cout << ans << endl;
    return 0;
}