#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tmap;
vector<vector<int>> query;
vector<vector<int>> component;

void DFS(int i, int j) {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    cin >> m >> n;
    tmap.resize(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            string x;
            cin >> x;
            if (x == "-") {
                tmap[i][j] = 0;
            } else {
                int ans = 0;
                for (char y : x) {
                    ans = ans * 10 + (y - '0');
                }
                tmap[i][j] = ans;
            }
        }
    }
    /*
	for(auto v: tmap){
		for(auto u: v){
			cout << u << " ";
		} cout << endl;
	} */
    int nnn;
    cin >> nnn;
    for (int i = 0; i < nnn; i++) {
        int nn;
        cin >> nn;
        component.push_back(vector<int>(nn));
        cout << nn << " ";
        for (int j = 0; j < nn; j++) {
            string tmp;
            cin >> tmp;
            int x, y;
            x = tmp[1] - '0';
            y = tmp[3] - '0';
            x -= 1;
            y -= 1;
            query[x][y] = i;
            component[i][tmap[x][y]] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << query[i][j] << " ";
        }
        cout << endl;
    }
}