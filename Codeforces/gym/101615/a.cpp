#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

bool ispalin(string& str, int from, int to) {
    int i = from, j = to - 1;
    while (i < j) {
        if (str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j <= a.size(); j++) {
            if (ispalin(a, i, j) && (j - i) % 2 == 0) {
                cout << "Or not." << endl;
                return 0;
            }
        }
    }
    cout << "Odd." << endl;
    return 0;
}