#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    string s;
    cin >> s;
    if (s.size() % 2) cout << "NO\n", exit(0);

    vector<int> vec(26, 0);
    for (char c : s)
        if (++vec[c - 'a'] > s.size() / 2) cout << "NO\n", exit(0);

    cout << "YES\n";
    return 0;
}