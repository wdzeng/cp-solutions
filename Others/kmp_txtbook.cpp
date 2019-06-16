#include <iostream>
#include <string>
using namespace std;

int* fail(const string& pat) {
    int* f = new int[pat.length()];
    f[0] = -1;
    int down = 1, up = 0;
    for (; down < pat.length(); down++) {
        if (pat[down] == pat[up]) {
            f[down] = f[down - 1] + 1;
            up++;
            continue;
        }
        // If up and down point to same character, stop
        // If up pointer is at leftest position, stop
        while (pat[down] != pat[up] && up > 0) {
            // First move left
            // Then point to that value
            // Finally move right
            up = f[up - 1] + 1;
        }
        if (pat[down] == pat[up]) {
            f[down] = up;
            up++;
        }  
        else {
            f[down] = -1;
        }
    }
    return f;
}

int kmp(string str, string pat) {
    int* f = fail(pat);
    int down = 0, up = 0;
    for (; down < str.length() && up < pat.length(); down++) {
        while (str[down] != pat[up] && up > 0) up = f[up - 1] + 1;
        if (str[down] == pat[up]) {
            up++;
        }
    }
    delete[] f;
    if (up == pat.length())
        return down - up;
    else
        return -1;
}