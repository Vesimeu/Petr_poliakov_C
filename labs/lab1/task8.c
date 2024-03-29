#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[1024];
    char new_info[1024];
    char line[1024];
    char temp_filename[] = "temp.txt";

    // Введите имя файла
    printf("Enter the file name:");
    scanf("%s", filename);

    // Открываем файл для чтения
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("ERROR = ( ");
        return 1;
    }

    // Введите информацию для добавления в начало файла
    printf("Enter the information to add to the beginning of the file: \n");
    scanf(" %[^\n]", new_info);

    // Открываем временный файл для записи
    FILE *temp_file = fopen(temp_filename, "w");
    if (temp_file == NULL) {
        perror("Error creating temporary file ");
        fclose(file);
        return 1;
    }

    // Записываем информацию в начало временного файла
    fprintf(temp_file, "%s\n", new_info);

    // Копируем содержимое исходного файла во временный
    while (fgets(line, sizeof(line), file)) {
        fprintf(temp_file, "%s", line);
    }

    // Закрываем файлы
    fclose(file);
    fclose(temp_file);

    // Заменяем исходный файл временным
    remove(filename);
    rename(temp_filename, filename);

    // Выводим содержимое файла
    printf("File contents after changes:\n");

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error file = (");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}
