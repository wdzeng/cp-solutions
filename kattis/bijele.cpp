#include <iostream>
using namespace std;
int main() {
    int arr[6] = {1, 1, 2, 2, 2, 8};
    for (int i = 0; i < 6; i++) {
        int x;
        cin >> x;
        cout << (arr[i] - x) << " ";
    }
    cout << endl;
    return 0;
}