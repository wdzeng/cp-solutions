#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t, c, p, s, m, l, delivery, chg[5] = {0, -1, 0, 0, 1};

string n, x, y, z;

map<string, int> small, medium, large;

int main() {
    cin.tie(0), ios::sync_with_stdio(0); 
    freopen("coffee.in", "r", stdin);
    cin >> t;
    while (t--) {
        small.clear(), medium.clear(), large.clear();
        cin >> c >> p;
        while (c--) {
            cin >> n >> s >> m >> l;
            small[n] = s, medium[n] = m, large[n] = l;
        }
        delivery = 100 / p;
        while (p--){
            cin >> x >> y >> z;
            if (y[0] == 's')
                cout << x << ' ' << (small[z] + delivery) + chg[(small[z] + delivery) % 5] << '\n';
            else if (y[0] == 'm')
                cout << x << ' ' << (medium[z] + delivery) + chg[(medium[z] + delivery) % 5] << '\n';
            else
                cout << x << ' ' << (large[z] + delivery) + chg[(large[z] + delivery) % 5] << '\n';
        }
    }
    return 0;
}
