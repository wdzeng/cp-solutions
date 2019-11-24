#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Car {
public:
	bool hor;
	int len;
	int x, y;
	Car(){}
	Car(bool h, int l, int x, int y): hor(h), len(l), x(x), y(y) {}
};

class G {
public:
	int count;
	int arr[6][6];
	vector<Car> cars;
	G(){}
	int* operator[](int i){ return arr[i]; }	
	void init() {
		cars.resize(count+1);
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
		assert(vis.size() == count);
	}
	bool operator<(const G& g) const {
		return cars < g.cars;
	}
	bool isdone() {
		return arr[2][4] == 1 and arr[2][5] == 1;
	}
};

class Car {
public:
	bool hor;
	int len;
	int x, y;
	Car(){}
	Car(bool h, int l, int x, int y): hor(h), len(l), x(x), y(y){}
	void move(queue<G>& q, G& gg, map<G, int>& m, int s) {
		if(hor) {
			
			if(x+len<6 and gg[x+len][y] == 0) {
				G g = gg;
				swap(g[x+len][y], g[x][y]);
				x++;
				if(!m.count(g))
					q.push(g), m[g] = s;
			}
			if(x>0 and gg[x-1][y] == 0) {
				G g = gg;
				swap(g[x-1][y], g[x][y]);
				x--;
				if(!m.count(g))
					q.push(g), m[g] = s;
			}
		}
		else {
			if(y+len<6 and gg[x][y+len] == 0) {
				G g = gg;
				swap(g[x][y+len], g[x][y]);
				y++;
				if(!m.count(g))
					q.push(g), m[g] = s;
			}
			if(y>0 and gg[x][y-1] == 0) {
				G g = gg;
				swap(g[x][y-1], g[x][y]);
				y--;
				if(!m.count(g))
					q.push(g), m[g] = s;
			}
		}
	}
	
	bool operator< (const Car& c) const {
		if(hor != c.hor) return hor < c.hor;
		if(len != c.len) return len < c.len;
		if(x != c.x) return x < c.x;
		if(y != c.y) return y < c.y;
	}
};

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
	G g;
	for(int i=0; i<6; i++) for(int j=0; j<6; j++) {
		int v; cin >> v; g.count = max(v, g.count);
		g[i][j] = v;
	}
	g.init();
	map<G, int> m;
	queue<G> q;
	q.push(g);
	m[g] = 0;
	while(q.size()) {
		G v = q.front(); q.pop();
		assert(m.count(v));
		int s = m[v];
		if(v.isdone()) {
			cout << s+2 << endl;
			exit(0);
		}
		for(int i=1; i<=v.count; i++) {
			Car c = v.cars[i];
			c.move(q, v, m, s+1);
		}
	}
	cout << -1 << endl;
	return 0;
}
