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

ll arr[10000];
const ll p = 2e9 + 99;
const ll x = 1e6 + 99;
int n;

bool judge(int k) {
    ll h = 0;
    ll X = 1;
    for (int i = 0; i < k; i++) h = (h * x + arr[i]) % p;
    for (int i = 1; i < k; i++) X = X * x % p;
    unordered_map<ll, ll> m;
    for (int i = k; i < n; i++) {
        if (m.count(h)) {
            if (m[h] != arr[i]) {
                return 0;
            }
        }
        m[h] = arr[i];
        h -= arr[i - k] * X;
        h = (h % p + p) % p;
        h = (h * x + arr[i]) % p;
    }
    return 1;
}

bool judge1(int k) {
    list<ll> l;
    for (int i = 0; i < k; i++) l.push_back(arr[i]);
    map<list<ll>, ll> m;
    for (int i = k; i < n; i++) {
        if (m.count(l) && m[l] != arr[i]) return 0;
        m[l] = arr[i];
        l.pop_front();
        l.push_back(arr[i]);
    }
    return 1;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] += 1e9 + 1;
    }
    if (unordered_set<ll>(arr, arr + n).size() == 1) {
        cout << 0 << endl;
        return 0;
    }

    int l = 1, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (judge(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;
    return 0;
}