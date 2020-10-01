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
    cout.tie(0);
    string str;
    cin >> str;
    int l = str.length();
    vector<int> count(26);
    for (char c : str) count[c - 'a']++;

    int dual = 0;
    char maxchar;

    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        if (count[i] >= l / 2) {
            dual++;
            maxchar = c;
        }
    }

    if (dual == 2) {
        sort(all(str));
        cout << "YES\n"
             << str << '\n';
        return 0;
    }

    if (dual == 0) {
        cout << "YES\n"
             << str << '\n';
        return 0;
    }

    int charCount = 0;
    for (auto c : count) charCount += (c > 0);
    char some = 0;
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        if (c == maxchar) continue;
        if (count[i] > 0) {
            some = c;
            break;
        }
    }

    int maxcharCount = count[maxchar - 'a'];
    if (charCount <= 2) {
        if (count[some - 'a'] > 2) {
            puts("YES");
            for (int i = 0; i < maxcharCount / 2; i++) putchar(maxchar);
            putchar(some);
            for (int i = maxcharCount / 2; i < maxcharCount; i++) putchar(maxchar);
            for (int i = 1; i < count[some - 'a']; i++) putchar(some);
            putchar('\n');
        } else {
            puts("NO\n");
        }

        return 0;
    }

    puts("YES");

    assert(some != maxchar);
    assert(some != 0);

    //string ans;
    for (int i = maxcharCount / 2; i > 0; i--) putchar(maxchar);
    for (int i = count[some - 'a']; i > 0; i--) putchar(some);
    for (int i = maxcharCount / 2; i < maxcharCount; i++) putchar(maxchar);

    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        if (c == maxchar or c == some) continue;
        int cnt = count[i];
        for (int j = 0; j < cnt; j++) putchar(c);  //ans.push_back(c);
    }
    //cout << ans << '\n';
    putchar('\n');

    return 0;
}
