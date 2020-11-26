#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int n;
    cin >> n;
    unordered_map<int, int> mmap;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(++mmap[x] == n) {
            cout << 0 << endl;
            return 0;
        }
        vec.push_back(x);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        mmap[vec[a]]--;
        vec[a] = b;
        if (++mmap[b] == n) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}