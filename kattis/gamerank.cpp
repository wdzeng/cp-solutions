#include <bits/stdc++.h>
using namespace std;

int ranks[] = {0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2};

int main() {
    int rnk = 25;
    int star = 0;
    int cwin = 0;

    string str;
    cin >> str;
    for (char c : str) {
        if (c == 'W') {
            cwin++;
            star++;
            if (cwin >= 3 && rnk >= 6 && rnk <= 25) star++;
            if (rnk > 0 && star > ranks[rnk]) {
                star -= ranks[rnk];
                rnk--;
            }
        }  //
        else {
            cwin = 0;
            if (rnk >= 1 && rnk <= 20) {
                star--;
                if (star == -1) {
                    if (rnk == 20)
                        star = 0;
                    else {
                        rnk++;
                        star = ranks[rnk] - 1;
                    }
                }
            }
        }
    }
    if (rnk == 0)
        cout << "Legend\n";
    else
        cout << rnk << endl;
    return 0;
}