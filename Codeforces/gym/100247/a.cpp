#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a, b, c;
    for (int i = 0; i < n; i++) {
        int arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr + 3);
        a.push_back(arr[0]), b.push_back(arr[1]), c.push_back(arr[2]);
    }

    int maxa = *max_element(a.begin(), a.end());
    int maxb = *max_element(b.begin(), b.end());

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (c[i] > maxb && b[i] > maxa) ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}