#include <stdio.h>

int main() {
    int a, b, c;
    
    // Введите значения a и b
    printf("Введите значение a: ");
    scanf("%d", &a);
    
    printf("Введите значение b: ");
    scanf("%d", &b);
    
    // Выполнение операции c = a + b
    c = a + b;
    
    // Вывод результата
    printf("c=%d\n", c);
    
    return 0;
}
