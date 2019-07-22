#include <bits/stdc++.h>
using namespace std;

bool divine(int a, int b) {
    long long l = (long long)a * b;
    return l % 1000000007 == 1;
}

int solve() {
    int n;
    cin >> n;
    unordered_map<int, int> sett;
    while (n--) {
        int x;
        cin >> x;
        sett[x % 1000000007]++;
    }

    int ret = 0;
    auto it = sett.begin();
    for (; it != sett.end(); it++) {
        if (it->second > 1) ret += divine(it->first, it->first);
        auto it2 = it;
        for (it2++; it2 != sett.end(); it2++) {
            ret += divine(it->first, it2->first);
        }
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) printf("Case #%d: %d\n", i, solve());
    return 0;
}