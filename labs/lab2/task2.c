#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
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

    // Открываем файл для записи
    FILE *file = fopen("random_array.txt", "w");
    if (file == NULL) {
        printf("Error\n");
        return 1;
    }

    // Записываем массив в файл в обратном порядке
    printf("We write the array to the file in reverse order...\n");
    for (int i = array_size - 1; i >= 0; i--) {
        fprintf(file, "%d ", random_array[i]);
    }

    // Закрываем файл
    fclose(file);
    printf("The array is written to a file 'random_array.txt '.\n");

    return 0;
}
