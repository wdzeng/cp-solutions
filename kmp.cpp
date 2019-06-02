#include <cstring>
#include <iostream>
using namespace std;

int* fail(const char* pat) {
    int l = strlen(pat);
    int* f = new int[l];
    f[0] = 0;
    int i = 1, j = 0;

    while (pat[i]) {
        if (pat[i] == pat[j]) {
            f[i] = f[i - 1] + 1;
            i++;
            j++;
            continue;
        }
        if (j == 0) {
            i++;
            continue;
        }

        while (j > 0 && j != pat[j]) {
            j = f[j - 1];
            if (pat[i] == pat[j]) break;
        }
        if (pat[i] == pat[j]) {
            f[i] = f[j] + 1;
            i++;
            j++;
            continue;
        }
        f[i] = f[j];
    }
    return f;
}

int kmp(const char* str, const char* pat) {
    int* f = fail(pat);
    int i = 0;
    int j = 0;
    while (str[i]) {
        if (!pat[j]) {
            // Found!
            delete[] f;
            return i - j;
        }
        if (str[i] == pat[j]) {
            i++;
            j++;
            continue;
        }
        if (j == 0) {
            i++;
            continue;
        }
        while (j > 0 && pat[j] != j) {
            j = f[j - 1];
            if (str[i] == pat[j]) break;
        }
        if (str[i] == pat[j]) j++;
        i++;
    }
    delete[] f;
    return pat[j] ? -1 : (i - j);
}

int main() {
    char str[100], pat[30];
    cin >> str >> pat;
    cout << kmp(str, pat) << endl;
    return 0;
}