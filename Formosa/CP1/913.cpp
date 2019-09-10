#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// AC

bool knapsack(const vector<int>& vec, int n, int rem_val) {
    if (rem_val == 0) return true;
    if (n == 0) return false;
    if (vec[n - 1] > rem_val) {
        return knapsack(vec, n - 1, rem_val);
    }
    return knapsack(vec, n - 1, rem_val) || knapsack(vec, n - 1, rem_val - vec[n - 1]);
}

bool solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        sum += vec[i];
    }

    // check divisible
    double _second = (double)sum * 100 / (100 + k);
    int second = (int)_second;
    if (_second != second) return false;
    
    int first = sum - second;
    return knapsack(vec, n, min(first, second));
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << (solve() ? "Yes" : "No") << endl;
    return 0;
}