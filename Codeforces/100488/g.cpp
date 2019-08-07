#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int n, sum;
    cin >> n >> sum;
    vector<int> coin = {1};
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ll c = (ll)coin.back() * x;
        if (c > sum) break;
        coin.push_back(c);
    }

    int ans = 0;
    while (sum) {
        ans += sum / coin.back();
        sum -= sum / coin.back() * coin.back();
        coin.pop_back();
    }
    cout << ans << endl;
    return 0;
}