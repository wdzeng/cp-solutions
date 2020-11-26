#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> point;
typedef long long ll;
#define x first
#define y second
const int maxn = 2e5;
int n;
ll x[maxn], y[maxn];

ll doublearea(int a, int b, int c) {
    a %= n, b %= n, c %= n;
    return abs((x[b] - x[a]) * (y[c] - y[a]) - (y[b] - y[a]) * (x[c] - x[a]));
}

int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

    cin >> n;
    vector<point> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    ll minn = LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {
        minn = min(minn, doublearea(i, i+1, i+2));
    }

    cout << minn << endl;
    return 0;
}