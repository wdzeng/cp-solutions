#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

vector<string> kk;
void init() {
    for (char i = 'a'; i <= 'z'; i++)
        for (char j = 'a'; j <= 'z'; j++)
            for (char k = 'a'; k <= 'z'; k++) {
                string s;
                s.push_back(i);
                s.push_back(j);
                s.push_back(k);
                kk.push_back(s);
            }
}

int main() {
    init();
    cin.tie(0), ios::sync_with_stdio(0);
    string ans;
    cin >> ans;
    int n = ans.size();

    string sub;
    for (int i = 0; i < n; i++) {
        sub.push_back(kk[i][0]);
    }
    cout << "? " << sub << endl;
    string ans1;
    cin >> ans1;

    sub = "";
    for (int i = 0; i < n; i++) {
        sub.push_back(kk[i][1]);
    }
    cout << "? " << sub << endl;
    string ans2;
    cin >> ans2;

    sub = "";
    for (int i = 0; i < n; i++) {
        sub.push_back(kk[i][2]);
    }
    cout << "? " << sub << endl;
    string ans3;
    cin >> ans3;

    vector<char> out(n);
    for (int i = 0; i < n; i++) {
        string tar = "";
        tar.push_back(ans1[i]);
        tar.push_back(ans2[i]);
        tar.push_back(ans3[i]);
        auto it = lower_bound(iter(kk), tar);
        assert(it != kk.end());
        int index = it - kk.begin();
        out[index] = ans[i];
    }

    cout << "! ";
    for(char c: out) cout << c;
    cout << endl;
    return 0;
}
