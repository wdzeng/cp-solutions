#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> maxq;
    int n;
    cin >> n;
    int prevtime = 0;
    int shield = 0;
    int shoot = 0;
    while (n--) {
        int t, dm;
        cin >> t >> dm;
        shield += (t - prevtime);
        maxq.push(dm);
        if (shield < dm) {
            int d = maxq.top();
            maxq.pop();
            shield += d;
            shoot++;
        }
        shield -= dm;
        prevtime = t;
    }
    cout << shoot << endl;
    return 0;
}