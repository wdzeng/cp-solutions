#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()

ll solve() {
    int n, t, c;
    cin >> n >> t >> c;
    map<int, int> mmap;
    while (n--) {
        int x;
        cin >> x;
        mmap[x]++;
    }
    vector<pii> vec;
    vec.insert(vec.begin(), mmap.begin(), mmap.end());
    sort(iter(vec), [&](const pii& a, const pii& b) { return a.second > b.second; });

    ll sum = 0;
    ll maxx = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i].first * vec[i].first % c;
        maxx = max(maxx, sum * vec[i].second);
    }
    return maxx;
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case %d: %lld\n", i, solve());
    }
    return 0;
}