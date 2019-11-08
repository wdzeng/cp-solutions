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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int nw;
    cin >> nw;
    map<int, int> ai, bi;
    int prev = -1;
    for (int i = 0; i < nw; i++) {
        int inf;
        cin >> inf;
        if (prev == -1 or inf > prev) {
            ai[inf] = i;
            prev = inf;
        }
    }
    ai[2e9] = nw;
    bi[2e9] = nw;

    prev = -1;
    for (int i = 0; i < nw; i++) {
        int inf;
        cin >> inf;
        if (prev == -1 or inf > prev) {
            bi[inf] = i;
            prev = inf;
        }
    }

    int d;
    cin >> d;
    vector<int> as, bs;
    for (int i = 0; i < d; i++) {
        int s;
        cin >> s;
        as.push_back(s);
    }
    for (int i = 0; i < d; i++) {
        int s;
        cin >> s;
        bs.push_back(s);
    }

    for (int i = 0; i < d; i++) {
        int ass = as[i], bss = bs[i];
        auto mxa = *ai.upper_bound(ass);
        auto mxb = *bi.upper_bound(bss);
        if (mxa.y == mxb.y) {
            cout << "Draw\n";
        } else if (mxa.y > mxb.y) {
            cout << "Constantine\n";
        } else {
            cout << "Mike\n";
        }
    }
    return 0;
}
