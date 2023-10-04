#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source_file, *output_file;
    char source_filename[1024];
    char output_filename[1024];
    char line[1024];
    int line_count = 0;

    // Введите имя исходного файла
    printf("Enter the name of the source file: ");
    scanf("%s", source_filename);

    // Открываем исходный файл для чтения
    source_file = fopen(source_filename, "r");
    if (source_file == NULL) {
        perror("ERROR = (");
        return 1;
    }

    // Введите имя файла для вывода первых трех строк
    printf("Enter the file name to output the first three lines: ");
    scanf("%s", output_filename);

    // Открываем файл для записи первых трех строк
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Error when creating a file for output");
        fclose(source_file);
        return 1;
    }

    // Читаем и записываем первые три строки
    while (fgets(line, sizeof(line), source_file) && line_count < 3) {
        fputs(line, output_file);
        line_count++;
    }

    // Закрываем файлы
    fclose(source_file);
    fclose(output_file);

    // Вывод содержимого исходного файла
    printf("Содержимое исходного файла (%s):\n", source_filename);
    source_file = fopen(source_filename, "r");
    while (fgets(line, sizeof(line), source_file)) {
        printf("%s", line);
    }
    fclose(source_file);

    // Вывод содержимого созданного файла
    printf("\nСодержимое созданного файла (%s):\n", output_filename);
    output_file = fopen(output_filename, "r");
    while (fgets(line, sizeof(line), output_file)) {
        printf("%s", line);
    }
    fclose(output_file);

    return 0;
}
