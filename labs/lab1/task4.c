#include <stdio.h>

int main() {
    double a, b, c, x;

    // Введите коэффициенты a, b и c
    printf("Enter the value a: ");
    scanf("%lf", &a);

    printf("Enter the value b: ");
    scanf("%lf", &b);

    printf("Enter the value c: ");
    scanf("%lf", &c);

    // Решение линейного уравнения
    if (a == 0) {
        if (b == c) {
            printf("x is any number\n");
        } else {
            printf("The equation has no solution = ( \n");
        }
    } else {
        x = (c - b) / a;
        printf("x=%lf\n", x);
    }

    return 0;
}
