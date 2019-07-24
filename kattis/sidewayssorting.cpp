#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b) {
    for (int i = 0; i < a.size(); i++) {
        char c1 = tolower(a[i]);
        char c2 = tolower(b[i]);
        if (c1 != c2) return c1 < c2;
    }
    return false;
}

void solve(int x, int y) {
    vector<string> strings(x);
    for (int i = 0; i < x; i++) cin >> strings[i];
    vector<string> fix_strings;
    for (int i = 0; i < y; i++) {
        string input = "";
        for (int j = 0; j < x; j++) input += strings[j][i];
        fix_strings.push_back(input);
    }
    stable_sort(fix_strings.begin(), fix_strings.end(), cmp);

    for (int j = 0; j < x; j++) {
        for (int i = 0; i < y; i++) {
            cout << fix_strings[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int x, y;
    while (cin >> x >> y) {
        if (x && y)
            solve(x, y);
        else
            break;
    }
    return 0;
}