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
#ifdef hy
#define fastio()
#define debug(a) cout << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

int solve0(int w, int h, int a, int b, int c) {
    int W = b + b + a;
    int H = b + b + c + c;
    if (W <= w && H <= h) return 1;
    W = b + c + b + a;
    H = a + b + c;
    if (W <= w && H <= h) return 1;
    W = b + a + b + c + b;
    H = a + c;
    if (W <= w && H <= h) return 1;
    return 0;
}

int solve(int w, int h, int a, int b, int c) {
    return solve0(w, h, a, b, c) ||
           solve0(w, h, a, c, b) ||
           solve0(w, h, b, a, c) ||
           solve0(w, h, b, c, a) ||
           solve0(w, h, c, a, b) ||
           solve0(w, h, c, b, a);
}

int main() {
    fastio();
    int a, b, c, w, h;
    cin >> a >> b >> c >> w >> h;
    int ans = solve(w, h, a, b, c) || solve(h, w, a, b, c);
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}