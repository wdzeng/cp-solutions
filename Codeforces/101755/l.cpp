#include <bits/stdc++.h>
using namespace std;
string s;
int table[200005][26];
vector<int> v;

bool pu() {
    char c;
    cin >> c;
    int d = c - 'a';
    if (v.empty()) {
        v.push_back(table[0][d]);
    }  //
    else {
        int curloc = v.back();
        if (curloc == -1)
            v.push_back(-1);
        else
            v.push_back(table[curloc + 1][d]);
    }
    return v.back() != -1;
}

bool pp() {
    v.pop_back();
    return v.empty() || v.back() != -1;
}

void build_table() {
    memset(table, -1, sizeof(table));
    string ss = s;
    for (int i = ss.size() - 1; i >= 0; --i) {
        char c = ss[i];
        int d = c - 'a';
        for (int j = i; j >= 0; j--) {
            table[j][d] = i;
            if (j == 0 || ss[j - 1] == c) break;
        }
    }
}

int main() {
    cin >> s;
    int q;
    cin >> q;
    build_table();
    /* for (int i = 0; i < 3; i++) {
        for (int j = 0; j < s.size(); j++) printf("%2d ", table[j][i]);
        cout << endl;
    } */
    while (q--) {
        string o;
        cin >> o;
        bool ret = o == "push" ? pu() : pp();
        cout << (ret ? "YES\n" : "NO\n");
    }
    return 0;
}