#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define mp(x, y) make_pair(x, y)
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))
#define debt first
#define profit second

struct SegmentTree {
    int n;
    vector<pll> array;
    SegmentTree(int n) : n(n) { array.assign(n * 4, {0, 0}); }
    pll update(int index, int l, int r, int val, int curl, int curr) {
        if (curr < l || curl > r) return array[index];
        if (curl == curr) return array[index] = val < 0 ? mp(-val, 0) : mp(0, val);

        int mid = (curl + curr) / 2;
        pll left = update(index * 2 + 1, l, r, val, curl, mid);
        pll right = update(index * 2 + 2, l, r, val, mid + 1, curr);
        return array[index] = left.profit > right.debt ? mp(left.debt, right.profit + left.profit - right.debt)
                                                       : mp(left.debt + right.debt - left.profit, right.profit);
    }
    void update(int l, int val) { update(0, l, l, val, 0, n - 1); }
    ll balance() { return array[0].debt ? -array[0].debt : 0; }
};

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int n;
    cin >> n;
    SegmentTree st(n);
    vector<pair<int, string>> val;
    vector<string> order;
    for (int i = 0; i < n; i++) {
        string date, time;
        int m;
        cin >> m >> date >> time;
        swap(date[0], date[3]), swap(date[1], date[4]);
        date = date += time;
        val.push_back({m, date}), order.push_back(date);
    }
    sort(iter(order));
    for (int i = 0; i < n; i++) {
        int v = val[i].first, r = lower_bound(iter(order), val[i].second) - order.begin();
        st.update(r, v);
        cout << st.balance() << "\n";
    }
    return 0;
}