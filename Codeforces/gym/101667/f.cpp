#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int w;
    ll n;
    cin >> w >> n;
    n--;
    w /= 2;

    ll area = 1;
    ll edge = 1;
    for (int i = 1; i < w; i *= 2) {
        area *= 4;
        edge *= 2;
    }

    int x = 0, y = 0;
    int src = 2, dst = 3;
    while (edge >= 1) {
        
        int id = n / area;
        // cout << n << '@' << id << ':' << x + 1 << ' ' << y + 1 << '#' << src << ' ' << dst << '$' << area << ' ' << edge << endl;
        if (src == 2 && dst == 3) {
            if (id == 0) {
                src = 2, dst = 0;
            } else if (id == 1) {
                src = 2, dst = 3;
                x += edge;
            } else if (id == 2) {
                src = 2, dst = 3;
                x += edge;
                y += edge;
            } else {
                src = 1, dst = 3;
                y += edge;
            }
        }
        else if (src == 2 && dst == 0) {
            if (id == 0) {
                src = 2, dst = 3;
            } else if (id == 1) {
                src = 2, dst = 0;
                y += edge;
            } else if (id == 2) {
                src = 2, dst = 0;
                x += edge;
                y += edge;
            } else {
                src = 1, dst = 0;
                x += edge;
            }
        }
        else if (src == 0 && dst == 2) {
            if (id == 0) {
                src = 0, dst = 1;
                x += edge;
            } else if (id == 1) {
                src = 0, dst = 2;
                x += edge;
                y += edge;
            } else if (id == 2) {
                src = 0, dst = 2;
                y += edge;
            } else {
                src = 3, dst = 2;
            }
        }
        else if (src == 0 && dst == 1) {
            if (id == 0) {
                src = 0, dst = 2;
                x += edge;
            } else if (id == 1) {
                src = 0, dst = 1;
            } else if (id == 2) {
                src = 0, dst = 1;
                y += edge;
            } else {
                src = 3, dst = 1;
                y += edge;
                x += edge;
            }
        }
        else if (src == 1 && dst == 0) {
            if (id == 0) {
                src = 1, dst = 3;
                x += edge;
                y += edge;
            } else if (id == 1) {
                src = 1, dst = 0;
                y += edge;
            } else if (id == 2) {
                src = 1, dst = 0;
            } else {
                src = 2, dst = 0;
                x += edge;
            }
        }
        else if (src == 1 && dst == 3) {
            if (id == 0) {
                src = 1, dst = 0;
                x += edge;
                y += edge;
            } else if (id == 1) {
                src = 1, dst = 3;
                x += edge;
            } else if (id == 2) {
                src = 1, dst = 3;
            } else {
                src = 2, dst = 3;
                y += edge;
            }
        }
        else if (src == 3 && dst == 1) {
            if (id == 0) {
                y += edge;
            } else if (id == 1) {
            } else if (id == 2) {
                x += edge;
            } else {
                x += edge;
                y += edge;
            }
        }
        else if (src == 3 && dst == 2) {
            if (id == 0) {
                src = 3, dst = 1;
                y += edge;
            } else if (id == 1) {
                src = 3, dst = 2;
                x += edge;
                y += edge;
            } else if (id == 2) {
                src = 3, dst = 2;
                y += edge;
            } else {
                src = 0, dst = 2;
            }
        }
        n -= area * id;
        n %= area;
        area /= 4;
        edge /= 2;
    }

    cout << y + 1 << ' ' << x + 1 << endl;
    return 0;
}