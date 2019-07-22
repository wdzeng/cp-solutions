#include <bits/stdc++.h>
using namespace std;

long long orr(const vector<long long>& vec, int index, long long sum, bool o) {
    if (index == vec.size() - 1) return o ? (sum | vec[index]) : sum;
    if (o) sum |= vec[index];
    return orr(vec, index + 1, sum, true) + orr(vec, index + 1, sum, false);
}

int main() {
    int n;
    cin >> n;
    set<int> sset;
    vector<long long> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    cout << orr(vec, 0, 0, true) + orr(vec, 0, 0, false) << endl;
    return 0;
}