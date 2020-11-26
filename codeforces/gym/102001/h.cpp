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

/**
 * Support single element increment and range sum query.
 *
 * Time Complexity: O(QlogN)
 * Space Complexity: O(N)
 */
class BIT {
   private:
    int n;
    vector<ll> a;

    ll sum(int i) {
        i++;
        ll r = 0;
        while (i > 0) r += a[i], i -= i & -i;
        return r;
    }

   public:
    // Constructs an binary indexed tree with all values initialized to 0, where n is size of array.
    BIT(int n) : n(n) { a.resize(n + 1); }
    // Increases element at index i by value v, where i in [1, n].
    void add(int i, ll v) {
        i++;
        while (i <= n) a[i] += v, i += i & -i;
    }
    // Queries sum in [l, r], where l and r in [1, n].
    ll sum(int l, int r) { return sum(r) - sum(l - 1); }
};

struct cmd {
    int l, r, req;
    cmd(int l, int r, int q) : l(l), r(r), req(q) {}
    bool operator<(const cmd& c) const { return r < c.r; }
};

void foul() {
    cout << "Impossible\n";
    exit(0);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    BIT b(n);
    set<int> hole;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) hole.insert(i), x = -1;
        b.add(i, x);
    }

    vector<cmd> cmds;
    while (q--) {
        int l, r, req;
        cin >> l >> r >> req;
        l--, r--;
        cmds.emplace_back(l, r, req);
    }
    sort(iter(cmds));
    for (auto& c : cmds) {
        int s = b.sum(c.l, c.r);
        while (s < c.req) {
            auto a = hole.upper_bound(c.r);
            if (a == hole.begin()) foul();
            a--;
            int i = *a;
            b.add(i, 2);
            s += 2;
            hole.erase(a);
        }
    }

    for (int i = 0; i < n; i++) cout << b.sum(i, i) << ' ';
    cout << '\n';
    return 0;
}