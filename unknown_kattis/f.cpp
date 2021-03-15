#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

int perfect = 1;
void judge(string& s) {
    // cout << "check " << s << endl;
    if (s == "a+a") return;
    if (zz(s) % 2 == 0) {
        cout << "error\n";
        exit(0);
    }
    for (int i = 0; i < zz(s); i++) {
        if (i % 2 == 1) {
            if (s[i] != '+') {
                cout << "error\n";
                exit(0);
            }
        } else {
            if (s[i] != 'a') {
                cout << "error\n";
                exit(0);
            }
        }
    }
    perfect = 0;
    // cout << "ok" << endl;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string s;
    getline(cin, s);
    string t;
    for (char c : s) {
        if (c == ' ') continue;
        if ('a' <= c && c <= 'z')
            t.push_back('a');
        else if (c == '+' or c == '-' or c == '*' or c == '/' or c == '%')
            t.push_back('+');
        else
            t.push_back(c);
    }
    s = t;

    while (1) {
        if (s == "a+a") {
            break;
        }
        int lastleft = -1;
        int ok = 0;
        for (int i = 0; i< zz(s); i++) {
            if (s[i] == '(') {
                lastleft = i;
            }  //
            else if (s[i] == ')') {
                if (lastleft == -1) {
                    cout << "error\n";
                    exit(0);
                }
                string str = s.substr(lastleft + 1, i - lastleft - 1);
                judge(str);
                s.erase(s.begin() + lastleft, s.begin() + i + 1);
                s.insert(s.begin() + lastleft, 'a');
                ok = 1;
                break;
            }
        }
        if (!ok) {
            break;
        }
    }
    // cout << "FFF" << endl;
    judge(s);
    cout << (perfect ? "proper" : "improper") << endl;
    return 0;
}