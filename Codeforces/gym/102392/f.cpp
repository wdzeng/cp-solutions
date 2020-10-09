#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int N = 1e5 + 10;
vector<int> adj[N];

int win(int r, int u) {
    int w = 0;
    for (int a : adj[r]) {
        if (a == u) continue;
        if (win(a, r)) w++;
    }   
    return w == 1 ? 0 : 1;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << (win(1, 0) ? "Alice" : "Bob") << endl;
    return 0;
}