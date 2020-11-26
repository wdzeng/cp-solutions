#include <bits/stdc++.h>
using namespace std;

bool rep(string& s, int left, int right, int range) {
    for (int i = left; i <= right; i++) {
        int index = left + (i - left) % range;
        if (s[i] != s[index]) return false;
    }
    return true;
}

int solve(string& s) {
    int table[s.size()][s.size()];
    for (int i = 0; i < s.size(); i++) table[i][i] = 1;
    for (int i = 0; i < s.size() - 1; i++) table[i][i + 1] = 2;

    for (int len = 3; len <= s.size(); len++) {
        for (int left = 0; left + len <= s.size(); left++) {
            int right = left + len - 1;
            table[left][right] = len;
            for (int mid = left + 1; mid <= right; mid++) {
                int anotherlen = table[left][mid - 1] + table[mid][right];
                table[left][right] = min(table[left][right], anotherlen);
            }
            for (int range = 1; range <= len / 2; range++) {
                if (len % range != 0) continue;
                if (!rep(s, left, right, range)) continue;
                int nrep = len / range;
                int realrange = table[left][left + range - 1];
                int strlen = to_string(nrep).size() + realrange + (realrange > 1 ? 2 : 0);
                table[left][right] = min(table[left][right], strlen);
            }
        }
    }

    return table[0][s.size() - 1];
}

int main() {
    string s;
    int t = 0;
    while (cin >> s && s != "0") printf("Case %d: %d\n", ++t, solve(s));
    return 0;
}