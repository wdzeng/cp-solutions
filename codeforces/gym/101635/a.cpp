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
    int in, out;
    cin >> in >> out;
    vector<int> vin, vout;
    while (in--) {
        int a;
        cin >> a;
        vin.push_back(a);
    }
    while (out--) {
        int a;
        cin >> a;
        vout.push_back(a);
    }

    unordered_map<int, int> m;
    for (int in : vin) {
        for (int out : vout) {
            int diff = out - in;
            if (diff < 0) continue;
            m[diff]++;
        }
    }

    int maxx = 0;
    int maxt = 0;
    for (auto& p : m) {
        if (p.y > maxt or p.y == maxt and p.x < maxx) {
            maxt = p.y;
            maxx = p.x;
        }
    }

    cout << maxx << endl;
    return 0;
}
