#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b) {
    for (int i = 1;; i++) {
        int ia = a.size() - i, ib = b.size() - i;
        if (ia == -1 && ib == -1) return false;
        if (ia == -1) return true;
        if (ib == -1) return false;
        char ca = a[ia], cb = b[ib];
        if (ca != cb) return ca < cb;
    }
    return false;
}

void solve(int maxlen, vector<string>& strings) {
    sort(strings.begin(), strings.end(), cmp);
    for (string& s : strings) {
        int nspace = maxlen - s.size();
        for (int i = 0; i < nspace; i++) cout << " ";
        cout << s << endl;
    }
    // cout << endl;
}

int main() {
    bool first = true;
    string s;
    int maxlen = 0;
    vector<string> strings;
    while (true) {
        getline(cin, s);
        if (s.empty()) {
            if (strings.empty()) return 0;
            if (first)
                first = false;
            else
                cout << endl;
            solve(maxlen, strings);
            strings.clear();
            maxlen = 0;
        }  //
        else {
            maxlen = max(maxlen, (int)s.size());
            strings.push_back(s);
        }
    }
    return 0;
}