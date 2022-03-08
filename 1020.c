#include <math.h>
#include <stdio.h>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

double getCircleLength(double x1, double y1, double x2, double y2, double x3, double y3, double b, double c, double r) {
    //printf("upper side = %lf\n", (x2 - x3) * (x2 - x1) + (y2 - y3) * (y2 - y1));
    //printf("down side = %lf\n", b * c);
    double cosAlpha = ((x2 - x3) * (x2 - x1) + (y2 - y3) * (y2 - y1)) / (b * c);
    //printf("acos = %lf\n", acos(cosAlpha));
    return (M_PI - acos(cosAlpha)) * r;
}

double getDistance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double calculateLength(int n, double r, double *x, double *y) {
    if (n == 1) {
        return 2.0 * M_PI * r;
    }
    
    /*for (int i = 0; i < n; i++) {
        printf("%d:\tx = %lf\t\ty = %lf\n", i, x[i], y[i]);
    }*/
    
    double l = 0.0;
    double b, c;
    b = getDistance(x[1], y[1], x[0], y[0]);
    //printf("initial b = %lf\n", b);
    for (int i = 0; i < n; i++) {
        l = l + b;
        c = getDistance(x[(i + 1) % n], y[(i + 1) % n], x[(i + 2) % n], y[(i + 2) % n]);
        //printf("c = %lf\n", c);
        double cl = getCircleLength(
            x[i], y[i],
            x[(i + 1) % n], y[(i + 1) % n],
            x[(i + 2) % n], y[(i + 2) % n],
            b, c, r
        );
        //printf("cl = %lf\n", cl);
        l = l + cl;
        b = c;
    }
    
    return l;
}

int main() {
    int n;
    double r;
    scanf("%d%lf", &n, &r);
    
    double x[n], y[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &x[i], &y[i]);
    }
    //printf("n = %d\nr = %lf\n", n, r);
    printf("%.2lf", calculateLength(n, r, x, y));
}