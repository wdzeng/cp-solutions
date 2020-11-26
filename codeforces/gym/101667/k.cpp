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
    int n;
    cin >> n;
    int l = 0, r = 0, t = 0, b = 0;
    char dir = 'R';
    pii curr;
    while (n--) {
        int a, d;
        cin >> a >> d;
        if (dir == 'R') {
            cout << r - curr.x + 1 << ' ';
            curr.x = r + 1;
            r = r + 1;
            dir = d == 1 ? 'T' : 'B';
        } else if (dir == 'L') {
            cout << curr.x - l + 1 << ' ';
            curr.x = l - 1;
            l = l - 1;
            dir = d == 1 ? 'B' : 'T';
        } else if (dir == 'T') {
            cout << t - curr.y + 1 << ' ';
            curr.y = t + 1;
            t = t + 1;
            dir = d == 1 ? 'L' : 'R';
        } else if (dir == 'B') {
            cout << curr.y - b + 1 << ' ';
            curr.y = b - 1;
            b = b - 1;
            dir = d == 1 ? 'R' : 'L';
        }
        // cout << "Move to " << curr.x << ',' << curr.y << ". Now goes " << dir << endl;
    }
    cout << endl;

    return 0;
}