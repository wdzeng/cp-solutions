#include <bits/stdc++.h>
using namespace std;

int inc() {
    static int v = 0;
    return v++;
}

const int maxn = 1001;
vector<pair<int, int>> rec;
vector<int> follow(maxn, -1);
vector<int> followed[maxn];
bool colored[maxn];
int n, k;

int paintfollowed(int i) {
    if (colored[i]) return 0;
    colored[i] = true;
    int ret = 1;
    for (int f : followed[i]) {
        ret += paintfollowed(f);
    }
    return ret;
}

void paint(int i) {
    vector<int> flag(n + 1, 0);
    vector<int> pass;
    int minn = 0, maxx = 0;
    while (flag[follow[i]] == 0) {
        flag[i] = ++minn;
        pass.push_back(i);
        i = follow[i];
    }
    minn = minn - flag[i] + 1;

    for (int p : pass) maxx += paintfollowed(p);
    rec.emplace_back(minn, maxx);
}

int kp() {
    int m = rec.size();
    int arr[m + 1][k + 1];
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i <= m; i++) {
        for (int w = 0; w <= k; w++) {
            if (i == 0 || w == 0) continue;
            
            if (rec[i - 1].first > w)
                arr[i][w] = arr[i - 1][w];

            else {
                for (int v = rec[i - 1].first; v <= rec[i - 1].second && v <= w; v++) {
                    arr[i][w] = max(arr[i][w], max(arr[i - 1][w], v + arr[i - 1][w - v]));
                }
            }
        }
    }

    //   for (int i = 0; i <= m; i++) {
    //       for (int j = 0; j <= k; j++) printf("%2d", arr[i][j]);
    //      cout << endl;
    //  }

    return arr[m][k];
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x != i) followed[x].push_back(i);
        follow[i] = x;
    }

    for (int i = 1; i <= n; i++)
        if (!colored[i]) paint(i);

    //   for (auto p : rec) printf("(%d, %d) ", p.first, p.second);
    //   cout << endl;

    cout << kp() << endl;
    return 0;
}