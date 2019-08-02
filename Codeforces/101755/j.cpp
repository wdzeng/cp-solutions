#include <bits/stdc++.h>
using namespace std;
int arr[200001];
int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        arr[x]++;
    }
    int pair = 0;
    for (int i : arr) {
        pair += (i / 2);
    }
    cout << pair / 2 << endl;
    return 0;
}