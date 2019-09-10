#include <algorithm>
#include <iostream>
using namespace std;

// AC

long solve() {
    int s, p, sa, pa, sb, pb;
    cin >> s >> p >> sa >> pa >> sb >> pb;
    s = abs(s);
    if (s == 0 || pa==pb) return 0;
    if (sa < sb) {
        swap(sa, sb);
        swap(pa, pb);
    }

    int sdiff = sa - sb;
    if (sdiff == 0) return -1;

    int pdiff = pb - pa;
    if (pdiff < 0) return -1;

    long ret = (long)s * pdiff / sdiff;
    // cout << "ret: " << ret << endl;
    return ret > 1'000'000'000'000'000'000L ? -1 : ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long ret = solve();
        if (ret < 0)
            cout << "position zero!\n";
        else
            cout << ret << "\n";
    }
    return 0;
}