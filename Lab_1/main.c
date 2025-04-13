#include <stdio.h>
#include <math.h>.
int main() {
    double a = 0.0;
    printf("A =");
    scanf("%lf", &a);
    double x = 9.0 * log(a);
    double y = 5.0 / (fabs(5.0 * x - 3.0) + 8.0);
    printf("X =%g\n"
                 "Y = %g", x, y);
    return 0;
}