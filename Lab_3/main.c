#include <stdio.h>
#include <math.h>
int main() {
    double eps = 0.0, x = 0.0;

    printf("Enter the value of x:");
    scanf("%lf", &x);
    printf("Enter the value of eps:");
    scanf("%lf", &eps);

    double term = x;
    double y_sin = x;
    int n = 1;

    while (fabs(y_sin - sin(x)) > eps) {
        term = term * (-pow(x, 2.0) / (double)((n + 1) * (n + 2)));
        y_sin = y_sin + term;
        n = n + 2;
    }
    printf("Approximated sin(x) = %lf\n", y_sin);
    return 0;
}