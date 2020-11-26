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

int decp(int v, int s) {
    int a = s, b = s;
    while (1) {
        if (v % a == 0) return a;
        if (v % b == 0) return b;
        a--, b++;
    }
}

void decomp(int v, int& a, int& b, int& c) {
    int s = round(cbrt(v));
    a = decp(v, s);
    b = decp(v / a, s);
    c = v / a / b;
}

int main() {
    int v;
    cin >> v;
    int minans = 1e9;
    for (int i = 1; i <= v; i++) {
        if (v % i) continue;
        for (int j = 1; j <= v / i; j++) {
            if (v / i % j) continue;
            int k = v / i / j;
            minans = min(minans, i * j + j * k + k * i);
        }
    }

    cout << minans * 2 << endl;
    return 0;
}