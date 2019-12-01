#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

inline int roundup(int a, int b) {
    if (a == 0) return 0;
    return (a - 1) / b + 1;
}

bool test(int sd, int sc, int nd, int nc, int s) {
    int nmore = nd % nc;
    if (nmore == 0) {
        return nc * min(nd / nc * sd, sc) >= s;
    }
    int nless = nc - nmore;
    int summore = nmore * min(sd * roundup(nd, nc), sc);
    int sumless = nless * min(sd * (roundup(nd, nc) - 1), sc);
    return summore + sumless >= s;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int sd, sc, s;
    cin >> sd >> sc >> s;
    int nd = roundup(s, sd);
    int nc = roundup(s, sc);
    if (nd <= nc) {
        cout << nc << ' ' << nc << endl;
        return 0;
    }

    int left = nc, right = nd;
    while (left < right) {
        int mid = (left + right) / 2;
        if (test(sd, sc, nd, mid, s))
            right = mid;
        else
            left = mid + 1;
    }
    cout << nd << ' ' << left << endl;
    return 0;
}