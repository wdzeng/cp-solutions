#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> locs(1000);
    locs.push_back(0);
    int cursor = 0;
    while(k--) {
        string s; cin >> s;
        if(s=="undo") {
            int x; cin >> x;
            cursor -= x;
        } //
        else {
            int x = stoi(s);
            int newloc = locs[cursor] + x;
            newloc = (newloc % n + n) % n;
            locs[++cursor] = newloc;
        }
    }
    cout << locs[cursor] << endl;
    return 0;
}