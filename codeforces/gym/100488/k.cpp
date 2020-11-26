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
    priority_queue<int, vector<int>, greater<int>> q;
    ll sum = 0, lesser = 0;
    for (int i = 0; i < n - n % 2; i+=2) {
        int x, y;
        cin >> x >> y;
        sum += x + y;
        q.push(x), q.push(y);
        int t = q.top();
        q.pop();
        lesser += t;
    }
    if (n % 2) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << sum - lesser << " " << lesser<<  endl;
    return 0;
}