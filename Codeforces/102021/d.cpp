#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

vector<ll> arr, arr1 = {0};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x; arr.push_back(x);
    }

    for (int v : arr) {
        arr1.push_back(v - arr1.back());
    }

    ll minn1 = 1e15;
    for (int i = 0; i < arr1.size(); i += 2) minn1 = min(minn1, arr1[i]);
    ll minn2 = 1e15;
    for (int i = 1; i < arr1.size(); i += 2) minn2 = min(minn2, arr1[i]);
    ll ans = minn2 + minn1 + 1;
    cout << max(ans, 0ll) << endl;
    return 0;
}