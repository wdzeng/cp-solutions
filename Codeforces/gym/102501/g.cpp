#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int s, f, n;
    cin >> s >> f >> n;

    vector<string> animals;
    unordered_map<string, int> a2i;
    for (int i = 0; i < s; i++) {
        string animal;
        cin >> animal;
        animals.push_back(animal);
        a2i[animal] = i;
    }

    int love[s][s];
    ms(love);
    for (int i = 0; i < f; i++) {
        string a, b;
        cin >> a >> b;
        int x = a2i[a], y = a2i[b];
        love[x][y] = love[y][x] = 1;
    }

    vector<vector<int>> locs(s);
    vector<int> line;
    for (int i = 0; i < n; i++) {
        string animal;
        cin >> animal;
        int index = a2i[animal];
        locs[index].push_back(i);
        line.push_back(index);
    }

    /*for (int i = 0; i < s; i++) {
        cout << animals[i] << ' ';
        for (int loc : locs[i]) cout << loc << ' ';
        cout << endl;
    }*/

    vector<vector<int>> pointedBy(n);
    vector<int> deg(n);

    for (int i = 0; i < s; i++) {
        for (int j = i + 1; j < s; j++) {
            if (love[i][j]) continue;
            // cout << "hate " << animals[i] << ' ' << animals[j] << endl;
            vector<int> merge;
            int a = 0, b = 0;
            while (a < locs[i].size() || b < locs[j].size()) {
                if (a == locs[i].size()) {
                    merge.push_back(locs[j][b++]);
                } else if (b == locs[j].size()) {
                    merge.push_back(locs[i][a++]);
                } else {
                    if (locs[i][a] < locs[j][b])
                        merge.push_back(locs[i][a++]);
                    else
                        merge.push_back(locs[j][b++]);
                }
            }
            /*cout << "m ";
            for (auto mm : merge) cout << mm << ' ';
            cout << endl;*/
            for (int i = 0; i < merge.size(); i++) {
                if (i != merge.size() - 1) pointedBy[merge[i]].push_back(merge[i + 1]);
                if (i != 0) {
                    deg[merge[i]]++;
                    // cout << merge[i] << " point to " << merge[i - 1] << endl;
                }
            }
        }
    }

   /* for (int i = 0; i < n; i++) {
        cout << i << " has deg " << deg[i] << " pointed by ";
        for (auto pb : pointedBy[i]) cout << pb << ' ';
        cout << endl;
    }*/

    priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.emplace(animals[line[i]], i);
        }
    }

    vector<string> ans;
    while (!q.empty()) {
        auto v = q.top();
        q.pop();
        int index = v.y;
        ans.push_back(v.x);
        // cout << "Pop " << v.x << " = " << index << endl;
        for (int pb : pointedBy[index]) {
            deg[pb]--;
            if (deg[pb] == 0) {
                q.emplace(animals[line[pb]], pb);
                // cout << "Push " << animals[line[pb]] << " = " << pb << endl;
            }
        }
    }

    assert(ans.size() == line.size());
    for(auto a: ans) cout << a << ' ';
    cout << endl;

    return 0;
}