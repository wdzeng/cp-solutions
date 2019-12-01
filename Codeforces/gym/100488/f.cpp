#include <iostream>
// AC
using namespace std;
#define another "Take another envelope\n"
#define stay "Stay with this envelope\n"

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (c % 2 == 1)
        cout << another;
    else if (c > b)
        cout << stay;
//    else if (c / 2 < a)
else
        cout << another;

    return 0;
}