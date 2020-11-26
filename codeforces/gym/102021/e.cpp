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

int bdigit(string a) {
    int i = a.find_first_of('.');
    if (i == -1) return 0;
    return a.size() - i - 1;
}

const int maxn = 1e7 + 20;
const int sqrtn = sqrt(maxn) + 10;
bitset<maxn> isprime;

void init() {
    isprime.flip();
    isprime[1] = 0;
    for (int i = 2; i <= sqrtn; i++) {
        if (!isprime[i]) continue;
        int x = i + i;
        while (x <= maxn) {
            isprime[x] = 0;
            x += i;
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    init();
    int n;
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a >> b;

        int mx = max(bdigit(a), bdigit(b));
        double d = pow(10, mx);
        int ra = round(stod(a) * d);
        int rb = round(stod(b) * d);
        int g = __gcd(ra, rb);
        ra /= g;
        rb /= g;
        if (ra == 1 && rb == 1) {
            cout << "2 2\n";
        } else if (!isprime[ra] || !isprime[rb]) {
            cout << "impossible\n";
        } else {
            cout << ra << ' ' << rb << endl;
        }
    }
    return 0;
}