#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

ll vhash(vector<int>& vec) {
    const ll X1 = 1e6 + 99, M1 = 1e9 + 87;
    const ll X2 = 1e6 + 33, M2 = 1e9 + 97;
    ll h1 = 0, h2 = 0;
    for (auto& val : vec) {
        h1 = ((h1 * X1 + val) % M1 + M1) % M1;
        h2 = ((h2 * X2 + val) % M2 + M2) % M2;
    }
    return (h1 << 32) | h2;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
#define one(x) __builtin_popcount(x)
#define lower(x) (x % (1 << 15))
#define higher(x) (x >> 15)
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    unordered_map<ll, int> hashtable;
    for (int mask = 0; mask < (1 << 15); mask++) {
        int c0 = one(lower(vec[0]) xor mask);
        vector<int> arr;
        for (int i = 1; i < n; i++) {
            arr.push_back(one(lower(vec[i]) xor mask) - c0);
        }
        hashtable[vhash(arr)] = mask;
    }
    for (int mask = 0; mask < (1 << 15); mask++) {
        int c0 = one(higher(vec[0]) xor mask);
        vector<int> arr;
        for (int i = 1; i < n; i++) {
            arr.push_back(c0 - one(higher(vec[i]) xor mask));
        }
        ll h = vhash(arr);
        if (hashtable.count(h)) {
            cout << (hashtable[h] | (mask << 15)) << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}