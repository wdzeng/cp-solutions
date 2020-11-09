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

void ok() {
    cout << "YES" << endl;
    exit(0);
}
void foul() {
    cout << "KEK" << endl;
    exit(0);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
#ifndef hy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& val : a) cin >> val;
    int g = max_element(all(a)) - a.begin();

    ll s = 0;
    for (int i = 0; i < g; i++) s += a[i];
    ll S = s;
    for (int i = g + 1; i < n; i++)
        S += a[i];

    int cnt = 1;
    ll minn = g;
    ll maxx = s;
    while (minn <= k) {
        if (minn <= k and k <= maxx) ok();
        minn += (n - 1) + a[g];
        maxx += S + a[g];
    }
    foul();

    return 0;
}