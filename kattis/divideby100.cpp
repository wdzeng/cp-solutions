#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string n, m;
    cin >> n >> m;
    int lenm = m.length() - 1;

    vector<char> vec;
    int cn = n.length() - 1;
    bool lz = true;
    for (int i = 0; i < lenm; i++) {
        if (cn < 0)
            vec.push_back('0');
        else {
            if (n[cn] != '0') lz = false;
            if (!lz) vec.push_back(n[cn]);
        }
        cn--;
    }
    if(!lz) vec.push_back('.');
    while (cn >= 0) vec.push_back(n[cn--]);

    if(vec.back() == '.') cout << '0';
    for (int i = vec.size() - 1; i > -1; i--) cout << vec[i];
    cout << endl;
    return 0;
}