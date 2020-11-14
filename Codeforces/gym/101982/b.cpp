#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

const int N = 1e7 + 5;
int mu[N];
int np[N];

void init() {
    np[1] = mu[1] = 1;
    vector<int> primes;
    for (int i = 2; i < N; i++) {
        if (!np[i]) mu[i] = -1, primes.push_back(i);
        for (auto& p : primes) {
            if (i * p > N) break;
            np[i * p] = 1;
            if (i % p == 0) {
                mu[i * p ]  = 0;
                break;
            }
            mu[i * p] = -mu[i];
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    init();

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    ll ans = 0;
    for (int p = 1; p <= min(b, d); p++) {
        ans += (ll)mu[p] * (b / p - (a - 1) / p) * (d / p - (c - 1) / p);
    }
    cout << ans << endl;
    return 0;
}