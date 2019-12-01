#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
// AC
int ceil(int x) { return x % 2 ? (x / 2 + 1) : (x / 2); }

int main() {
    int n;
    cin >> n;
    int h = ceil(n);
    int arr[n + 1][h + 1];
    memset(arr, 0, sizeof(arr));

    for (int i = 1; i <= h; i++) {
        cout << "Q " << i << " " << i + h - 1 << endl;
        bool detected[n+1];
        memset(detected, false, sizeof(detected));
        for (int s = 0; s < h; s++) {
            int d;
            cin >> d;
            detected[d] = true;
        }
        for (int s = 1; s <= n; s++) {
            // Add by 1 or 0
            arr[s][i] = arr[s][i - 1] + detected[s];
        }
    }

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        int index = arr[i][h];
        if (index == 0) {
            ans[n] = i;
            continue;
        }
        bool ref = arr[i][1] == 0;
        if (ref) index = h * 2 - index;
        ans[index] = i;
    }
    cout << "A ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}