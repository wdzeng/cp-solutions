#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool solve() {
    int npeo, npac;
    cin >> npeo >> npac;

    map<int, int> age, pac;
    for (int i = 0; i < npeo; i++) {
        int a;
        cin >> a;
        age[a]++;
    }

    for (int i = 0; i < npac; i++) {
        int p;
        cin >> p;
        pac[p]++;
    }

    if (pac.size() < age.size()) return false;

    auto a = age.begin();
    auto p = pac.begin();

    while (a != age.end()) {
        while (true) {
            if (p == pac.end()) return false;
            if (p->second >= a->second) {
                p++;
                break;
            }
            p++;
        }
        a++;
    }

    return a == age.end();
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << (solve() ? "YES\n" : "NO\n");
    return 0;
}