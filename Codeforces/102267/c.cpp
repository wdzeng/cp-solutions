#include <iostream>
using namespace std;
int main() {
    int n, x; cin >> n >> x;
    int ans = 0;
    while(n>0) {
        n/=x;
        ans++;
    }
    cout << ans << endl;
    return 0;
}