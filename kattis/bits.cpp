#include <bits/stdc++.h>
using namespace std;

int nbit(int n) {
    int ret = 0;
    while (n) {
        if (n & 1) ret++;
        n >>= 1;
    }
    return ret;
}

int solve() {
    int x; cin >> x;
    int maxx = 0;
    while(x) {
        maxx = max(maxx, nbit(x));
        x/=10;
    }
    return maxx;
}

int main() {
    int n; cin >> n; while(n--) cout << solve() << endl;
    return 0;
}