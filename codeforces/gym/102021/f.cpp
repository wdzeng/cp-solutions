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

const int maxv = 1e6 + 10;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int i = 1, j = 1;
    vector<int> rabbits(maxv);
    while (i < maxv) {
        j = i + j;
        rabbits[i] = j;
        swap(i, j);
    }

    int n;
    cin >> n;
    vector<pii> monsters;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (rabbits[x]) monsters.emplace_back(x, i);
    }
    sort(iter(monsters));
    if (monsters.size() > 1 && monsters[0].x == 1 && monsters[1].x == 1) {
        cout << monsters[0].y + 1 << ' ' << monsters[1].y + 1 << endl;
        return 0;
    }

    int pa = 0, pb = 0;
    while (1) {
        while (pb < monsters.size() && monsters[pb].x == monsters[pa].x) pb++;
        if (pb == monsters.size()) {
            cout << "impossible" << endl;
            return 0;
        }
        int v0 = monsters[pa].x, v1 = monsters[pb].x;
        if (rabbits[v0] == v1) {
            cout << monsters[pa].y + 1 << ' ' << monsters[pb].y + 1 << endl;
            return 0;
        }
        pa = pb;
    }
    return 0;
}