#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
// AC
void explore(unordered_set<int>& visited, const vector<unordered_set<int>>& vec, int i) {
    visited.insert(i);
    for (int x : vec[i]) {
        if (visited.count(x) == 0) {
            explore(visited, vec, x);
        }
    }
}

void solve() {
    int nr, np;
    cin >> nr >> np;
    vector<unordered_set<int>> vec(nr + 1);
    int a, b;
    while (np--) {
        cin >> a >> b;
        if (a == b) continue;
        vec[a].insert(b);
        vec[b].insert(a);
    }

    vector<int> result(nr + 1, 0);
    for (int i = 1; i <= nr; i++) {
        if (result[i] != 0) continue;
        unordered_set<int> visited;
        explore(visited, vec, i);
        int sz = visited.size() - 1;
        for (int x : visited) result[x] = sz;
    }

    for (int i = 1; i <= nr; i++) cout << result[i] << " ";
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ":\n";
        solve();
        cout << "\n";
    }
    return 0;
}