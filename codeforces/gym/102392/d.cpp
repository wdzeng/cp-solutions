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
    string str;
    cin >> str;
    int cnt[26] = {0};
    for (char c : str) cnt[c - 'a']++;
    int maxchar = max_element(cnt, cnt + 26) - cnt;

    if (cnt[maxchar] <= str.size() / 2) {
        cout << "YES\n";
        for (int i = 0; i < 26; i++) {
            for (int a = 0; a < cnt[i]; a++) cout << (char)('a' + i);
        }
        cout << endl;
        return 0;
    }

    if (cnt[maxchar] >= str.size() - 1) {
        cout << "NO" << endl;
        return 0;
    }

    if (cnt[maxchar] == str.size() - 2) {
        char a = 0, b = 0;
        for (int i = 0; i < 26; i++) {
            if (i == maxchar) continue;
            if (!cnt[i]) continue;
            if (a)
                b = 'a' + i;
            else
                a = 'a' + i;
        }
        if (a and b) {
            cout << "YES\n";
            for (int i = 0; i < str.size() / 2 - 1; i++)
                cout << (char)(maxchar + 'a');
            cout << a;
            for (int i = 0; i < str.size() / 2 - 1; i++)
                cout << (char)(maxchar + 'a');
            cout << b << endl;
            return 0;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    string ans;
    for (int i = 0; i < cnt[maxchar]; i++) ans.push_back('a' + maxchar);
    for (int i = 0; i < 26; i++)
        if (i != maxchar)
            for (int j = 0; j < cnt[i]; j++) ans.push_back('a' + i);
    swap(ans[ans.size() / 2 - 1], ans[cnt[maxchar]]);
    cout << "YES\n" << ans << endl;
    return 0;
}