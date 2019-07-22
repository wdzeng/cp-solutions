#include <iostream>
using namespace std;

int table[100002] = {0};

int search(int x) {
    if (x == 2) return 1;
    if (table[x] == 0) {
        table[x] = search(x - 2) * 2 + (x - 3);
        table[x] %= 1000000007;
    }
    return table[x];
}

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    if (k * 2 <= n) {
        long long ans = 0;
        for (int i = 2; i <= m; i += 2) {
            ans += search(i);
            ans %= 1000000007;
        }
        ans *= 2 * n;
        ans %= 1000000007;
        cout << ans << endl;
    }  //
    else {
        long long ans = 0;
    }
}