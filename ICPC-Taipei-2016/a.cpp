#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define x first
#define y second

pii g(pii p) {
    ll g = __gcd(p.x, p.y);
    p.x /= g, p.y /= g;
    if (p.y < 0) p.x *= -1, p.y *= -1;
    return p;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll c, v1, v2;
    while (cin >> c and c) {
        cin >> v1 >> v2;
        assert(v1 != v2);
        int vfast = max(v1, v2);
        int vslow = min(v1, v2);
        pii aloc = {c * v1, (vfast - vslow) * 2};
        aloc = g(aloc);
        ll mm = aloc.y * c;
        aloc.x = (aloc.x % mm + mm) % mm;
        assert(aloc.x >= 0);
        if (aloc.y == 1)
            cout << aloc.x << '\n';
        else
            cout << aloc.x << '/' << aloc.y << '\n';
    }
    return 0;
}
