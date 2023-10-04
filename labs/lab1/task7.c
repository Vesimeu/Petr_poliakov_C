#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[1024];
    char new_line[1024];

    // Введите имя файла
    printf("Введите имя файла для дописывания: ");
    scanf("%s", filename);

    // Открываем файл для дописывания (режим "a" - дописывание)
    file = fopen(filename, "a");
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return 1;
    }

    // Введите строку для дописывания
    printf("Введите строку для дописывания в файл: ");
    scanf(" %[^\n]", new_line);

    // Дописываем строку в файл
    fprintf(file, "%s\n", new_line);

    // Закрываем файл
    fclose(file);

    // Выводим содержимое файла
    printf("Содержимое файла после дописывания:\n");

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}
