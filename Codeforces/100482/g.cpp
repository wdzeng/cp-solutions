#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mn(x) memset(x, -1, sizeof(x))
const int M = 1e9 + 7;

int rev(const int i) {
    static unordered_map<int, int> rec;
    if (rec.count(i)) return rec[i];
    int a = i, m = M, y = 0, x = 1;
    while (a > 1) {
        int q = a / m;
        int tmp = m;
        m = a % m;
        a = tmp;

        int tmp2 = y;
        y = x - q * y;
        x = tmp2;
    }
    x = (x + M) % M;
    rec[i] = x;
    rec[x] = i;
    return x;
}

int solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mmap;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int y = rev(x);
        if (mmap[y])
            mmap[y]--, ans++;
        else
            mmap[x]++;
    }
    return ans;
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