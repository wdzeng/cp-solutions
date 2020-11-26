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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string s;
    cin >> s;
    int n = zz(s);
    vector<int> f;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            f.push_back(i);
            if (n / i != i && i != 1) f.push_back(n / i);
        }
    }
    sort(all(f));
    unordered_set<int> good;
    for (int k : f) {
        for (int i = 0; i < n; i++) {
            if (s[i] == 'P') continue;
            int loc = (i + k) % n;
            int ok = 1;
            while (loc != i) {
                if (s[loc] == 'P') {
                    ok = 0;
                    break;
                }
                loc += k;
                loc %= n;
            }
            if (ok) {
                good.insert(k);
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (good.count(__gcd(i, n))) ans++;
    }

    cout << ans << endl;

    return 0;
}