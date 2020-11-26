#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
#define x first
#define y second
typedef pair<int, int> point;

bool cmp(const point& a, const point& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int upperbound(int k, const vector<int>& tails) {
    int left = 0, right = tails.size() - 1;
    while (right > left) {
        int mid = (left + right) / 2;
        int t = tails[mid];
        if (t > k)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int lis_length(const vector<point>& v, const int n) {
    vector<int> tails;
    tails.push_back(v[0].y);

    for (int i = 1; i < n; i++) {
        if (v[i].y < tails[0]) {
            tails[0] = v[i].y;
            continue;
        }  //
        if (v[i].y > tails.back()) {
            tails.push_back(v[i].y);
            continue;
        }
        int index = upperbound(v[i].y, tails);
        tails[index] = v[i].y;
    }

    return tails.size();
}

int solve() {
    int n;
    cin >> n;
    vector<point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }
    sort(pts.begin(), pts.end(), cmp);
    return lis_length(pts, n);
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    return 0;
}