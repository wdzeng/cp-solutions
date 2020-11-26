#include <bits/stdc++.h>
using namespace std;

bool solve() {
    string s;
    vector<int> vec(26, 0);
    while (cin >> s && s != "*") {
        for (char c : s) vec[tolower(c) - 'a']++;
    }
    vector<int> ii(26);
    for (int i = 0; i < 26; i++) ii[i] = i;
    sort(ii.begin(), ii.end(), [&](int a, int b) { return vec[a] == vec[b] ? (a > b) : (vec[a] > vec[b]); });
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int idx = ii[i];
        if (!vec[idx]) break;
        sum += idx;
    }
    return sum > 62;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case %d: %s\n", i, solve() ? "Effective" : "Ineffective");
    }
    return 0;
}