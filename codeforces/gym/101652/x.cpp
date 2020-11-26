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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int s;
    cin >> s;
    cout << s << ":\n";
    for (int i = 2; i < s; i++) {
        int sum = 0;
        int f = 1;
        while (sum < s) {
            sum += (f ? i : (i - 1));
            f = !f;
        }
        if (sum == s) cout << i << ',' << i - 1 << '\n';
        if (s % i == 0) cout << i << ',' << i << '\n';
    }

    return 0;
}