#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Установим начальное значение для генератора случайных чисел на основе времени
    srand(time(NULL));

    // Размер массива
    int array_size = 10;

    // Создаем и заполняем массив случайными числами
    int random_array[array_size];
    for (int i = 0; i < array_size; i++) {
        random_array[i] = rand();
    }

    // Выводим массив в консоль
    printf("Random array:\n");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", random_array[i]);
    }
    printf("\n");

    return 0;
}
