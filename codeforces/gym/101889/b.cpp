#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

int vow(char c) {
    return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string s;
    cin >> s;
    int a = 0;
    for (char c : s)
        if (vow(c)) a += 1;
    if (!a) {
        cout << 1 << endl;
        return 0;
    }
    if (!vow(s[0])) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> v;
    int len = 0;
    for (int i = 1; i < zz(s); i++) {
        if (vow(s[i])) {
            v.push_back(len);
            len = 0;
        } else
            len++;
    }
    v.push_back(len);
    cout << v[(zz(v) - 1) / 2] + 1 << endl;

    return 0;
}