#include <stdio.h>

int main() {
    double a, b, c, x;

    // Введите коэффициенты a, b и c
    printf("Введите значение a: ");
    scanf("%lf", &a);

    printf("Введите значение b: ");
    scanf("%lf", &b);

    printf("Введите значение c: ");
    scanf("%lf", &c);

    // Решение линейного уравнения
    if (a == 0) {
        if (b == c) {
            printf("x - любое число\n");
        } else {
            printf("Уравнение не имеет решения\n");
        }
    } else {
        x = (c - b) / a;
        printf("x=%lf\n", x);
    }

    return 0;
}
