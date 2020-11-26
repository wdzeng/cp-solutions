#include <bits/stdc++.h>
using namespace std;

pair<int, int> minmax(vector<pair<int, int>> mmap) {
    double minn = 1000005;
    double maxx = 0;
    int minindex, maxindex;
    for (int i = 0; i < mmap.size(); i++) {
        double val = (double)mmap[i].first / mmap[i].second;
        if (val < minn) {
            minn = val;
            minindex = i;
        }
        if (val > maxx) {
            maxx = val;
            maxindex = i;
        }
    }
    return {minindex, maxindex};
}

int solve() {
    double k;
    int n;
    cin >> k >> n;
    vector<pair<int, int>> mmap;
    while (n--) {
        int x;
        cin >> x;
        mmap.push_back({x, 1});
    }

    int cut = 0;
    while (true) {
        auto mm = minmax(mmap);
        int minindex = mm.first;
        int maxindex = mm.second;
        double maxval = (double)mmap[maxindex].first / mmap[maxindex].second;
        double minval = (double)mmap[minindex].first / mmap[minindex].second;
        if (minval / maxval >= k) return cut;
        mmap[maxindex].second++;
        cut++;
    }
    throw "";
}

int main() {
    cout << solve() << endl;
    return 0;
}