#include <algorithm>
#include <iostream>
using namespace std;

// AC

int get_max(int* arr, int size) {
    int maxx = arr[0];
    for (int i = 1; i < size; i++) maxx = max(maxx, arr[i]);
    return maxx;
}

long sum(int* arr, int size) {
    long s = 0;
    while (size--) s += arr[size];
    return s;
}

int require_enough_days(int* arr, int size, long maxx) {
    long total = 0;
    int d = 1;
    for (int i = 0; i < size; i++) {
        total += arr[i];
        if (total > maxx) {
            total = arr[i];
            d++;
        }
    }
    return d;
}

long find(int* arr, int n, int d) {
    long maxx = sum(arr, n);
    long minn = get_max(arr, n);
    while (minn < maxx) {
        long guess = (maxx + minn) / 2;
        int rd = require_enough_days(arr, n, guess);
        if (rd <= d) {
            // We can spend more days. Let the distance be shorter.
            maxx = guess;
        } else {
            // It takes too much days, let the distance be longer.
            minn = guess + 1;
        }
    }

    return minn;
}

void solve() {
    int n, d;
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << find(arr, n, d) << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}