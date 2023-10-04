#include <stdio.h>

int main() {
    int a, b, c;
    
    // Введите значения a и b
    printf("Enter the value a: ");
    scanf("%d", &a);
    
    printf("Enter the value b: ");
    scanf("%d", &b);
    
    // Выполнение операции c = a + b
    c = a + b;
    
    // Вывод результата
    printf("c=%d\n", c);
    
    return 0;
}
