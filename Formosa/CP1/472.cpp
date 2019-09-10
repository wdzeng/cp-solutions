#include <bits/stdc++.h>
using namespace std;

inline int q(long l) { return l < 0 ? 0 : (int)sqrt(l); }

vector<int> solve5(vector<long>& inputs) {
    vector<int> ret(5);
    ret[0] = q(inputs[0]);
    ret[1] = inputs[1] / ret[0];
    ret[2] = inputs[4] / ret[0];
    ret[4] = q(inputs[24]);
    ret[3] = inputs[23] / ret[4];

    vector<long> compared;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) compared.push_back((long)ret[i] * ret[j]);
    sort(compared.begin(), compared.end());
    return inputs == compared ? ret : vector<int>();
}

vector<int> solve4(vector<long>& inputs) {
    vector<int> ret(4);
    ret[0] = q(inputs[0]);
    ret[1] = inputs[1] / ret[0];
    ret[3] = q(inputs[15]);
    ret[2] = inputs[14] / ret[3];

    vector<long> compared;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) compared.push_back((long)ret[i] * ret[j]);
    sort(compared.begin(), compared.end());
    return inputs == compared ? ret : vector<int>();
}

vector<int> solve3(vector<long>& inputs) {
    vector<int> ret(3);
    ret[0] = q(inputs[0]);
    ret[1] = inputs[1] / ret[0];
    ret[2] = q(inputs[8]);

    vector<long> compared;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) compared.push_back((long)ret[i] * ret[j]);
    sort(compared.begin(), compared.end());
    return inputs == compared ? ret : vector<int>();
}

vector<int> solve2(vector<long>& inputs) {
    vector<int> ret(2);
    ret[0] = q(inputs[0]);
    ret[1] = q(inputs[3]);

    vector<long> compared;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) compared.push_back((long)ret[i] * ret[j]);
    sort(compared.begin(), compared.end());
    return inputs == compared ? ret : vector<int>();
}

vector<int> solve1(vector<long>& inputs) {
    int n = q(inputs[0]);
    return ((long)n * n) == inputs[0] ? vector<int>{n} : vector<int>{};
}

vector<int> solve(vector<long>& inputs) {
    sort(inputs.begin(), inputs.end());
    switch (inputs.size()) {
        case 1:
            return solve1(inputs);
        case 4:
            return solve2(inputs);
        case 9:
            return solve3(inputs);
        case 16:
            return solve4(inputs);
    }
    return solve5(inputs);
}

int main() {
    string s;
    while (getline(cin, s, '\n')) {
        if (s.empty()) break;
        istringstream iss(s);
        vector<long> vec;
        for (string num; iss >> num;) {
            vec.push_back(stol(num));
        }
        vector<int> ans = solve(vec);
        if (ans.empty()) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        for (int i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}