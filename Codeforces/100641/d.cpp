#include <bits/stdc++.h>
using namespace std;

struct vector_set {
    int arr[5001];
    int flag = 0;
    void clear() {
        memset(arr, -1, sizeof(arr));
        flag = 0;
    }
    void insert(int i) {
        if (arr[i] != -1) return;
        arr[i] = flag;
        flag = i;
    }
    void merge(vector_set& a, vector_set& b) {
        for (int i = a.flag; i > 0; i = a.arr[i]) {
            for (int j = b.flag; j > 0; j = b.arr[j]) {
                insert((i >= j) ? (i + j) : (j - i));
            }
        }
    }
    bool empty() { return flag == 0; }
};

vector_set table[50][50];

int val(char c) {
    switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
    }
    throw "";
}

vector_set& find(const string& s, int l, int r) {
    if (!table[l][r].empty()) return table[l][r];

    unordered_set<int> ret;
    for (int mid = l + 1; mid <= r; mid++) {
        table[l][r].merge(find(s, l, mid - 1), find(s, mid, r));
    }
    return table[l][r];
}

void solve(string str) {
    for (int i = 0; i < str.size(); i++)
        for (int j = i; j < str.size(); j++) table[i][j].clear();

    for (int i = 0; i < str.size(); i++) table[i][i].insert(val(str[i]));

    auto& sset = find(str, 0, str.size() - 1);
    vector<int> ans;
    for (int i = sset.flag; i > 0; i = sset.arr[i]) ans.push_back(i);
    sort(ans.begin(), ans.end());
    for (int x : ans) cout << x << " ";
}

int main() {
    string str;
    int t = 0;
    while (cin >> str && str != "0") {
        printf("Case %d: ", ++t);
        solve(str);
        cout << endl;
    }
}