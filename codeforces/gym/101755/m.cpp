#include <bits/stdc++.h>
using namespace std;
string stra, strb, strc;

void amb() {
    cout << "Ambiguous\n";
    exit(0);
}

void imp() {
    cout << "Impossible\n";
    exit(0);
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size();
    int m3 = 0, m2 = 0, da = 0, db = 0, dc = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i] && b[i] != c[i] && c[i] != a[i])
            m3++;
        else if (a[i] == b[i] && b[i] == c[i])
            continue;
        else {
            m2++;
            if (a[i] == b[i])
                dc++;
            else if (b[i] == c[i])
                da++;
            else
                db++;
        }
    }

    if (m2 == 0) {
        if (m3 <= 1) amb();
        imp();
    }
    if (m2 == 1) {
        if (m3 == 0) amb();
        if (m3 == 1) {
            if (dc == 1)
                swap(a, c);
            else if (db == 1)
                swap(a, b);
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i] && b[i] != c[i] && c[i] != a[i])
                    cout << a[i];
                else
                    cout << b[i];
            }
            cout << endl;
            return 0;
        }
        imp();
    }
    if (m2 == 2) {
        if (m3 != 0) imp();
        if (da == 2 || db == 2 || dc == 2) amb();
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i])
                cout << a[i];
            else if (b[i] == c[i])
                cout << b[i];
            else
                cout << c[i];
        }
        cout << endl;
        return 0;
    }
    if (m2 == 3) {
        if (m3 != 0) imp();
        if (da == 1 && db == 1 && dc == 1) {
            for (int i = 0; i < n; i++) {
                if (a[i] == b[i] && b[i] == c[i])
                    cout << a[i];
                else if (a[i] == b[i])
                    cout << a[i];
                else if (b[i] == c[i])
                    cout << b[i];
                else
                    cout << c[i];
            }
            cout << endl;
            return 0;
        }
        imp();
    }
    imp();
}