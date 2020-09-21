#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& val : v) cin >> val;

    int l = -1, r = -1;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            if (r != -1) {
                cout << "impossible\n";
                return 0;
            }
            if (l == -1) {
                l = i;
            }
        } else if (v[i] < v[i + 1]) {
            if (l == -1) continue;
            if (r != -1) continue;
            if (r == -1) {
                r = i + 1;
            }
        }
    }

    if (l == -1 && r == -1) {
        cout << "1 1\n";
        return 0;
    }
    if (l != -1) {
        if (r == -1) r = n;
    }

    for (int i = l - 1; i >= 0; i--) {
        if (v[i] == v[l]) l--;
    }
    for (int i = r; i < n; i++) {
        if (v[i] == v[r - 1]) r++;
    }

    reverse(v.begin() + l, v.begin() + r);
    if (is_sorted(all(v))) cout << l + 1 << ' ' << r << endl;
    else cout << "impossible\n";

    return 0;
}