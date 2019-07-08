#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// AC

struct info {
    int x;
    bool flag;
    bool operator<(const info& i) const { return x == i.x ? (flag) : (x < i.x); }
    info(int x, bool f) : x(x), flag(f){};
};

int solve() {
    int n, lim;
    cin >> n >> lim;
    vector<info> vec;

    int base = n;
    while (n--) {
        int x1, x2, y;
        cin >> x1  >> y >> x2 >> y;
        if (x1 > x2) swap(x1, x2);
        if (x2 - x1 < lim)
            base--;
        else {
            vec.push_back(info(x2 - lim + 1, false));
            vec.push_back(info(x1 + lim, true));
        }
    }

    sort(vec.begin(), vec.end());
    int maxx = 0;
    int sum = 0;
    for (auto& i : vec) {
        // cout << (i.flag? "+": "-") << i.x << endl;
        sum += i.flag ? 1 : -1;
        maxx = max(maxx, sum);
    }
    return maxx + base;
}

int main() {
    int t;
    cin >> t;
    while(t--) cout << solve() << endl;
    return 0;
}