#include <stdio.h>
int multiply(int a, int b);
int main() {
    int a = 0, b = 0;
    printf("Enter the value `a`:");
    scanf_s("%d", &a);
    printf("Enter the value `b`:");
    scanf_s("%d", &b);
    if (a < 0 || b < 0) {
        printf("\nBoth values must be positive integers.\n");
    } else {
        int product = multiply(a, b);
        printf("\nThe product of %d and %d is %d.\n", a, b, product);
    }
    return 0;
}

int multiply(int a, int b) {
    return (b == 0) ? 0 : (b % 2 == 0) ? 2 * multiply(a, b / 2) : a + multiply(a, b - 1);
}