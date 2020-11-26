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
    int t; cin >> t; while(t--) {
        int n; set<int>s; cin >> n; while(n--) {
            int a; cin >> a; s.insert(a);
        }
        cout << s.size() << endl;
    }
    
    return 0;
}