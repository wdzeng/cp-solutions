#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int group(ll m) { return (-1 + sqrt(1 + 8 * m)) / 2; }

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        ll m;
        cin >> n >> m;
        m--;
        int g = group(m);
        ll gall = (ll)g * (g + 1) / 2;
        m -= gall;
        printf("Case %d: %d %d\n", i, g, (int)m);
    }
    return 0;
}