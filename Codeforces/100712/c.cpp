#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))
 
int solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> light;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') light.push_back(i);
    }
    for (int l : light) {
        if (l != 0) s[l - 1] = '*';
        if (l + 1 != n) s[l + 1] = '*';
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            if (i + 1 != n && s[i + 1] == '.') {
                if (i + 2 != n) s[i + 2] = '*';
                s[i + 1] = '*';
            }
            s[i] = '*';
            ans++;
        }
    }
    return ans;
}
 
int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << solve() << endl;
    }
    return 0;
}