#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mn(x) memset(x, -1, sizeof(x))
const int X = 2, MOD = 1e9 + 7;

bool solve() {
    int n;
    cin >> n;
    int arr[4][n];
    ll sum = 0;
    for (int x = 0; x < 4; x++)
        for (int i = 0; i < n; i++) {
            cin >> arr[x][i];
            sum += arr[x][i];
        }
    if (sum % n) return false;
    sum /= n;

    ll xx = 1;
    for (int i = 0; i < n; i++) {
        xx = xx * X % MOD;
    }

    ll hs = 0;
    for (int i = 0; i < n; i++) {
        hs = (hs * X + sum) % MOD;
    }
  //  cout << "* " << hs << endl;

    unordered_set<int> rec;
    ll h0 = 0;
    for (int i = 0; i < n; i++) {
        h0 = (h0 * X + arr[0][i]) % MOD;
    }
   // cout << "h0: " << h0 << endl;

    vector<int> h1 = {0};
    for (int i = 0; i < 2 * n; i++) {
        ll h = h1.back();
        h = (h * X + arr[1][i % n]) % MOD;
        h1.push_back(h);
    }
    for (int i = 0; i < n; i++) {
        ll h = (h0 + h1[i + n] - h1[i] * xx % MOD + MOD) % MOD;
 //       cout << h << endl;
        rec.insert(h);
    }

    vector<int> h2tmp = {0}, h2;
    for (int i = 0; i < 2 * n; i++) {
        ll h = h2tmp.back();
        h = (h * X + arr[2][i % n]) % MOD;
        h2tmp.push_back(h);
    }
    for(int i = 0; i < n; i++) {
        ll h = (h2tmp[i+n] - h2tmp[i] * xx % MOD) + MOD % MOD;
        h2.push_back(h);
    }

    vector<int> h3 = {0};
    for (int i = 0; i < 2 * n; i++) {
        ll h = h3.back();
        h = (h * X + arr[3][i % n]) % MOD;
        h3.push_back(h);
    }
    for (int i = 0; i < n; i++) {
        ll h = (h3[i + n] - h3[i] * xx % MOD + MOD) % MOD;
        h = (hs - h + MOD) % MOD;
        for(int v: h2) {
            if (rec.count((h - v + MOD) % MOD)) return true;
        }
    }

    return false;
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case %d: %s\n", i, solve() ? "Yes" : "No");
    }
    return 0;
}