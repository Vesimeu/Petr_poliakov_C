#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Проверяем, передано ли имя файла как аргумент
    if (argc != 2) {
        printf("Using: %s <name file>\n", argv[0]);
        return 1;
    }

    // Открываем файл для чтения
    FILE *file = fopen(argv[1], "r");
    
    if (file == NULL) {
        perror("ERROR = ( ");
        return 1;
    }

    // Читаем и выводим содержимое файла построчно
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    // Закрываем файл
    fclose(file);

    return 0;
}
