#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

const int maxn = 1299709 + 10;

int main() {
    freopen("B.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    bool not_prime[maxn];
    vector<int> prime;
    ms(not_prime);
    for (int i = 2; i < maxn; i++) {
        if (not_prime[i]) continue;
        prime.push_back(i);
        int e = i + i;
        while (e < maxn) {
            not_prime[e] = 1;
            e += i;
        }
    }

    int n;
    while (cin >> n && n != 0) {
        auto l = lower_bound(iter(prime), n);
        if (*l == n || l == prime.begin())
            cout << 0 << endl;
        else {
            int u = *l;
            int v = *(l - 1);
            cout << (u - v) << endl;
        }
    }
    return 0;
}