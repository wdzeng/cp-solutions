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

int table[10][10];

int poo(int a, int b) {
    return table[a][b];
}

int poo(int a, int b, int c, int d) {
    return poo(poo(poo(poo(0,a),b),c),d);
}

int poo(int a, int b, int c, int d, int e) {
    return poo(poo(poo(poo(poo(0,a),b),c),d),e);
}

bool ok(int a, int b, int c, int d) {
    int e = poo(a,b,c,d);
    for(int i=0;i<10;i++) if(i==a) continue; else if(poo(i,b,c,d,e) == 0) return 0;
    for(int i=0;i<10;i++) if(i==b) continue; else if(poo(a,i,c,d,e) == 0) return 0;
    for(int i=0;i<10;i++) if(i==c) continue; else if(poo(a,b,i,d,e) == 0) return 0;
    for(int i=0;i<10;i++) if(i==d) continue; else if(poo(a,b,c,i,e) == 0) return 0;
    for(int i=0;i<10;i++) if(i==e) continue; else if(poo(a,b,c,d,i) == 0) return 0;
    if(a!=b) if(poo(b,a,c,d,e) == 0) return 0;
    if(b!=c) if(poo(a,c,b,d,e) == 0) return 0;
    if(c!=d) if(poo(a,b,d,c,e) == 0) return 0;
    if(d!=e) if(poo(a,b,c,e,d) == 0) return 0;
    return 1;
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) cin >> table[i][j];
    }
    int ans = 0;
    for (int i = 0; i < 10000; i++) {
        if (!ok(i / 1000 , i / 100 % 10, i / 10 % 10, i % 10)) ans++;
    }
    cout << ans << endl;
    return 0;
}
