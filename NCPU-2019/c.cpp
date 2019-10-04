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

const int maxn = 1e5 + 5;
pii val[maxn];
bool rev = 0;
int n;

void remove(int a) {
    int l = val[a].x, r = val[a].y;
    if (l != -1) val[l].y = r;
    if (r != -1) val[r].x = l;
}

void left(int s, int d, bool rv);
void right(int s, int d, bool rv);

void left(int s, int d, bool rv) {
    if (rv) {
        right(s, d, 0);
        return;
    }
    remove(s);
    int l = val[d].x;
    if (l != -1) val[l].y = s;
    val[d].x = s;
    val[s].x = l, val[s].y = d;
}

void right(int s, int d, bool rv) {
    if (rv) {
        left(s, d, 0);
        return;
    }
    remove(s);
    int r = val[d].y;
    if (r != -1) val[r].x = s;
    val[d].y = s;
    val[s].x = d, val[s].y = r;
}

void change(int a, int b) {
    int al = val[a].x, ar = val[a].y, bl = val[b].x, br = val[b].y;
    if (al != -1) val[al].y = b;
    if (ar != -1) val[ar].x = b;
    if (bl != -1) val[bl].y = a;
    if (br != -1) val[br].x = a;
    swap(val[a], val[b]);
}

int start() {
    for (int i = 0; i < n; i++)
        if (val[i].x == -1) return i;
    assert(false);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    while (cin >> n) {
        rev = 0;
        for (int i = 0; i < n; i++) {
            val[i].x = i - 1, val[i].y = i + 1;
        }
        val[n - 1].y = -1;

        int m;
        cin >> m;
        while (m--) {
            int o;
            cin >> o;
            if (o == 1) {
                int a, b;
                cin >> a >> b;
                a--, b--;
                left(a, b, rev);
            } else if (o == 2) {
                int a, b;
                cin >> a >> b;
                a--, b--;
                right(a, b, rev);
            } else if (o == 3) {
                int a, b;
                cin >> a >> b;
                a--, b--;
                change(a, b);
            } else {
                rev = !rev;
            }
        }

        if (rev)
            for (auto& p : val) swap(p.x, p.y);

        int c = 1;
        int s = start();
        ll ans = 0;
        while (s != -1) {
            if (c & 1) ans += s + 1;
            s = val[s].y;
            c++;
        }
        cout << ans << endl;
    }
    return 0;
}