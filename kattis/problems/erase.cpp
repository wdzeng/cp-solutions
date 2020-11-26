#include <iostream>
using namespace std;

void yes() {
    cout << "Deletion succeeded\n";
    exit(0);
}

void no() {
    cout << "Deletion failed\n";
    exit(0);
}

int main() {
    int n;
    cin >> n;
    char str1[1001];
    char str2[1001];
    cin >> str1 >> str2;
    if (n % 2 == 0) {
        for (int i = 0; str1[i]; i++) {
            if (str1[i] != str2[i]) no();
        }
        yes();
    } 
    else {
        for (int i = 0; str1[i]; i++) {
            if (str1[i] == str2[i]) no();
        }
        yes();
    }
}