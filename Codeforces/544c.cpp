#include <algorithm>
#include <iostream>
using namespace std;
// AC
int main() {
    int n;
    cin >> n;
    int sks[n];
    for (int i = 0; i < n; i++) cin >> sks[i];
    sort(sks, sks + n);
    int lc = 0, hc = 0;
    int maxx = 0;
    while (hc < n) {
        int lim = sks[lc] + 5;
        while (hc < n && sks[hc] <= lim) hc++;
        maxx = max(maxx, hc - lc);
        lc++;
    }
    cout << maxx << "\n";
    return 0;
}