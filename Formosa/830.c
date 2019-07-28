#include <math.h>
#include <stdio.h>
// AC
typedef struct {
    double x, y;
} point;

double dia(point p) { return p.x * p.x + p.y * p.y; }

point waiShin(point p1, point p2, point p3) {
    double dd = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) -
                (p2.y * p3.x + p3.y * p1.x + p1.y * p2.x);
    dd *= 2;
    double p12 = dia(p1);
    double p22 = dia(p2);
    double p32 = dia(p3);

    double dx = (p12 * p2.y + p22 * p3.y + p32 * p1.y) -
                (p3.y * p12 + p2.y * p32 + p1.y * p22);
    double dy = (p1.x * p22 + p2.x * p32 + p3.x * p12) -
                (p22 * p3.x + p32 * p1.x + p12 * p2.x);
    point res = {.x = dx / dd, .y = dy / dd};
    return res;
}

int isLine(point p1, point p2, point p3) {
    if (p1.x == p2.x) {
        return p2.x == p3.x;
    }
    return (p3.y - p1.y) / (p3.x - p1.x) == (p2.y - p1.y) / (p2.x - p1.x);
}

void sort2(point* p1, point* p2) {
    if (p1->x > p2->x) {
        point tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
    } else if (p1->x == p2->x && p1->y > p2->y) {
        point tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
    }
}

void sort(point* p1, point* p2, point* p3) {
    sort2(p1, p2);
    sort2(p1, p3);
    sort2(p2, p3);
}

double len2(point p1, point p2) {
    double dx = p1.x - p2.x;
    double dy = p2.y - p1.y;
    return dx * dx + dy * dy;
}

double len(point p1, point p2) { return sqrt(len2(p1, p2)); }

void printMid(point p1, point p2) {
    printf("%lf %lf %lf\n", (p1.x + p2.x) / 2, (p1.y + p2.y) / 2,
           len(p1, p2) / 2);
}

int fatTriangle(point p1, point p2, point p3) {
    double c, a, b;
    double len12 = len2(p1, p2), len23 = len2(p2, p3), len31 = len2(p3, p1);
    if (len12 >= len23 && len12 >= len31) {
        if (len23 + len31 <= len12) {
            printMid(p1, p2);
            return 1;
        }
        return 0;
    }
    if (len23 >= len31 && len12 >= len12) {
        if (len31 + len12 <= len23) {
            printMid(p3, p2);
            return 1;
        }
        return 0;
    }
    if (len31 >= len12 + len23) {
        printMid(p3, p1);
        return 1;
    }
    return 0;
}

int thinTriangle(point p1, point p2, point p3) {
    // printf("/");
    point ws = waiShin(p1, p2, p3);
    printf("%lf %lf %lf\n", ws.x, ws.y, len(ws, p1));
    return 1;
}

void solve(point p1, point p2, point p3) {
    //printf("(%g, %g) (%g, %g) (%g, %g)\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    sort(&p1, &p2, &p3);
    //printf("(%g, %g) (%g, %g) (%g, %g)\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    if (isLine(p1, p2, p3)) {
        printMid(p1, p3);
        return;
    }
    fatTriangle(p1, p2, p3) || thinTriangle(p1, p2, p3);
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) !=
           EOF) {
        point a = {.x = x1, .y = y1};
        point b = {.x = x2, .y = y2};
        point c = {.x = x3, .y = y3};
        solve(a, b, c);
    }
}