#include <iostream>
#include <cstring>
using namespace std;
// AC
int main() {
    int arr[26] = {0};
    char buff[400002];
    cin >> buff;
    if(strlen(buff)%2==1) {
        cout << "NO\n";
        return 0;
    }
    for (char c : buff) {
        if (c == '\0') break;
        for (char i = 'a'; i <= 'z'; i++) {
            arr[i - 'a'] += (c == i ? 1 : -1);
        }
    }
    for(int i: arr) {
        if(i>0) {cout << "NO\n"; return 0;}
    }
    cout << "YES\n";
    return 0;
}