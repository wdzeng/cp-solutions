#include <iostream>
using namespace std;

int spoints(char c) {
    switch (c) {
        case 'A':
            return 11;
        case 'K':
            return 4;
        case 'Q':
            return 3;
        case 'J':
            return 20;
        case 'T':
            return 10;
        case '9':
            return 14;
    }
    return 0;
}

int nspoints(char c) {
    switch (c) {
        case 'A':
            return 11;
        case 'K':
            return 4;
        case 'Q':
            return 3;
        case 'J':
            return 2;
        case 'T':
            return 10;
    }
    return 0;
}

int points(char c1, char c2, char s) { return c2 == s ? spoints(c1) : nspoints(c1); }

int main() {
    int n;
    char s;
    scanf("%d %c", &n, &s);

    char input[2];
    int sum = 0;
    for (int i = 0; i < 4 * n; i++) {
        scanf("%s", input);
        sum += points(input[0], input[1], s);
    }

    cout << sum << endl;
    return 0;
}