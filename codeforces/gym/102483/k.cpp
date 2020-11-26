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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    string lst, str;
    cin >> lst >> str;
    for (char& c : lst) c -= 'a';
    for (char& c : str) c -= 'a';
    reverse(all(str));
    reverse(all(lst));
    string ans = lst;
    for (int i = 0; i < b - a; i++) {
        int c = 0 + str[i] - ans[i];
        c = (c % 26 + 26) % 26;
        ans.push_back(c);
    }
    reverse(all(ans));
    for (char& c : ans) c += 'a';
    cout << ans << endl;
    return 0;
}