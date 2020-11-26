#include <bits/stdc++.h>
using namespace std;

int main() {
    int cs = 0;
    cin >> cs;
    int hc, mc, hw, mw;
    for(int i=1;i<=cs;i++) {
        cin >> hc >> mc >> hw >> mw;
        cout << "Case " << i << ": " << ((hw - hc) * 60 + (mw - mc)) << endl;
    }
    return 0;
}