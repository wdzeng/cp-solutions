#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    bool flag = false;
    for (int i = 0; i < x; i++) {
        if (a[i] != b[i])
            flag = true;
        else {
            if (flag) ans++;
            flag = false;
        }
    }
    if(flag) ans++;

    cout << ans << endl;
}