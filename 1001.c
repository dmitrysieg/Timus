#include <math.h>
#include <stdio.h>

int main() {
	double t;
	double x[131072];
	int i = 0;
	while ((scanf("%lf", &t)) > 0) {
		x[i++] = sqrt(t);
	}
	for (--i; i >= 0; --i) {
		printf("%.4lf\n", x[i]);
	}
}