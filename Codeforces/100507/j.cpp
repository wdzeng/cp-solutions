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
    int n;
    cin >> n;
    vector<pii> a, b;
    int suma = 0, sumb = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.emplace_back(x, i);
        suma += x;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        b.emplace_back(x, i);
        sumb += x;
    }
    sort(iter(a)), sort(iter(b));
    list<pii> la(iter(a)), lb(iter(b));
    vector<pii> ans;

    int diff = suma - sumb;
    while (!la.empty()) {
        int val;
        // cout << diff << endl;
        if (diff < 0) {
            ans.emplace_back(la.front().second, lb.back().second);
            val = la.front().first - lb.back().first;
            lb.pop_back(), la.pop_front();
        }  //
        else {
            ans.emplace_back(la.back().second, lb.front().second);
            val = la.back().first - lb.front().first;
            la.pop_back(), lb.pop_front();
        }
        diff += val;
    }
    while (!ans.empty()) {
        cout << ans.back().first << " " << ans.back().second << endl;
        ans.pop_back();
    }
    return 0;
}