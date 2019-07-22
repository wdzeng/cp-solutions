#include <bits/stdc++.h>
#define M_PI 3.14159265358979323846
using namespace std;

int main() {
    double n, s;
    cin >> n >> s;
    double deg = (180.0 * n - 360.0) / n;
    double rad = deg / 180.0 * M_PI;
    rad /= 2;
    double r = (s / 2) / cos(rad);
    printf("%9lf\n", r * r * M_PI);
    return 0;
}