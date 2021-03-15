#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int q, c;
vector<int> times;

bool judge(int n) {
    queue<int> q[n];
    int i = 0;
    for (auto t : times) {
        if (q[i].size() < c)
            q[i].push(t + 1000);
        else {
            if (q[i].front() <= t) {
                q[i].pop();
                q[i].push(t);
            } else {
                return false;
            }
        }
        i++;
        i %= n;
    }
    return true;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> q >> c;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        times.push_back(t);
    }
    sort(all(times));
    int l = 1, r = 100000;
    while (l <= r) {
        int m = (l + r) / 2;
        if (judge(m))
            r = m - 1;
        else
            l = m + 1;
    }
    cout << l  << endl;
    return 0;
}