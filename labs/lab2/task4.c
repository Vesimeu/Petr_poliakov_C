#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция сортировки пузырьком
void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Обмен элементов
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("ERROR: %s <NEED 3 ARG>\n", argv[0]);
        return 1;
    }

    int array_size = atoi(argv[1]);
    float lower_bound = atof(argv[2]);
    float upper_bound = atof(argv[3]);

    if (array_size <= 0) {
        printf("The size of the array must be a positive integer.\n");
        return 1;
    }

    if (lower_bound >= upper_bound) {
        printf("The size of the array must be a positive integer !!.\n");
        return 1;
    }

    srand(time(NULL));


    float random_array[array_size];
    for (int i = 0; i < array_size; i++) {
        float random_number = lower_bound + ((float)rand() / RAND_MAX) * (upper_bound - lower_bound);
        random_array[i] = random_number;
    }


    printf("Random array size %d in the interval (%.2f, %.2f):\n", array_size, lower_bound, upper_bound);
    for (int i = 0; i < array_size; i++) {
        printf("%.2f ", random_array[i]);
    }
    printf("\n");


    bubbleSort(random_array, array_size);

    printf("Sorted array:\n");
    for (int i = 0; i < array_size; i++) {
        printf("%.2f ", random_array[i]);
    }
    printf("\n");

    FILE *file = fopen("sorted_array.txt", "w");
    if (file == NULL) {
        printf("Error^ka .\n");
        return 1;
    }

    for (int i = 0; i < array_size; i++) {
        fprintf(file, "%.2f ", random_array[i]);
    }

    fclose(file);
    printf("The sorted array is written to a file 'sorted_array.txt '.\n");

    return 0;
}
