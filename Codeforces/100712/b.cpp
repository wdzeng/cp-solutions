#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))
 
ll solve() {
    ll ans = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> rock = {0}, scss = {0}, papr = {0};
    for (int i = 0; i < n; i++) {
        vector<int>& win = [&]() -> vector<int>& {
            if (s[i] == 'R') return papr;
            if (s[i] == 'S') return rock;
            return scss;
        }();
        vector<int>& none = [&]() -> vector<int>& {
            if (s[i] == 'P') return papr;
            if (s[i] == 'R') return rock;
            return scss;
        }();
        vector<int>& lose = [&]() -> vector<int>& {
            if (s[i] == 'S') return papr;
            if (s[i] == 'P') return rock;
            return scss;
        }();
        win.push_back(win.back() + 1);
        none.push_back(none.back());
        lose.push_back(lose.back() - 1);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (rock[i] + papr[j] - papr[i] + scss[n] - scss[j] > 0) ans++;
        }
    }
    return ans;
}
 
int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << solve() << "\n";
    }
    return 0;
}