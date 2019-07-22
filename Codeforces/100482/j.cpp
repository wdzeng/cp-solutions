#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;
// AC
int solve() {
    set<pair<int, pair<int, int>>> sett;

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (p[i] + p[j] > p[k])
                    sett.insert({p[i], {p[j], p[k]}});
                else
                    break;
            }
        }
    }
    return sett.size();
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) cout << "Case #" << i << ": " << solve() << endl;
    return 0;
}