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
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a.push_back(v);
    }
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        b.push_back(v);
    }

    int win = 0;
    int lose = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] && !b[i])
            win++;
        else if (!a[i] && b[i])
            lose++;
    }

    if (win == 0) {
        cout << -1 << endl;
    } else {
        for(int ans=1; ;ans++) {
            if(ans*win > lose) {
                cout << ans << endl;
                return 0;
            }
        }
    }

    return 0;
}