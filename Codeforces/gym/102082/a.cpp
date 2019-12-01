#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

struct item {
    bool isnum;
    int ival;
    string sval;

    item(int v) : ival(v), isnum(1) {}
    item(const string& v) : sval(v), isnum(0) {}
    bool operator<(const item& a) const {
        if (isnum != a.isnum) return isnum;
        return isnum ? (ival < a.ival) : (sval < a.sval);
    }
};

vector<item> toitems(const string& s) {
    vector<item> ret;
    int ival = -1;
    string sval = "";
    for (char c : s) {
        if (isdigit(c)) {
            if (sval != "") ret.push_back(item(sval)), sval = "";
            if (ival == -1) ival = 0;
            ival = ival * 10 + (c - '0');
        }  //
        else {
            if (ival != -1) ret.push_back(item(ival)), ival = -1;
            sval += c;
        }
    }
    ret.push_back(ival == -1 ? item(sval) : item(ival));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string f;
    cin >> n >> f;
    auto first = toitems(f);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << (toitems(s) < first ? '-' : '+') << endl;
    }

    return 0;
}