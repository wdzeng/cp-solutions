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

const vector<int> DS = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
const int N = 1001;
int dp[N][10][N];
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string n;
    cin >> n;
    for (char& c : n)
        if (c != '?') c -= '0';
    int z = zz(n);

    int m;
    cin >> m;

    /*(z == 1) {
        if (n == "?")
            cout << 0 << endl;
        else {
            int x = n[0];
            if (x % m)
                cout << '*' << endl;
            else
                cout << x << endl;
        }
        return 0;
    }*/

    reverse(all(n));
    mss(dp);
    for (int i = 0; i < 10; i++)
        if (n[0] == '?' || n[0] == i) dp[0][i][i % m] = 0;

    int k = 10 % m;
    for (int i = 1; i < z; i++) {
        vector<int> D;
        if (n[i] == '?')
            D = DS;
        else
            D.push_back(n[i]);

        for (int d : D) {
            int addon = k * d % m;
            for (int r = 0; r < m; r++) {
                int rest = r - addon;
                rest = (rest % m + m) % m;
                for (int x = 9; ~x; x--) {
                    if (~dp[i - 1][x][rest]) dp[i][d][r] = x;
                }
            }
        }
        k = k * 10 % m;
    }

    int r = 0;
    string ans;
    int d = 0;
    for (int i = 9; i; i--)
        if (~dp[z - 1][i][0])
            d = i;

    if (!d) {
        cout << "*\n";
        return 0;
    }

    for (int i = z - 1; ~i; i--) {
        assert(~d);
        ans.push_back(d);
        int att = 1;
        for (int a = 0; a < i; a++) att *= 10, att %= m;
        att *= d, att %= m;
        d = dp[i][d][r];
        r = r - att;
        r = (r % m + m) % m;
    }

    for (char& c : ans) c += '0';
    cout << ans << endl;
    assert(zz(ans) == z);
    return 0;
}