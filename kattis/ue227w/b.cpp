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
#define debug(a) cerr << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

int main() {
    fastio();
    int n, w;
    cin >> n >> w;
    vector<int> sc(n);
    for (int& val : sc) cin >> val;
    int added = 0;
    int suml = 0;
    int sumr = 0;
    for (int val : sc) suml += val, sumr += val;

    for (int i = 0; i < 10000; i++) {
        if (suml <= (n + added) * w && sumr >= (n + added) * w) {
            cout << added << endl;
            return 0;
        }
        added++;
        sumr += 100;
    }
        cout << "impossible" << endl;
    return 0;
}