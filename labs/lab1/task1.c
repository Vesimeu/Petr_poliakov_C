#include <stdio.h>

int main() {
    int a, b;

    printf("Введите значение a: ");
    scanf("%d", &a);

    printf("Введите значение b: ");
    scanf("%d", &b);

    int c = a + b;

    printf("c=%d\n", c);

    return 0;
}
