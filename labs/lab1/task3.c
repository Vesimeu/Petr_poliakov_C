#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Количество аргументов: %d\n", argc);

    printf("Аргументы:\n");
    for (int i = 0; i < argc; i++) {
        printf("Аргумент %d: %s\n", i, argv[i]);
    }

    return 0;
}
