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
    int n, k;
    cin >> n >> k;
    int maxx = 0;
    while (n--) {
        int val;
        cin >> val;
        maxx = max(maxx, val);
    }
    maxx *= k;
    cout << (maxx+999) / 1000  << endl;
    return 0;
}