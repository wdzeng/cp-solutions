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

struct davidtree {
    vector<bool> stamp;
    vector<int> arrlen;
    vector<int> arridx;
    int N;

    davidtree(int n) : N(n) {
        arrlen.assign(4 * n, INT_MAX);
        arridx.assign(4 * n, -1);
        stamp.assign(4 * N, false);
        stamp[0] = true;
    }

    // set all values in [l, r] to v.
    void range_set(int l, int r, int i, int len) { range_set(0, 0, N - 1, l, r, i, len); }

    // at index i, this node represents range [curl, curr]; a user wants to set [tarl, tarr] to value v.
    void range_set(int i, int curl, int curr, int tarl, int tarr, int idx, int len) {
        // no intersection
        if (curl < tarr || curr > tarl) {
            stamp[i] = true;
            return;
        }
        // combined
        if (tarl <= curl && curr <= tarr) {
            if (len < arrlen[i]) {
                arrlen[i] = len;
                arridx[i] = idx;
            }
            stamp[i] = true;
            return;
        }

        // kick down
        if (stamp[i]) {
            stamp[i * 2 + 1] = true;
            stamp[i * 2 + 2] = true;
            arrlen[i * 2 + 1] = len;
            arridx[i * 2 + 1] = idx;
            arrlen[i * 2 + 2] = len;
            arridx[i * 2 + 2] = idx;
        }
        // go down
        int m = (curl + curr) / 2;
        range_set(i * 2 + 1, curl, m, tarl, tarr, idx, len);
        range_set(i * 2 + 2, m + 1, curr, tarl, tarr, idx, len);
        stamp[i] = false;
    }

    int query(int i) { query(0, 0, N - 1, i); }

    // at tree index i, this node represents range [curl, curr]; a user wants to query array index tar;
    // the function returns the value that locates at array index tar.
    int query(int i, int curl, int curr, int tar) {
        if (stamp[i]) return arridx[i];
        int m = (curl + curr) / 2;
        // l: curl ~ m
        // r: m+1 ~ curr
        if (tar <= m)
            return query(i * 2 + 1, curl, m, tar);
        else
            return query(i * 2 + 2, m + 1, curr, tar);
    }
};

vector<int> all_nums;
int disc(int x) {
    auto a = lower_bound(all_nums.begin(), all_nums.end(), x);
    // a == all_nums.end();
    return a - all_nums.begin();
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);

    vector<pii> segments;
    vector<int> queries;

    int nseg;
    cin >> nseg;
    for (int i = 0; i < nseg; i++) {
        pii s;
        cin >> s.first >> s.second;
        segments.push_back(s);
        all_nums.push_back(s.first);
        all_nums.push_back(s.second);
    }

    int nq;
    cin >> nq;
    while (nq--) {
        int x;
        cin >> x;
        queries.push_back(x);
        all_nums.push_back(x);
    }

    sort(iter(all_nums));

    davidtree dt(all_nums.size());
    for (int i = 0; i < nseg; i++) {
        dt.range_set(disc(segments[i].first), disc(segments[i].second), i, segments[i].second - segments[i].first);
    }

    for (int q : queries) {
        // cout << disc(q) << endl;
        cout << dt.query(disc(q)) << endl;
    }

    return 0;
}