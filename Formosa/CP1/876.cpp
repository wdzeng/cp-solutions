#include <iostream>
#include <unordered_map>
using namespace std;
// AC
unordered_map<int, int> table;

int x(int k) {
    if (k == 0) return 1;
    if (table.count(k)) return table[k];
    long a = x(k / 2);
    a *= a;
    if (k & 1 == 1) a <<= 1;
    a %= 998244353;
    int ret = (int)a;
    table[k] = ret;
    return ret;
}

int solve(int k) {
    int ret = x(k + 1);
    ret -= (k + 2);
    if(ret<0) ret+= 998244353;
    return ret;
}

int main() {
    int t;
    cin >> t;
    while(t--) { int k; cin >> k; cout << solve(k) << "\n";}
    return 0;
}