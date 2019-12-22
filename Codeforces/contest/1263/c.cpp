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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> f = {0, 1}, b = {n};
        for (int i = 2; f.back() < b.back(); i++) {
            int d = n / i;
            f.push_back(i);
            b.push_back(d);
        }

        while (f.back() >= b.back()) f.pop_back();
        cout << f.size() + b.size() << '\n';
        for (int i : f) cout << i << ' ';
        while (b.size()) cout << b.back() << ' ', b.pop_back();
        cout << '\n';
    }
    return 0;
}
