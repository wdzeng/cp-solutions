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

const int maxn = 32;
vector<int> adj[maxn];
int V, E;

int findleaf() {
    int dad[maxn];
    int dist[maxn];
    mss(dad);
    ms(dist);
    queue<int> q;
    q.push(1);
    dad[1] = 0;
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (int e : adj[v]) {
            if (dad[e] != -1) continue;
            dad[e] = v;
            dist[e] = dist[v] + 1;
            q.push(e);
        }
    }

    int x = 1;
    for (int i = 1; i <= V; i++) {
        if (dist[i] > dist[x]) x = i;
    }
    return x;
}

vector<int> chain() {
    int leaf = findleaf();
    int dad[maxn];
    int dist[maxn];
    mss(dad);
    ms(dist);

    queue<int> q;
    q.push(leaf);
    dad[leaf] = 0;
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (int e : adj[v]) {
            if (dad[e] != -1) continue;
            dad[e] = v;
            dist[e] = dist[v] + 1;
            q.push(e);
        }
    }

    int x = 1;
    for (int i = 1; i <= V; i++) {
        if (dist[i] > dist[x]) x = i;
    }
    vector<int> ret;
    for (int i = x; i; i = dad[i]) ret.push_back(i);
    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    while (cin >> V and V) {
        int ans[maxn];
        for (auto& vec : adj) vec.clear();
        cin >> E;
        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        auto ch = chain();
        ans[ch[0]] = 0;
        bool ispos = 1;
        int rem = E;
        for (int i = 1; i < ch.size() - 1; i++) {
            int cv = ch[i];
            ans[cv] = ans[ch[i - 1]] + (ispos ? 1 : -1) * rem;
            rem--;
            for (int momo : adj[cv]) {
                if (momo == ch[i - 1] or momo == ch[i + 1]) continue;
                ans[momo] = ans[cv] + (ispos ? -1 : 1) * rem;
                rem--;
            }
            ispos = !ispos;
        }
        ans[ch.back()] = ans[ch[ch.size() - 2]] + (ispos ? 1 : -1) * rem;
        for (int i = 1; i <= V; i++) cout << ans[i] << " \n"[i == V];
    }

    return 0;
}

/*
10 9
2 10
1 2
1 9
1 6
1 8
7 5
7 4
3 7
7 1

5 4
1 2
2 3
2 4
2 5

0
*/
