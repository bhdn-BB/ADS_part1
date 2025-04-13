#include <stdio.h>
int main() {
    double x = 0.0;
    printf("Enter the value of x:");
    scanf("%lf", &x);
    double y = (x > 0.0) ? (x * x) : -x;
    printf("y = %g", y);
    return 0;
}