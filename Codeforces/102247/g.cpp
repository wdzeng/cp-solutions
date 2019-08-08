#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i * i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i * i + j * j == n) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}