#include <bits/stdc++.h>
#define pb(x) push_back(x)

#define x first
#define y second
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

vector<int> Depth, Low, BCC;
vector<vector<int>> graph;
set<pii> bridge;

int ans = 0;
int counter = 1;
int current_BCC = 1;
int current_size = 0;
int max_size = 0;
int BCC_num = 0;

void tarjan(int current, int father) {
    int children_num = 0;
    Depth[current] = Low[current] = counter++;
    bool isPt = false;
    for (int v : graph[current]) {
        if (v == father) {
            continue;
        }
        if (!Depth[v]) {
            tarjan(v, current);
            children_num++;
            if (Low[v] > Depth[current] or (current != father and Low[v] >= Depth[current])) {
                isPt = 1;
            }
            Low[current] = min(Low[current], Low[v]);
        }
        Low[current] = min(Low[current], Depth[v]);
    }
    if (Low[current] >= Depth[current] and father != current) {
        bridge.insert({current, father});
    }
    if (current == father and (children_num < 2)) {
        isPt = false;
    }
    ans += isPt;
}

void dfs(int v) {
    if (BCC[v]) return;
    //cout << v << " " << current_BCC << endl;
    BCC[v] = current_BCC;
    //current_size++;
    for (int u : graph[v]) {
        if (bridge.count({u, v}) or bridge.count({v, u})) {
            //cout << "bridge" << endl;
            continue;
        }
        current_size++;
        dfs(u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        int n, m;
        cin >> n >> m;
        graph.clear();
        Depth.clear();
        Low.clear();
        bridge.clear();
        BCC.clear();
        graph.resize(n);
        BCC.resize(n);
        Depth.resize(n);
        Low.resize(n);
        current_BCC = 1;
        current_size = 0;
        max_size = 0;
        BCC_num = 0;
        ans = 0;

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            a--;
            b--;

            graph[a].pb(b);
            graph[b].pb(a);
        }

        tarjan(0, 0);
        for (int i = 0; i < n; i++) {
            if (BCC[i]) continue;
            dfs(i);
            if (current_size != 0) {
                BCC_num++;
            }
            max_size = max(max_size, current_size);
            current_size = 0;
            current_BCC++;
        }
        // 為了他雞巴定義的特判處理
        max_size /= 2;
        max_size = max(max_size, 1);
        // BCC_num += bridge.size();
        int gcd = __gcd(BCC_num, max_size);
        //BCC_num /= gcd;
        //max_size /= gcd;
        cout << ans << " " << bridge.size() << " " << BCC_num << " " << max_size << endl;
    }
}