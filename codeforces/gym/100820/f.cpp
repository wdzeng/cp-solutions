#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int t1[3][3];
int t2[3][3];
int t3[3][3];
int t4[3][3];
int x[3][3];
int r1[3][3];
int r2[3][3];
int r3[3][3];
int r4[3][3];
int s1[3][3];
int s2[3][3];
int z1[3][3];
int z2[3][3];
int v1[3][3];
int v2[3][3];
int v3[3][3];
int v4[3][3];
int n1[3][3];
int n2[3][3];
int n3[3][3];
int n4[3][3];
int w1[3][3];
int w2[3][3];
int w3[3][3];
int w4[3][3];

inline void r90(int s[3][3], int d[3][3]) {
    d[2][2] = s[2][0];
    d[1][2] = s[2][1];
    d[0][2] = s[2][2];
    d[2][1] = s[1][0];
    d[1][1] = s[1][1];
    d[0][1] = s[1][2];
    d[2][0] = s[0][0];
    d[1][0] = s[0][1];
    d[0][0] = s[0][2];
}

inline void cls(int x[3][3]) {
    if (x[0][0] && x[0][1] && x[0][2]) {
        x[0][0] = x[1][0];
        x[0][1] = x[1][1];
        x[0][2] = x[1][2];
        x[1][0] = x[2][0];
        x[1][1] = x[2][1];
        x[1][2] = x[2][2];
        x[2][0] = x[2][1] = x[2][2] = 0;
        cls(x);
    } else if (x[1][0] && x[1][1] && x[1][2]) {
        x[1][0] = x[2][0];
        x[1][1] = x[2][1];
        x[1][2] = x[2][2];
        x[2][0] = x[2][1] = x[2][2] = 0;
        cls(x);
    } else if (x[2][0] && x[2][1] && x[2][2]) {
        x[2][0] = x[2][1] = x[2][2] = 0;
    }
}

inline void init() {
    t1[2][0] = t1[2][1] = t1[2][2] = t1[1][1] = t1[0][1] = 1;
    r90(t1, t2);
    r90(t2, t3);
    r90(t3, t4);
    x[2][1] = x[1][0] = x[1][1] = x[1][2] = x[0][2] = 1;
    r1[2][1] = r1[2][2] = r1[1][0] = r1[1][1] = r1[0][1] = 1;
    r90(r1, r2);
    r90(r2, r3);
    r90(r3, r4);
    s1[2][1] = s1[2][2] = s1[1][1] = s1[0][1] = s1[0][0] = 1;
    r90(s1, s2);
    z1[2][0] = z1[2][1] = z1[1][1] = z1[0][1] = z1[0][2] = 1;
    r90(z1, z2);
    v1[2][0] = v1[1][0] = v1[0][0] = v1[0][1] = v1[0][2] = 1;
    r90(v1, v2);
    r90(v2, v3);
    r90(v3, v4);
    n1[2][1] = n1[2][0] = n1[1][1] = n1[1][2] = n1[0][1] = 1;
    r90(n1, n2);
    r90(n2, n3);
    r90(n3, n4);
    w1[2][0] = w1[1][0] = w1[1][1] = w1[2][1] = w1[2][2] = 1;
    r90(w1, w2);
    r90(w2, w3);
    r90(w3, w4);

    cls(t1);
    cls(t2);
    cls(t3);
    cls(t4);
    cls(x);
    cls(r1);
    cls(r2);
    cls(r3);
    cls(r4);
    cls(s1);
    cls(s2);
    cls(z1);
    cls(z2);
    cls(v1);
    cls(v2);
    cls(v3);
    cls(v4);
    cls(n1);
    cls(n2);
    cls(n3);
    cls(n4);
    cls(w1);
    cls(w2);
    cls(w3);
    cls(w4);
}

typedef array<array<int, 3>, 10> G;

G merge(G g, int x[3][3]) {
}

inline int good(const G& g) {
    return !(g[9][0] || g[9][1] || g[9][2] | g[8][0] || g[8][1] || g[8][2] || g[7][0] || g[7][1] || g[7][2]);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    init();

    string ser;
    cin >> ser;

    queue<pair<G, int>> q;
    q.emplace(G(), 0);

    int maxans = 0;
    while (!q.empty()) {
        auto v = q.front();
        auto& g = v.x;
        int i = v.y;
        char nxt = ser[(i + 1) % ser.size()];
        switch (nxt) {
            case 'T':
                break;
            case 'R':
                break;
            case 'X':
                break;
            case 'S':
                break;
            case 'Z':
                break;
            case 'V':
                break;
            case 'N':
                break;
            case 'W':
                break;
        }
    }

    return 0;
}