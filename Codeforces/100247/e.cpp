#include <bits/stdc++.h>
using namespace std;
char buff[200005];
vector<vector<int>> sub;

// AC

void dfsset(int x) {
    for (int s : sub[x]) {
        if (buff[s] == '0') buff[s] = buff[x];
        dfsset(s);
    }
}

int dfsreset(int x) {
    if (sub[x].empty()) return buff[x] == '+' ? 1 : -1;
    int score = 0;
    for (int s : sub[x]) score += dfsreset(s);
    if (score == sub[x].size()) {
        buff[x] = '+';
        for (int s : sub[x]) buff[s] = '0';
        return 1;
    }  //
    else if (score == -1 * sub[x].size()) {
        buff[x] = '-';
        for (int s : sub[x]) buff[s] = '0';
        return -1;
    }  //
    else {
        buff[x] = '0';
        return 0;
    }
}

int main() {
    int n;
    cin >> n;
    cin >> buff;
    sub.resize(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        sub[a - 1].push_back(b - 1);
    }
    if (buff[0] == '0') buff[0] = '-';
    dfsset(0);
    // cout << buff << endl;
    dfsreset(0);
    // cout << buff << endl;

    vector<int> ans;
    for (int i = 0; buff[i]; i++)
        if (buff[i] == '+') ans.push_back(i + 1);
    cout << ans.size() << endl;
    for (int a : ans) cout << a << " ";
    cout << endl;
    return 0;
}