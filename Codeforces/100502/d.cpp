#include <iostream>
using namespace std;
int main() {
    int a, b, c, d, s0 = 0, s1 = 0;
    cin >> a >> b >> c >> d;
    s0 = a + b + c + d;
    cin >> a >> b >> c >> d;
    s1 = a + b + c + d;
    if (s0 == s1)
        cout << "Tie\n";
    else
        cout << (s0 < s1 ? "Emma" : "Gunnar") << "\n";
    return 0;
}