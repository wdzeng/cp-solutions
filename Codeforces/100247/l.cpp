#include <bits/stdc++.h>
using namespace std;

// AC
unordered_map<int, int> mmap;

int x(int i) { return i / 2 + 1; }

int solve(int n) {
    if (mmap[n] != 0) return mmap[n];
    int minn = x(n);
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) minn = min(minn, x(i) * solve(n / i));
    }
    return mmap[n] = minn;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}