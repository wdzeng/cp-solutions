#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    vector<int> ia(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ia[i] = a[i];
    }
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> indexes(20001);
    for (int i = 0; i < n; i++) indexes[a[i] + 10000] = i;

    for(int i: ia) {
        int index = indexes[i+10000]; cout << b[index] << endl;
    }
    cout << endl;
}

int main() {
    int n;
    while ((cin >> n) && n) solve(n);
    return 0;
}