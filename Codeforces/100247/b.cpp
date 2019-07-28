#include <bits/stdc++.h>
using namespace std;

string normalize(string s) {
    string ret = "";
    int table[26] = {0};
    int cnt = 0;
    for (char c : s) {
        int idx = c - 'a';
        if (table[idx] == 0) table[idx] = ++cnt;
        ret.push_back(table[idx]);
    }
    return ret;
}

int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    unordered_map<string, int> mmap;
    int n;
    cin >> n;

    long long ans = 0;
    while (n--) {
        string s;
        cin >> s;
        s = normalize(s);
        ans += mmap[s];
        mmap[s]++;
    }

    cout << ans << endl;
    return 0;
}