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

const int N = 1e4 + 5;
int solve(int n, int k) {
    k--;
    vector<int> s = {k};
    int ans = 0;
    for (int i = 1; i < n; i++) {
        vector<int> t(i + 1);
        for (int j = 0; j < i; j++) {
            t[j] += (s[j] + 1) >> 1;
            t[j + 1] += (s[j]) >> 1;
        }
        if (s[ans] % 2 == 1) ans++;
        s.swap(t);
    }
    return ans;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
    return 0;
}