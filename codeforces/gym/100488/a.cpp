#include <math.h>
#include <iostream>

using namespace std;
// AC
double area(int a, int b, int c) {
    double s = (double)(a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    double A = area(a, b, c);
    double x = (a+b+c)*r/(2*A);
    double _A = A*x*x;
    double rem =_A - r * r * 3.14159265358979323846;
    double ans = 1.0 - rem / A;
    printf("%.10lf\n", ans);
    return 0;
}