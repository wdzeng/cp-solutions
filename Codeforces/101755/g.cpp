#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mn(x) memset(x, -1, sizeof(x))
int N, K;

struct BIT {
    int n;
    vector<ll> bitarray;
    BIT(int n) : n(n) { bitarray.assign(n + 1, 0); }
    void add(int index, int val) {
        index++;
        while (index <= n) bitarray[index] += val, index += index & -index;
    }
    ll query(int index) const {
        index++;
        ll ret = 0;
        while (index > 0) ret += bitarray[index], index -= index & -index;
        return ret;
    }
};

struct CounterBIT {
    vector<bool> rec;
    BIT bit;
    CounterBIT(int n) : bit(n) { rec.assign(n, false); }
    void inc(int index) {
        if (!rec[index]) rec[index] = true, bit.add(index, 1);
    }
    void dec(int index) {
        if (rec[index]) rec[index] = false, bit.add(index, -1);
    }
    ll query(int index) const { return bit.query(index); }
};

struct SumBIT {
    int ninsert = 0;
    vector<bool> rec;
    vector<int> tvec;
    BIT bit;
    SumBIT(const vector<int>& vec) : tvec(vec), bit(vec.size()) {
        rec.assign(vec.size(), false);
        sort(iter(tvec));
    }
    void insert(int index) {
        if (!rec[index]) ninsert++, rec[index] = true, bit.add(index, tvec[index]);
    }
    void remove(int index) {
        if (rec[index]) ninsert--, rec[index] = false, bit.add(index, -tvec[index]);
    }
    ll query(int index) const { return bit.query(index); }
    int size() const { return ninsert; }
};

vi ranksort(const vector<int>& vec) {
    vi indices(vec.size());
    for (int i = 0; i < vec.size(); i++) indices[i] = i;
    sort(iter(indices), [&vec](int i, int j) { return vec[i] < vec[j]; });
    vi rank(vec.size());
    for (int i = 0; i < vec.size(); i++) rank[i] = i;
    sort(iter(rank), [&indices](int i, int j) { return indices[i] < indices[j]; });
    return rank;
}

ll solve(const vector<int>& vec, const vector<int>& rnk, int initloc) {
    int loc = initloc;
    auto findleft = [&loc]() {
        int initl = K - 1 - loc;
        if (initl > loc) return initl;
        return loc + ((K % 2) ? 2 : 1);
    };
    auto findright = [&loc]() {
        int r = loc + K - 1;
        if (r < N) return r;
        int lmleft = N - K;
        int move = loc - lmleft;
        return N - 1 - move;
    };
    int l = findleft(), r = findright();
    if (l < 0 || l >= N || r < 0 || r >= N) return 0;

    ll ret = 0;
    CounterBIT indices(N);
    SumBIT sum(vec);
    indices.inc(rnk[l]), sum.insert(rnk[l]), indices.inc(rnk[r]), sum.insert(rnk[r]);

    while (l <= r) {
        ll nleft = indices.query(rnk[loc]), nright = sum.size() - nleft;
        ll sleft = sum.query(rnk[loc]), sright = sum.query(N - 1) - sleft;
        ll inc = vec[loc] * nleft - sleft + sright - vec[loc] * nright;
        ret += inc;

        loc += 2;
        int newl = findleft();
        if (newl == l + 2) {
            indices.dec(rnk[l]);
            sum.remove(rnk[l]);
            l += 2;
        } else if (newl == l - 2) {
            l -= 2;
            indices.inc(rnk[l]);
            sum.insert(rnk[l]);
        }

        int newr = findright();
        if (newr == r + 2) {
            r += 2;
            indices.inc(rnk[r]);
            sum.insert(rnk[r]);
        } else if (newr == r - 2) {
            indices.dec(rnk[r]);
            sum.remove(rnk[r]);
            r -= 2;
        }
    }
    return ret;
}

ll solve() {
    cin >> N >> K;
    vi val(N);
    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }
    if (N == 1) return 0;
    vi rnk = ranksort(val);
    return solve(val, rnk, 0) + solve(val, rnk, 1);
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}