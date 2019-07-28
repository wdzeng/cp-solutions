#include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <list>
#include <string>

// AC

#define numlen 18
#define format "%018ld"
#define lim 1000000000000000000L
using namespace std;

list<long> bigint;

void add(char* s) {
    auto it = bigint.rbegin();
    int cursor = strlen(s);
    bool carry = false;
    bool end = false;
    while (cursor) {
        cursor = max(0, cursor - numlen);
        long added = atol(s + cursor) + carry;
        if (end || it == bigint.rend()) {
            if (added >= lim) {
                added -= lim;
                carry = true;
            } else
                carry = false;
            bigint.push_front(added);
            end = true;
        } else {
            int org = *it;
            *it += added;
            if (*it >= lim) {
                *it -= lim;
                carry = true;
            } else
                carry = false;
            it++;
        }
        s[cursor] = '\0';
    }
    if (carry) {
        while (it != bigint.rend()) {
            *it += 1;
            if (*it == lim) {
                *it = 0;
                it++;
            } else {
                return;
            }
        }
        bigint.push_front(1);
    }
}

void solve(string& line) {
    char* str = (char*)line.c_str();
    char* token = strtok(str, " ");
    while (token != NULL) {
        add(token);
        token = strtok(NULL, " ");
    }

    bool start = false;
    auto it = bigint.begin();
    while (it != bigint.end()) {
        if (start)
            printf(format, *it);
        else {
            if (*it) {
                cout << *it;
                start = true;
            }
        }
        it++;
    }
    if (!start) cout << 0;
    cout << "\n";
}

int main() {
    static string input;
    while (getline(cin, input)) {
        bigint.clear();
        solve(input);
    }
    return 0;
}