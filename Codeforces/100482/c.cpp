#include <bits/stdc++.h>
using namespace std;
// AC
string str;
int arr[100001 * 4][26];

void update(int index, int lran, int rran, int l, int r) {
    if (rran < l || lran > r) return;
    if (lran == rran) {
        for (char c = 'A'; c <= 'Z'; c++) arr[index][c - 'A'] = (c == str[lran]);
        return;
    }
    update(index * 2 + 1, lran, (lran + rran) / 2, l, r);
    update(index * 2 + 2, (lran + rran) / 2 + 1, rran, l, r);
    for (char c = 'A'; c <= 'Z'; c++) {
        arr[index][c - 'A'] = arr[index * 2 + 1][c - 'A'] + arr[index * 2 + 2][c - 'A'];
    }
}

void query(int index, int lran, int rran, int l, int r, int dest[26]) {
    if (rran < l || lran > r) return;
    if (l <= lran && rran <= r) {
        for (char c = 'A'; c <= 'Z'; c++) dest[c - 'A'] += arr[index][c - 'A'];
        return;
    }
    query(index * 2 + 1, lran, (lran + rran) / 2, l, r, dest);
    query(index * 2 + 2, (lran + rran) / 2 + 1, rran, l, r, dest);
}

void solve() {
    cin >> str;
    update(0, 0, str.length() - 1, 0, str.length() - 1);
    int q;
    cin >> q;
    while (q--) {
        char o;
        int l, r;
        cin >> o >> l >> r;
        if (o == 's') {
            sort(str.begin() + l, str.begin() + r + 1);
            update(0, 0, str.length() - 1, l, r);
        }  //
        else {
            int dest[26];
            memset(dest, 0, sizeof(dest));
            query(0, 0, str.length() - 1, l, r, dest);
            for (int i : dest) cout << i << " ";
            cout << "\n";
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}