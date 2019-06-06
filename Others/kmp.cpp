#include <cstring>
#include <iostream>
using namespace std;

int* fail(const char*);
int kmp(const char*, const char*, int*);
int kmp(const char*, const char*);

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

int kmp(const char* str, const char* pat, int* f) {
    int i = 0;
    int j = 0;
    while (str[i]) {
        if (!pat[j]) {
            // Found!
            return i - j;
        }
        if (str[i] == pat[j]) {
            // Match! Go next.
            i++;
            j++;
            continue;
        }

        // Unmatch. Use failure function.

        if (j == 0) {
            i++;
            continue;
        }

        j--;
        while (j > 0 && f[j] != j) {
            j = f[j];
            if (str[i] == pat[j]) break;
        }
        if (str[i] == pat[j]) j++;
        i++;
    }
    return pat[j] ? -1 : (i - j);
}

int kmp(const char* string, const char* pattern) {
    int* f = fail(pattern);
    int ret = kmp(string, pattern, f);
    delete[] f;
    return ret;
}

int main() {
    char str[100], pat[30];
    cin >> str >> pat;
    cout << kmp(str, pat) << endl;
    return 0;
}