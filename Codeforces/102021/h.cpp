#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

vector<ll> pw[60];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "3 1\n";
        return 0;
    }
    for (int i = 2; i < 60; i++) {
        ll sum = 0;
        pw[i] = {1};
        ll j = 1;
        while (sum < n && j <= 1817121) {
            if (i == 2) {
                pw[i].push_back(j * j);
            } else {
                ll pushed = pw[i - 1][j] * j;
                if (pushed < pw[i].back()) break;
                pw[i].push_back(pushed);
            }

            sum += pw[i].back();
            j++;
        }
        if (sum == n) {
            cout << i + 1 << ' ' << j - 1 << endl;
            return 0;
        }
    }
    cout << "impossible\n";
    return 0;
}