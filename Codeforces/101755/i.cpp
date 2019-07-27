#include <bits/stdc++.h>
using namespace std;
int n, h;
int dist[1024][1024];
int mom[1024];
vector<int> lvs;

int query(int x, int y) {
    if (x > y) swap(x, y);
    if (x == y) return 0;
    if (dist[x][y] != -1) return dist[x][y];
    cout << "? " << x << " " << y << endl;
    int d;
    cin >> d;
    return dist[x][y] = d;
}

pair<int, int> find2leaves(vector<int>& cands, int dist) {
    while (true) {
        int x = rand() % cands.size();
        int y = rand() % cands.size();
        if (query(cands[x], cands[y]) == dist) return {cands[x], cands[y]};
    }
}

int build(vector<int>& cands, vector<int>& leafcands, int treeheight) {
  /*   cout << "Nodes: ";
    for (int x : cands) cout << x << " ";
    cout << endl;
    cout << "Leaves: ";
    for (int x : leafcands) cout << x << " ";
    cout << endl; */

    if (treeheight == 1) return cands[0];
    int rootdist = treeheight - 1;

    pair<int, int> leaf2 = leafcands.empty() ? find2leaves(cands, rootdist * 2) : find2leaves(leafcands, rootdist * 2);
    vector<int> lefttree, righttree, leftleaves, rightleaves;
    int root;
    for (int x : cands) {
        int d1 = query(leaf2.first, x);
        int d2 = query(leaf2.second, x);
        if (d1 < d2)
            lefttree.push_back(x);
        else if (d1 > d2)
            righttree.push_back(x);
        else
            root = x;
    }
    for (int x : cands) {
        if (query(root, x) == rootdist) {
            if (query(leaf2.first, x) < query(leaf2.second, x))
                leftleaves.push_back(x);
            else
                rightleaves.push_back(x);
        }
    }

    int leftroot = build(lefttree, leftleaves, treeheight - 1);
    int rightroot = build(righttree, rightleaves, treeheight - 1);
    mom[leftroot] = root;
    mom[rightroot] = root;

    return root;
}

int main() {
    srand(time(NULL));
    cin >> n;
    int h = round(log2(n + 1));
    memset(dist, -1, sizeof(dist));

    vector<int> cands, none;
    for (int i = 1; i <= n; i++) cands.push_back(i);
    int root = build(cands, none, h);
    mom[root] = 0;

    cout << "! ";
    for (int i = 1; i <= n; i++) cout << mom[i] << " ";
    cout << endl;
    return 0;
}