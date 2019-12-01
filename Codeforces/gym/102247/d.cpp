#include <iostream>
using namespace std;

void solve() {
    int r, c;
    cin >> r >> c;
    if (r == 10) {
        if (c == 1) {
            cout << "4\nDRRU\n";
        }  //
        else if (c == 12) {
            cout << "4\nDLLU\n";
        }  //
        else if (c == 3 || c == 10) {
            cout << "0\n\n";
        }  //
        else {
            cout << (c - 3) << endl;
            for (int i = c; i > 3; i--) cout << "L";
            cout << endl;
        }
        return;
    }
    if (r == 3) {
        if (c >= 10) {
            cout << (c - 10) << "\n";
            for (int i = c; i > 10; i--) cout << "L";
            cout << endl;
        } else if (c >= 3) {
            cout << (c - 3) << "\n";
            for (int i = c; i > 3; i--) cout << "L";
            cout << endl;
        } else {
            cout << "40\n"
                 << "LLLLLLLLLLLLUUUUUUUUUUUULLLLLLLLLLLLRRDD\n";
        }
        return;
    }
    cout << "40\n"
         << "LLLLLLLLLLLLUUUUUUUUUUUULLLLLLLLLLLLRRDD\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}