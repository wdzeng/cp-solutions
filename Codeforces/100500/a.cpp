#include <bits/stdc++.h>
using namespace std;

int arr[2][26][26];

bool judge(int me, int start) {
    int he = 1 - me;
    for (int i = 0; i < 26; i++) {
        if (arr[me][start][i] > 0) {
            arr[me][start][i]--;
            bool ret = judge(he, i);
            arr[me][start][i]++;
            if (!ret) return true;
        }
    }
    return false;
}

bool solve() {
    memset(arr, 0, sizeof(arr));
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        arr[0][s.front() - 'a'][s.back() - 'a']++;
    }
    int m;
    cin >> m;
    getline(cin, s);
    while (m--) {
        getline(cin, s);
        arr[1][s.front() - 'a'][s.back() - 'a']++;
    }
    for(int i=0;i<26;i++) {
        if(judge(0, i)) return true; 
    }
    return false;
}

int main() {
    int t; cin >> t;
    for(int i=1;i<=t;i++) {
        printf("Game %d: player%d\n", i, solve()? 1: 2);
    }
    return 0;
}