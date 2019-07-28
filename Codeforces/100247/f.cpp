#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, crt, stk;
vector<int> msts;

int rup(int x, int y) {
    if (x % y == 0) return x / y;
    return x / y + 1;
}

bool test(int n) {
    int dec = n * stk;
    int nctk = 0;
    for (int hp : msts) {
        if (hp <= dec) continue;
        nctk += rup(hp - dec, crt);
        if (nctk > n) return false;
    }
    return true;
}

int main() {
    cin >> n >> crt >> stk;
    crt -= stk;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        msts.push_back(x);
    }

    if (crt == 0) {
        int maxx = *max_element(msts.begin(), msts.end());
        cout << rup(maxx, stk) << endl;
        return 0;
    }

    int maxx = *max_element(msts.begin(), msts.end());
    int r = rup(maxx, stk), l = rup(maxx, stk + crt);

    while (l < r) {
        int mid = (l + r) / 2;
        if (test(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << endl;
    return 0;
}