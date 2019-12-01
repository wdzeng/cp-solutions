#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> vec;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        switch(s[0]) {
            case 'A': case 'P': case 'O': case 'R': vec.push_back(1); break;
            case 'B': case 'M': case 'S': vec.push_back(2); break;
            case 'D': case 'G': case 'J': case 'K': case 'T': case 'W': vec.push_back(3); break;
        }
    }

    //for(int i: vec) cout << i << ", "; cout << endl;

    int prev = 1;
    ll ans = 0;
    for(int i: vec){
        ans += abs(i-prev);
        prev = i;
    }
    cout << ans << endl;
    return 0;
}