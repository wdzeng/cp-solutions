#include <bits/stdc++.h>
using namespace std;

bool trap(string s) {
    bool press1 = false, press0 = false;
    for (int c : s) {
        for (int i = 0; i < 7; i++) {
            if (c & 1)
                press1 = !press1;
            else
                press0 = !press0;
            c >>= 1;
        }
    }
    return press0 || press1;
}

int main() {
    string s;
    while (true) {
        getline(cin, s);
        if (s.empty()) break;
        cout << (trap(s) ? "trapped" : "free") << endl;
    }
    return 0;
}