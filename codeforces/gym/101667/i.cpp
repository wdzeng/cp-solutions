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
int prv[N];
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto& val : vec) cin >> val;
    reverse(all(vec));
    prv[0] = -1;
    int ansk = 1e7, ansp = 1e7;
    for (int i = 0; i < n; i++) {
        int p = i - prv[i];
        int k = n - i - 1;
        if (p + k < ansk + ansp)
            ansk = k, ansp = p;
        else if (p + k == ansk + ansp && p < ansp)
            ansk = k, ansp = p;
        int j = prv[i];
        while (~j && vec[j + 1] != vec[i + 1]) j = prv[j];
        if (vec[j + 1] == vec[i + 1])
            prv[i + 1] = j + 1;
        else
            prv[i + 1] = -1;
    }
    cout << ansk << ' ' << ansp << endl;
    return 0;
}