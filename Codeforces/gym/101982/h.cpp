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

const int N = 1e6 + 5;
int np[N];
vector<int> primes;

int nxt(int n) {
    int ret = 0;
    for (int p : primes) {
        if (p >= n) break;
        int q = n - p;
        if (binary_search(all(primes), q)) {
            return q - p;
        }
    }
    assert(0);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    for (int i = 2; i * i <= N; i++) {
        if (np[i]) continue;
        for (int a = i * i; a < N; a += i)
            np[a] = 1;
    }
    for (int i = 2; i < N; i++)
        if (!np[i]) primes.push_back(i);

    int n;
    cin >> n;
    int cnt = 0;
    while (n >= 4) {
        n = nxt(n);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}