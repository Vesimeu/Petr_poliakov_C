#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для хранения данных о товаре
struct Product {
    char name[100];
    float price;
};

// Функция для сравнения двух товаров по цене (для сортировки)
int compareProducts(const void *a, const void *b) {
    const struct Product *productA = (const struct Product *)a;
    const struct Product *productB = (const struct Product *)b;
    return (productA->price > productB->price) - (productA->price < productB->price);
}

int main() {
    // Открываем входной файл для чтения
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

    // Считываем количество товаров из входного файла
    int numProducts;
    fscanf(inputFile, "%d", &numProducts);

    // Выделяем память для массива товаров
    struct Product *products = (struct Product *)
    malloc(numProducts * sizeof(struct Product));
    if (products == NULL) {
        printf("Memory allocation error.\n");
        fclose(inputFile);
        return 1;
    }

    // Считываем данные о товарах из входного файла
    for (int i = 0; i < numProducts; i++) {
        fscanf(inputFile, "%s %f", products[i].name, &products[i].price);
    }

    // Закрываем входной файл
    fclose(inputFile);

    // Сортируем товары по цене
    qsort(products, numProducts, sizeof(struct Product), compareProducts);

    // Открываем выходной файл для записи
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error when opening the output file.\n");
        free(products);
        return 1;
    }

    // Записываем отсортированные данные в выходной файл
    fprintf(outputFile, " Sorted products by price:\n");
    for (int i = 0; i < numProducts; i++) {
        fprintf(outputFile, "%s %.2f\n", products[i].name, products[i].price);
    }

    // Закрываем выходной файл
    fclose(outputFile);

    // Освобождаем выделенную память
    free(products);

    printf("The data has been successfully sorted and written to a file 'output.txt '.\n");

    return 0;
}


// Пример input.txt:

// Copy code
// 4
// Product1 10.50
// Product2 5.99
// Product3 20.00
// Product4 7.25