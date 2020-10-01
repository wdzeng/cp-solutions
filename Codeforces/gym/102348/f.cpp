#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

ll p = 0, n = 0, z = 0;
const int N = 2e5 + 10;
int v[N];

void solve(int l, int r) {
    cout << l << ' ' << r << endl;
    if (l == r) return;
    vector<ll> k;
    bool pos;
    for (int i = l; i < r; i++) {
        if (k.empty()) {
            k.push_back(1);
            pos = k[i] > 0;
        } else if ((v[i] > 0) == pos)
            k.back()++;
        else {
            k.push_back(1);
            pos = !pos;
        }
    }

    ll a = 0, b = 0;
    for (int i = 0; i < k.size(); i++) {
        if (i % 2)
            a += k[i];
        else
            b += k[i];
    }
    
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    int prev = 0;
    for (int i = 0; i < n; i++) {
        if (!v[i]) {
            solve(prev, i);
            prev = i + 1;
        }
    }
    solve(prev, n);

    ll e = n * (n + 1) / 2;
    cout << n << ' ' << e - n - p << ' ' << p << endl;

    return 0;
}