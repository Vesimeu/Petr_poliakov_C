#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("ERROR! NO ARGUMENT %s \n", argv[0]);
        return 1;
    }

    int array_size = atoi(argv[1]);
    if (array_size <= 0) {
        printf("The size of the array must be a positive integer.\n");
        return 1;
    }

    // Установим начальное значение для генератора случайных чисел на основе времени
    srand(time(NULL));

    // Создаем и заполняем массив случайными числами с плавающей точкой
    float random_array[array_size];
    for (int i = 0; i < array_size; i++) {
        random_array[i] = (float)rand() / RAND_MAX; // Генерация числа в интервале (0, 1)
    }

    // Выводим массив в консоль
    printf("Massive random number. Lenght massive = %d\n", array_size);
    for (int i = 0; i < array_size; i++) {
        printf("%.6f ", random_array[i]);
    }
    printf("\n");

    return 0;
}
