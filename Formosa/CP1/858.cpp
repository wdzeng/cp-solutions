#include <algorithm>
#include <iostream>
using namespace std;

// AC

int min_ans(int *arr, int n) {
    int maxx = arr[0];
    for (int i = 1; i < n; i++) maxx = max(maxx, arr[i]);
    return maxx;
}

int require_segments(int *arr, int n, long dis) {
    int maxx = 0;
    int len = 0;
    int seg = 1;
    for (int i = 0; i < n; i++) {
        maxx = max(maxx, arr[i]);
        if ((long)maxx * (++len) > dis) {
            len = 1;
            maxx = arr[i];
            seg++;
        }
    }
    return seg;
}

long solve(int *arr, int n, int k) {
    long minn = min_ans(arr, n);
    long maxx = minn * n;
    while (minn < maxx) {
        long guess = (minn + maxx) / 2;
        int rk = require_segments(arr, n, guess);
        // cout << ": " << rk << endl;
        if (rk <= k)
            maxx = guess;
        else
            minn = guess + 1;
    }
    return minn;
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solve(arr, n, k) << "\n";
    return 0;
}