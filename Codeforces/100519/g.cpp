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

vector<int> dad;
vector<int> sixe;

int query(const string& name) {
    static unordered_map<string, int> mmap;
    if (mmap.count(name) == 0) {
        mmap[name] = mmap.size();
    }
    return mmap[name];
}

inline string lname(const string& strfam, const string& strfir) { return strfam + ' ' + strfir; }

int find_ring(int i, int c) {
    if (i == -1) return -1;
    if (sixe[i] > 0) return sixe[i];
    if (sixe[i] == 0) {
        sixe[i] = c;
        int ret = find_ring(dad[i], c - 1);
        if (sixe[i] < 0)
            return sixe[i] = ret + 1;
        else
            return sixe[i];
    }
    // find loop
    int ring_size = sixe[i] - c;
    assert(ring_size > 0);
    sixe[i] = ring_size;
    for (int x = dad[i]; x != i; x = dad[x]) {
        assert(x != -1);
        sixe[x] = ring_size;
    }
    return ring_size;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    dad.assign(n * 2, -1);
    for (int i = 0; i < n; i++) {
        string strfam, strson, strdad, sonof;
        cin >> strfam >> strson >> sonof >> sonof >> strdad;
        int s = query(lname(strfam, strson));
        int d = query(lname(strfam, strdad));
        dad[s] = d;
    }

    // find ring
    sixe.assign(n * 2, 0);
    for (int i = 0; i < n * 2; i++) {
        find_ring(i, -1);
    }

    // for(int z: dad) cout << z << ' '; cout << endl;
    // for(int z: sixe) cout << z << ' '; cout << endl;

    int maxx = *max_element(iter(sixe));
    cout << maxx << endl;
    return 0;
}