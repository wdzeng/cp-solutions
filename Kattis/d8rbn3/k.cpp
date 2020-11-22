#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifndef hy
#define endl '\n'
#endif

const int Q = 1e5 + 5;
const int N = 5050;

namespace Bit2D {

ll v[N][N];
ll sum(int x, int y) {
    ll ret = 0;
    for (int i = x; i; i -= i & -i)
        for (int j = y; j; j -= j & -j)
            ret += v[i][j];
    return ret;
}
void add(int x, int y, ll val) {
    for (int i = x; i < N; i += i & -i)
        for (int j = y; j < N; j += j & -j)
            v[i][j] += val;
}
ll get(int x, int y) {
    ll ret = 0;
    ret += sum(x - 1, y - 1);
    ret -= sum(x - 1, y);
    ret -= sum(x, y - 1);
    return ret;
}
}  // namespace Bit2D

pii S[Q], D[Q];
ll V[Q];

inline ll lrand() {
    ll a = rand(), b = rand();
    return (a << 10) ^ b;
}

int main() {
#ifndef hy
    cin.tie(0), ios::sync_with_stdio(0);
#endif

    srand(time(0));
    int q;
    cin >> q;

    for (int t = 1; t <= q; t++) {
        int op;
        cin >> op;

        if (op == 1) {
            pii src, dst;
            cin >> src.x >> src.y >> dst.x >> dst.y;
            if (src.x > dst.x) swap(src.x, dst.x);
            if (src.y > dst.y) swap(src.y, dst.y);

            ll r = lrand();
            Bit2D::add(dst.x, dst.y, r);
            Bit2D::add(src.x, src.y, r);
            Bit2D::add(dst.x, src.y, -r);
            Bit2D::add(src.x, dst.y, -r);

            S[t] = src, D[t] = dst, V[t] = r;
        }  //
        else if (op == 2) {
            int a;
            cin >> a;

            ll r = V[a];
            pii src = S[a];
            pii dst = D[a];
            Bit2D::add(dst.x, dst.y, -r);
            Bit2D::add(src.x, src.y, -r);
            Bit2D::add(dst.x, src.y, r);
            Bit2D::add(src.x, dst.y, r);
        }  //
        else {
            pii src, dst;
            cin >> src.x >> src.y >> dst.x >> dst.y;
            ll a = Bit2D::get(src.x, src.y);
            ll b = Bit2D::get(dst.x, dst.y);
            cout << (a == b ? "Y" : "N");
        }
    }
    cout << endl;
    return 0;
}
