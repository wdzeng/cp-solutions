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
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        vec.push_back(val);
    }
    if (n % 2 == 1) {
        cout << "YES\n";
        int g = (n - 1) / 2;
        int t = g * 2 - 1;
        cout << t << '\n';
        for (int i = 0; i < g; i++) {
            int j = i * 2 + 1;
            cout << j << ' ' << j + 1 << ' ' << j + 2 << '\n';
        }
        for (int i = g - 2; i >= 0; i--) {
            int j = i * 2 + 1;
            cout << j << ' ' << j + 1 << ' ' << j + 2 << '\n';
        }
    } else {
        int rem = 0;
        for (auto& val : vec) rem ^= val;
        if (rem) {
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n";
        int g = (n - 2) / 2;
        int t = g * 2 - 1;
        cout << t << '\n';
        for (int i = 0; i < g; i++) {
            int j = i * 2 + 1;
            cout << j << ' ' << j + 1 << ' ' << j + 2 << '\n';
        }
        for (int i = g - 2; i >= 0; i--) {
            int j = i * 2 + 1;
            cout << j << ' ' << j + 1 << ' ' << j + 2 << '\n';
        }
    }

    return 0;
}