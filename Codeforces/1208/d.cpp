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

class BIT {
   private:
    int n;
    vector<ll> a;

    ll sum(int i) {
        i++;
        ll r = 0;
        while (i > 0) assert(0 <= i && i < a.size()), r += a[i], i -= i & -i;
        return r;
    }

   public:
    // Constructs an binary indexed tree with all values initialized to 0, where n is size of array.
    BIT(int n) : n(n) { a.resize(n + 1); }
    // Increases element at index i by value v.
    void add(int i, ll v) {
        i++;
        while (i <= n) assert(0 <= i && i < a.size()), a[i] += v, i += i & -i;
    }
    // Queries sum in [l, r].
    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        ll val;
        cin >> val;
        v.push_back(val);
    }

    BIT bit(n + 1);
    for (int i = 0; i <= n; i++) bit.add(i, i);

    list<int> ans;
    while (v.size()) {
        int l = 0, r = n;
        while (l < r) {
            int m = (l + r) >> 1;
            if (bit.sum(0, m) <= v.back())
                l = m + 1;
            else
                r = m;
        }
        bit.add(l, -l);
        ans.push_front(l);
        v.pop_back();
    }

    for (int a : ans) cout << a << ' ';
    cout << endl;
    return 0;
}