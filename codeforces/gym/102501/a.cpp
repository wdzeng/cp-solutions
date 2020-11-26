#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
int N;
int B, C0, T;

vector<int> costs;
vector<pair<int, int>> stations;
vector<vector<int>> tmap;
int distance(pair<int, int> a, pair<int, int> b) {
    int x = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    double y = sqrt(x);
    return ceil(y);
}
int BFS() {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> queue;
    queue.push({0, 0, 0});  // Costs, Here, Distance

    while (!queue.empty()) {
        vector<int> status = queue.top();
        queue.pop();
        //cout << status[0] << " " << status[1] << " " << status[2] << endl;
        if (status[2] > B) {
            continue;
        }
        if (status[1] == N + 1) {
            return status[0];
        }
        
        for (int i = 1; i < N + 2; i++) {
            //cout << tmap[i][status[1]] << endl;
            if (tmap[i][status[1]] != INF and i != status[1]) {
                int dis = distance(stations[i], stations[status[1]]);
                queue.push({status[0] + dis * tmap[i][status[1]], i, status[2] + dis});
            }
        }
    }
    return -1;
}
int main() {
    int xs, ys;
    int xd, yd;
    cin >> xs >> ys;
    cin >> xd >> yd;
    cin >> B >> C0 >> T;
    costs.resize(T);
    for (int i = 0; i < T; i++) {
        cin >> costs[i];
    }
    cin >> N;
    stations.resize(N + 2);
    stations[0] = {xs, ys};
    stations[N + 1] = {xd, yd};

    tmap.resize(N + 2);
    for (auto &v : tmap) {
        v.resize(N + 2, INF);
    }

    for (int i = 0; i < N; i++) {
        tmap[1 + i][0] = C0;
        tmap[N + 1][1 + i] = C0;
    }

    for (int i = 0; i < N; i++) {
        int l0;
        cin >> stations[i + 1].first;
        cin >> stations[i + 1].second;
        cin >> l0;
        for (int j = 0; j < l0; j++) {
            int k, mk;
            cin >> k >> mk;
            tmap[i + 1][k + 1] = min(tmap[i + 1][k + 1], costs[mk - 1]);
            tmap[k + 1][i + 1] = min(tmap[k + 1][i + 1], costs[mk - 1]);
        }
    }
    /*
	for(auto v: tmap){
		for(auto u: v){
			cout << u << " ";
		} cout << endl;
	}*/
    cout << BFS();
    return 0;
}