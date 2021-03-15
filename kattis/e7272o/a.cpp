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

int vow(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    fastio();
    string s;
    while(cin >> s) {
        string ans;
        for(int i=0; i<s.size(); i++) {
            if(i<s.size() -2) {if(vow(s[i]) && s[i+1] == 'p' && s[i+2] == s[i]){ ans.push_back(s[i]); i+=2;} else ans.push_back(s[i]);}
            else ans.push_back(s[i]);
        }
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}