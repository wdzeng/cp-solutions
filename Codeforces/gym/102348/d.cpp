#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int l;
    string s;
    cin >> l >> s;
    int suma = 0, sumb = 0;
    int qa = 0, qb = 0;
    for (int i = 0; i * 2 < l; i++) {
        if (s[i] != '?')
            suma += (s[i] - '0');
        else
            qa++;
    }
    for (int i = l / 2; i < l; i++) {
        if (s[i] != '?')
            sumb += (s[i] - '0');
        else
            qb++;
    }

    int d = min(qa, qb);
    qa -= d;
    qb -= d;
    if (qa) {
        swap(qb, qa);
        swap(suma, sumb);
    }

    suma -= sumb;
    if (suma < 0 || qb % 2) {
        cout << "Monocarp" << endl;
        return 0;
    }
    if (suma == qb / 2 * 9) {
        cout << "Bicarp" << endl;
        return 0;
    }
    cout << "Monocarp" << endl;

    return 0;
}