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
    string south, north;
    cin >> south >> north;
    reverse(iter(south)), reverse(iter(north));
    int ans = 0;
    while(!south.empty() && !north.empty()) {
        ans++;
        if(south.back() == 'L' && north.back() == 'L') south.pop_back(), north.pop_back();
        else if(south.back() == 'L') north.pop_back();
        else if(north.back() == 'L') south.pop_back();
        else south.pop_back(), north.pop_back();
    }
    ans += south.size() + north.size();
    cout << ans << endl;
    return 0;
}