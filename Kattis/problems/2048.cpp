#include <algorithm>
#include <iostream>
using namespace std;

void task(int sq[4][4]) {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (sq[i][j] == 0) {
                for (int x = j + 1; x < 4; x++) {
                    if (sq[i][x] != 0) {
                        swap(sq[i][j], sq[i][x]);
                        break;
                    }
                }
            }
            for (int x = j + 1; x < 4; x++) {
                if (sq[i][x] == 0) continue;
                if (sq[i][x] != sq[i][j]) {
                    swap(sq[i][j + 1], sq[i][x]);
                } else {
                    sq[i][j] *= 2;
                    sq[i][x] = 0;
                }
                break;
            }
        }
    }
}

int main() {
    int sq[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) cin >> sq[i][j];

    int d;
    cin >> d;
    if (d == 0) {  // left
        task(sq);
    } else if (d == 3) {  // down
        int copy[4][4];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) copy[i][j] = sq[3 - j][i];
        task(copy);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) sq[3 - j][i] = copy[i][j];
    } else if (d == 2) {  // right
        for (int i = 0; i < 4; i++) {
            swap(sq[i][0], sq[i][3]);
            swap(sq[i][1], sq[i][2]);
        }
        task(sq);
        for (int i = 0; i < 4; i++) {
            swap(sq[i][0], sq[i][3]);
            swap(sq[i][1], sq[i][2]);
        }
    } else {  // up
        int copy[4][4];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) copy[i][j] = sq[j][3 - i];
        task(copy);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) sq[j][3 - i] = copy[i][j];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << sq[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}