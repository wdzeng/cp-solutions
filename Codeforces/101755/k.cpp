#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> vec;

int test(int p) {
    int w = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i] <= w)
            w++;
        else if (p > 0) {
            p--;
            w++;
        }
    }
    return w;
}

int main() {
    int target;
    cin >> n >> target;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    int l = 0, r = target;
    while (l < r) {
        int mid = (l + r) / 2;
        if (test(mid) >= target)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}