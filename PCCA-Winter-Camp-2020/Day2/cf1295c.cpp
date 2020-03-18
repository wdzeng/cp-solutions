#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int solve() {
    string s, t, z;
    cin >> s >> t;

    vector<int> dp[26];
    for (char c : s) {
        for (char i = 'a'; i <= 'z'; i++) {
            auto& v = dp[i - 'a'];
            v.push_back((v.empty() ? 0 : v.back()) + (i == c ? 1 : 0));
        }
    }

    reverse(all(t));
    int tt = t.size();
    int ans = 0;
    while (!t.empty() and ans <= tt) {
        ans++;
        int pos = 0;
        while (!t.empty()) {
            char c = t.back();
            auto& v = dp[c - 'a'];
            auto from = v.begin() + pos;
            auto a = upper_bound(from, v.end(), pos ? *(from - 1) : 0);
            if (a == v.end()) break;
            pos = a - v.begin();
            pos++;
            t.pop_back();
        }
    }

    return ans > tt ? -1 : ans;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) cout << solve() << '\n';
    return 0;
}