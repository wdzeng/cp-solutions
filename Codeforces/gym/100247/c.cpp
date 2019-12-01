#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n;
    ll target;
    cin >> n >> target;
    unordered_map<ll, int> mmap;
    ll sum = 0;
    ll ans = 0;
    while (n--) {
        int x;
        cin >> x;
        sum += x;
        if (sum == target) ans++;
        ans += mmap[sum - target];
        mmap[sum]++;
    }

    cout << ans << endl;
    return 0;
}