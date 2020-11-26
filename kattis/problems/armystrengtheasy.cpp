#include <iostream>
#include <algorithm>
using namespace std;

bool solve() {
    int n, m;
    cin >> n >> m;
    int maxn = -1, maxm = -1;
    int x;
    while(n--) {
        cin >> x;
        maxn = max(x, maxn);
    }
    while(m--) {
        cin >> x;
        maxm = max(x, maxm);
    }
    return maxn >= maxm;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "Godzilla\n" : "MechaGodzilla\n");
    }
    return 0;
}