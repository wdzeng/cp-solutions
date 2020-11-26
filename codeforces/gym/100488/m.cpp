#include <iostream>
using namespace std;
// AC
int main() {
    int x, y;
    cin >> x >> y;
    cout << x * y << "\n";
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < y; j++) {
            cout << i * y - j << " ";
        }
    }
    cout << "\n";
    return 0;
}