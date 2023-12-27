
#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 50  // Примерное ограничение на количество команд
Command commandList[MAX_COMMANDS];
int commandCount = 0;
AST* objects[MAX_OBJECTS];
int objectCount = 0;

AST* get_obj(const char* name) {
    for (int i = 0; i < objectCount; i++) {
        if (strcmp(objects[i]->name, name) == 0) {
            return objects[i];
        }
    }
    if (objectCount < MAX_OBJECTS) {
        AST* newObj = add_obj(name);
        objects[objectCount++] = newObj;
        return newObj;
    }

    fprintf(stderr, "Перебор\n");
    return NULL;
}
void add_command(void (*execute)(AST*, int), AST* obj, int arg) {
        if (commandCount >= MAX_COMMANDS) {
            fprintf(stderr, "Превышено максимальное количество команд\n");
            return;
        }
        commandList[commandCount].execute = execute;
        commandList[commandCount].object = obj;
        commandList[commandCount].arg = arg;
        commandCount++;
    }


void execute_command_list() {
    for (int i = 0; i < commandCount; i++) {
        Command cmd = commandList[i];
        cmd.execute(cmd.object, cmd.arg);
    }
    commandCount = 0; // Сброс списка команд после выполнения
}




AST* add_obj(const char* name) {
    for (int i = 0; i < objectCount; i++) {
        if (strcmp(objects[i]->name, name) == 0) {
            return objects[i]; 
        }
    }

    AST* obj = (AST*)malloc(sizeof(AST));
    if (!obj) {
        perror("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }
    strncpy(obj->name, name, sizeof(obj->name) - 1);
    obj->name[sizeof(obj->name) - 1] = '\0';
    obj->light_state = 0;
    obj->thermostat_temperature = 0;
    obj->set_volume = 0;
    obj->blinds_state = 0;
    if (objectCount < MAX_OBJECTS) {
        objects[objectCount++] = obj;
    } else {
        fprintf(stderr, "Превышено максимальное количество объектов\n");
        free(obj);
        return NULL;
    }

    printf("Комната %s успешно создана!\n", obj->name);
    printf("Состояние света: %d\n", obj->light_state);
    printf("Температура: %d градусов\n", obj->thermostat_temperature);
    printf("Звук установлен на %d \n", obj->thermostat_temperature);
    printf("Состояние зановесок: %d\n", obj->blinds_state);
    return obj;
}

void print_atribute_room(AST* obj) {
    if (obj != NULL) {
        printf("Инофрмация о комнате: %s : \n - Свет=%d \n - Температура=%d \n - Звук=%d \n - Зановески=%d\n", obj->name, obj->light_state, obj->thermostat_temperature, obj->set_volume, obj->blinds_state);
    } else {
        printf("Error: Object is NULL\n");
    }
}

void turn_on_light(AST* obj) {
    obj->light_state = 1;
    printf("%s: Свет включен!\n", obj->name);

}


void turn_off_light(AST* obj) {
    obj->light_state = 0;
    printf("%s: Свет выключен!\n", obj->name);

}

void conditioner(AST* obj, int temperature) {
    obj->thermostat_temperature = temperature;
    printf("%s: Кондиционер в комнате установлен на %d градусов!\n", obj->name, temperature);

}

void set_volume(AST* obj, int value) {
    obj->set_volume = value;
    if (value == 0){
        printf("Звук в комнате %s выключен!\n", obj->name);
    }
    else{   
        printf("%s: Звук в комнате установлен на %d!\n", obj->name, value);
    }

}
void turn_on_blinds(AST* obj) {
    obj->blinds_state = 1;
    printf("%s: Зановекси закрыты\n", obj->name);
}

void turn_off_blinds(AST* obj) {
    obj->blinds_state = 0;
    printf("%s: Зановески открыты\n", obj->name);
}
//сделай принт котоырй скидывает текст
void print(const char* message) {
    printf("%s\n", message);
}

