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

void solve(int i) {
    if (i)
        cout << "Win" << endl;
    else
        cout << "Lose" << endl;
    exit(0);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int one = 0, two = 0, more = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1)
            one++;
        else if (x == 2)
            two++;
        else
            more++;
    }
    if (one == n) solve(n % 3 != 0);
    if (one == n - 1) solve(1);
    if (one == n - 2) solve(one % 3 != 0 and two > 0);
    solve(0);

    return 0;
}