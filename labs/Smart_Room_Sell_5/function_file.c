
#include "head_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 50  // Примерное ограничение на количество команд
Action actionQueue[MAX_COMMANDS];
int actionCount = 0;
Device* devices[MAX_OBJECTS];
int deviceCount = 0;

Device* get_device(const char* name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i]->name, name) == 0) {
            return devices[i];
        }
    }
    if (deviceCount < MAX_OBJECTS) {
        Device* newObj = create_device(name);
        devices[deviceCount++] = newObj;
        return newObj;
    }

    fprintf(stderr, "Перебор\n");
    return NULL;
}
void enqueue_action(void (*execute)(Device*, int), Device* obj, int arg) {
        if (actionCount >= MAX_COMMANDS) {
            fprintf(stderr, "Превышено максимальное количество команд\n");
            return;
        }
        actionQueue[actionCount].execute = execute;
        actionQueue[actionCount].object = obj;
        actionQueue[actionCount].arg = arg;
        actionCount++;
    }


void execute_actions() {
    for (int i = 0; i < actionCount; i++) {
        Action cmd = actionQueue[i];
        cmd.execute(cmd.object, cmd.arg);
    }
    actionCount = 0; 
}


void print_message(const char* message) {
    printf("Сообщение системы: %s\n", message);
}

Device* create_device(const char* name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i]->name, name) == 0) {
            return devices[i]; 
        }
    }

    Device* obj = (Device*)malloc(sizeof(Device));
    if (!obj) {
        perror("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }
    strncpy(obj->name, name, sizeof(obj->name) - 1);
    obj->name[sizeof(obj->name) - 1] = '\0';
    obj->light = 0;
    obj->aircon = 0;
    obj->volume = 0;
    obj->blinds = 0;
    if (deviceCount < MAX_OBJECTS) {
        devices[deviceCount++] = obj;
    } else {
        fprintf(stderr, "Превышено максимальное количество объектов\n");
        free(obj);
        return NULL;
    }

    printf("Новая комната %s успешно добавлена в систему управления.\n", obj->name);
    printf("Начальное состояние освещения: %s.\n", obj->light ? "включено" : "выключено");
    printf("Текущая температура: %d°C (по умолчанию).\n", obj->aircon);
    printf("Начальный уровень звука: %d (настройки по умолчанию).\n", obj->volume);
    printf("Состояние зановесок: %s.\n", obj->blinds ? "закрыты" : "открыты");
    return obj;
}


void print_atribute_room(Device* obj) {
    if (obj != NULL) {
        printf("Детали комнаты %s: \n - Свет: %s \n - Температура: %d°C \n - Звук: %s \n - Зановески: %s\n",
               obj->name,
               obj->light ? "включен" : "выключен",
               obj->aircon,
               obj->volume ? "настроен" : "выключен",
               obj->blinds ? "закрыты" : "открыты");
    } else {
        printf("Ошибка: Объект не определен!\n");
    }
}

void set_light_mode(Device* obj, int mode) {
    if (mode) {  // Если mode равно 1 (или true), включить свет
        obj->light = 1;
        printf("Освещение в %s теперь светит ярко!\n", obj->name);
    } else {  // Если mode равно 0 (или false), выключить свет
        obj->light = 0;
        printf("В %s теперь темно, свет выключен.\n", obj->name);
    }
}

void turn_on_light(Device* obj) {
    obj->light = 1;
    printf("Освещение в %s теперь светит ярко!\n", obj->name);
}

void turn_off_light(Device* obj) {
    obj->light = 0;
    printf("В %s теперь темно, свет выключен.\n", obj->name);
}

void adjust_aircon(Device* obj, int aircon) {
    obj->aircon = aircon;
    printf("В %s установлена комфортная температура %d°C.\n", obj->name, aircon);
}

void set_audio_level(Device* obj, int value) {
    obj->volume = value;
    if (value == 0) {
        printf("Тишина в комнате %s, звук выключен.\n", obj->name);
    } else {
        printf("В %s уровень звука установлен на %d.\n", obj->name, value);
    }
}

void turn_on_shades(Device* obj) {
    obj->blinds = 1;
    printf("В %s зановески закрыты для уюта.\n", obj->name);
}

void turn_off_shades(Device* obj) {
    obj->blinds = 0;
    printf("В %s зановески открыты, впуская свет!\n", obj->name);
}