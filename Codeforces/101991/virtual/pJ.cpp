#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef double db;

struct p{
    db x, y, z;
};

p cross(const p &a, const p &b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

p operator- (const p &a, const p &b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

p operator+ (const p &a, const p &b) {
     return {a.x + b.x, a.y + b.y, a.z + b.z};
}


db dis(p a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

p operator *(const p & a, db k) {
    return {a.x * k, a.y * k, a.z * k};
}

int t;

double l, h;

p n, a, b, bc, c, o = {0, 0, 0}, oja, base;

int main() {
    freopen("jupiter.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n.x >> n.y >> n.z >> a.x >> a.y >> a.z >> l >> h, base = {0, 0, -h};
        oja = cross(n - o, a - o);
        oja = oja * (l / dis(oja) / 2.0);
        bc = (a - o) * -0.5;
        b = bc + oja, c = bc - oja;
        cout << setprecision(6) << fixed << dis(a - base) << ' ' << dis(b - base) << ' ' << dis(c - base) << '\n';
    }
    return 0;
}
