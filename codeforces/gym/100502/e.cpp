#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());

    list<pair<int, int>> rec;
    int prev = 0;
    int c = 0;
    for (int v : vec) {
        if (v != prev) {
            if (prev != 0) {
                rec.push_front({prev, c});
            }
           prev = v;
            c = 0;
        }
        c++;
    }
    rec.push_front({prev, c});
    
    int hit = 0;
    int height = 0;
    while (n > 0) {
        if (vec.back()- height > n) {
            n--;
            vec.pop_back();
        }  //
        else {
            height++;
            if (height >= rec.back().first) {
                n -= rec.back().second;
                rec.pop_back();
            }
        }
        hit++;
    }

    cout << hit << endl;
    return 0;
}
