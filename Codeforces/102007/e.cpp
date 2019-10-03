#include <bits/stdc++.h>
using namespace std;

int a[8];
bool judge() {
    for (int i = 0; i < 8; i++) {
        bool b = 1;
        for (int l = 0; l < i; l++) {
            if (a[l] > a[i]) {
                b = 0;
                break;
            }
        }
        for (int r = i + 1; r < 8; r++) {
            if (a[r] < a[i]) {
                b = 0;
                break;
            }
        }
        if (b) return 1;
    }
    return 0;
}

bool valid() {
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (a[i] == a[j]) return false;
        }
    }
    return true;
}

int main() {
    int c = 0;
    for (int i0 = 1; i0 <= 8; i0++)
        for (int i1 = 1; i1 <= 8; i1++)
            for (int i2 = 1; i2 <= 8; i2++)
                for (int i3 = 1; i3 <= 8; i3++)
                    for (int i4 = 1; i4 <= 8; i4++)
                        for (int i5 = 1; i5 <= 8; i5++)
                            for (int i6 = 1; i6 <= 8;  i6++) 
                            for (int i7 = 1; i7<= 8; i7++) {
                                a[0] = i0;
                                a[1] = i1;
                                a[2] = i2;
                                a[3] = i3;
                                a[4] = i4;
                                a[5] = i5;
                                a[6] = i6;
                                a[7] = i7;
                                if (valid() && judge()) c++;
                            }
    cout << c << endl;
    return 0;
}