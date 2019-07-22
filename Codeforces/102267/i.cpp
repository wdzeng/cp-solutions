#include <bits/stdc++.h>
using namespace std;

char buff[1000002];
int n;
vector<int> ans;

int next_num(int& index) {
    string s = "";
    while (buff[index] >= '0' && buff[index] <= '9') {
        s += buff[index];
        index++;
    }
    return stoi(s);
}

void findat(int& index, int juren) {
    while (true) {
        char c = buff[index];  // (
        index++;

        int num = next_num(index);
        ans[num] = juren;
        // printf("%d => %d\n", num, juren);

        char d = buff[index];
        if (d == '(') findat(index, num);
        // here d must be )
        index++;
        // printf("%d: %c\n", index, buff[index]);
        if (buff[index] != '(') return;
    }
}

int main() {
    cin >> n;
    cin >> buff;

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    ans.resize(n + 1);
    int index = 0;
    int first = next_num(index);
    ans[first] = 0;
    findat(index, first);

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}