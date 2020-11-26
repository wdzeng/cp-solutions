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

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/** 普通 BIT ，為了加速打字只支援 1-based **/
const int maxn = 600000;  // 開全域加速打字
struct BIT {
    vector<ll> a = vector<ll>(maxn);
    ll sum(int i) {
        ll r = 0;
        while (i > 0) r += a[i], i -= i & -i;
        return r;
    }
    // size = maxn 的空 BIT ，所有元素都是零
    BIT() {}
    // 注意 1-based
    void add(int i, ll v) {
        while (i <= maxn) a[i] += v, i += i & -i;
    }
    // 注意 1-based
    ll sum(int l, int r) { return sum(r) - sum(l - 1); }
};
BIT bit;
bitset<maxn + 1> bs;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        int v;
        cin >> v;
        v = min(maxn, v);
        if (bs[0]) {
            cout << "No\n";
            continue;
        }
        if (bit.sum(1, v) == v && bit.sum(1, maxn) > bit.sum(1, v)) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        while (bs[v]) {
            bit.add(v, -1);
            bs[v] = 0;
            v--;
        }
        bs[v] = 1;
        if (v > 0) bit.add(v, 1);
    }
    return 0;
}
