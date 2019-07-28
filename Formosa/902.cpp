#include <iostream>
using namespace std;

 // AC

void solve1(int r, int c) {
    r--;
    c--;
    long val = 0;
    long parser = 1;
    while (r || c) {
        if (c & 1) {
            val |= parser;
        }
        parser <<= 1;
        c >>= 1;
        if (r & 1) {
            val |= parser;
        }
        parser <<= 1;
        r >>= 1;
    }
    cout << val + 1 << "\n";
}

void solve2(long val, int n) {
    val--;
    int r = 0, c = 0;
    long parser = (long)1 << (n * 2 - 1);
    while (parser) {
        r <<= 1;
        if (val & parser) {
            r |= 1;
        }
        parser >>= 1;
        c <<= 1;
        if (val & parser) {
            c |= 1;
        }
        parser >>= 1;
    }
    cout << r + 1 << " " << c + 1 << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        while (q--) {
            int mode;
            cin >> mode;
            if (mode == 1) {
                int r, c;
                cin >> r >> c;
                solve1(r, c);
            }  //
            else {
                long val;
                cin >> val;
                solve2(val, n);
            }
        }
    }
    return 0;
}