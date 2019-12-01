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
#define mss(a) memset(a, 1, sizeof(a))
#define mp(e, f) make_pair(e, f)

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int a[n], b[n];
    int w = 0, l = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i])
            w++;
        else
            l++;
    }

    vector<int> merged;
    for (int i = 0; i < n - 1 && w <= l; i++) {
        if (a[i] > b[i] && a[i + 1] > b[i + 1]) continue;
        if ((a[i] > b[i] != a[i + 1] > b[i + 1]) && a[i] + a[i + 1] <= b[i] + b[i + 1]) continue;
        l--;
        merged.push_back(i);
        i++;
    }
    if (w <= l) {
        cout << "-1\n";
        return 0;
    }

    cout << merged.size() << endl;
    for (int m : merged) cout << m + 1 << ' ' << m + 2 << endl;
    return 0;
}