#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mn(x) memset(x, -1, sizeof(x))

int solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x >> x;
    }
    return n == 1 ? 1 : 2;
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: %d\n", i, solve());
    }
    return 0;
}