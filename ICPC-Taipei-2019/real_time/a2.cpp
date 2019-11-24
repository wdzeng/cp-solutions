#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> G;
#define x first
#define y second

struct Car {
	bool hor;
	int len;
	int x, y;
	Car(){}
	Car(bool h, int l, int x, int y): hor(h), len(l), x(x), y(y) { assert(len ==2 or len ==3); }
	bool at(int xx, int yy) {
		if(hor) {
			if(x!=xx) return 0;
			return y <= yy and yy < y+len;
		}
		else {
			if(y!=yy) return 0;
			return x <= xx and xx < x+len;
		}
	}
	bool operator< (const Car& c) const {
		if(hor != c.hor) return hor < c.hor;
		if(len != c.len) return len < c.len;
		if(x != c.x) return x < c.x;
		return y < c.y;
	}
};

typedef vector<Car> CC;

bool good(int ex, CC& cc, pii& loc) {
	for(int i=1; i<cc.size();i++) {
		if(i==ex) continue;
		if(cc[i].at(loc.x, loc.y)) return 0;
	}
	return 1;
}

void expand(int i, CC& cc, int s, map<CC, int>& m, queue<CC>& q) {
	Car& c = cc[i];
	vector<pair<pii, pii>> clocs;
	if(c.hor) {
		if(c.y>0) clocs.push_back({{c.x, c.y-1}, {c.x, c.y-1}});
		if(c.y+c.len<6) clocs.push_back({{c.x, c.y+1}, {c.x, c.y+c.len}});
	}
	else {
		if(c.x>0) clocs.push_back({{c.x-1, c.y}, {c.x-1, c.y}});
		if(c.x+c.len<6) clocs.push_back({{c.x+1, c.y}, {c.x+c.len, c.y}});
	}
	
	for(auto& cloc: clocs) {
		if(good(i, cc, cloc.y)) {
			CC tmp = cc;
			tmp[i].x = cloc.x.x, tmp[i].y = cloc.x.y;
			if(!m.count(tmp)) {
				m[tmp] = s;
				q.push(tmp);
			}
		}
	}
}

void expand(CC& cc, int s, map<CC, int>& m, queue<CC>& q) {
	for(int i=1; i<cc.size(); i++) expand(i, cc, s, m, q);
}

vector<Car> makecar(G& arr, int n) {
	vector<Car> cars(n+1);
	unordered_set<int> vis;
	for(int i=0;i<6;i++) {
		for(int j=0;j<6;j++){
			if(arr[i][j] and !vis.count(arr[i][j])) {
				if(i<=3 and arr[i+1][j] == arr[i][j] and arr[i+2][j] == arr[i][j]) 
					cars[arr[i][j]] = Car(0, 3, i, j);
				else if(i<=4 and arr[i+1][j] == arr[i][j])
					cars[arr[i][j]] = Car(0, 2, i, j);
				else if(j<=3 and arr[i][j+1] == arr[i][j] and arr[i][j+2] == arr[i][j]) 
					cars[arr[i][j]] = Car(1, 3, i, j);
				else if(j<=4 and arr[i][j+1] == arr[i][j])
					cars[arr[i][j]] = Car(1, 2, i, j);
				vis.insert(arr[i][j]);
			}
		}
	}
	assert(vis.size() == n);
	return cars;
}

bool isdone(CC& g) {
	return g[1].at(2, 4) and g[1].at(2, 5);
}



int main() {
	cin.tie(0), ios::sync_with_stdio(0);
	G g;
	g.assign(6, vector<int>(6));
	int n = 0;
	for(int i=0; i<6; i++) {
		for(int j=0; j<6; j++) {
			cin >> g[i][j];
			n = max(g[i][j], n);
		}
	}
	
	queue<CC> q;
	map<CC, int> m;
	CC src = makecar(g, n);
	//for(Car c: src) cout << c.hor << ' ' << c.x << ' ' << c.y << ' ' << c.len << endl;
	q.push(src);
	m[src] = 0;
	
	while(q.size()) {
		CC v = q.front(); q.pop();
		int s = m[v];
		if(s>8) { cout << -1 << endl; exit(0); }
		if(isdone(v)) {
			//for(Car c: v) cout << c.hor << ' ' << c.x << ' ' << c.y << ' ' << c.len << endl;
			cout << s+2 << endl, exit(0);
		}
		expand(v, s+1, m, q);
	}
	cout << -1 << endl;
	return 0;
}

/*
2 2 0 0 0 7
3 0 0 5 0 7
3 1 1 5 0 7
3 0 0 5 0 0
4 0 0 0 8 8
4 0 6 6 6 0

0 2 0 6 6 0
0 2 0 0 7 0
0 3 1 1 7 0 
0 3 4 4 8 0
0 5 5 5 8 0
0 0 0 0 0 0 
*/
