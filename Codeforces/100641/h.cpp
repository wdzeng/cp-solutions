#include <bits/stdc++.h>
using namespace std;
const double rdeg = 3600.0 / 330.0;
int hr, mn, sc;

void solve() {
    int deg, h;
    string o;
    cin >> deg >> o >> h;
    int initdeg = (12 - h) * 30 % 360;
    if (o == "after") {
        deg -= initdeg;
        if (deg <= 0) deg += 360;
        int second = round(deg * rdeg);
        hr = (h + second / 3600) % 12;
        mn = (second % 3600) / 60;
        sc = second % 60;
    }  //
    else {
        deg = initdeg - deg;
        if (deg <= 0) deg += 360;
        int second = round(deg * rdeg);
        second = 43200 - second;
        hr = (h + second / 3600) % 12;
        mn = (second % 3600) / 60;
        sc = second % 60;
    }
}

int main() {
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        solve();
        printf("Case %d: %d:%02d:%02d\n", cs, hr == 0 ? 12 : hr, mn, sc);
    }
}