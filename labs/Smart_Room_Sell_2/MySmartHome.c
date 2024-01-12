
#include "MySmartHome.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 50  // Примерное ограничение на количество команд
Action actionQueue[MAX_COMMANDS];
int actionCount = 0;
Home* devices[MAX_OBJECTS];
int deviceCount = 0;

// Символы для украшения вывода
#define LIGHT_ON "💡"
#define LIGHT_OFF "🌑"
#define AIRCON_ON "🌡️"
#define AIRCON_OFF "❄️"
#define AUDIO_ON "🔊"
#define AUDIO_OFF "🔇"
#define BLINDS_OPEN "🌤️"
#define BLINDS_CLOSED "🌙"
#define INFO_PREFIX "🔍"
#define ERROR_PREFIX "❌"
#define SUCCESS_PREFIX "✅"



Home* retrieve_device(const char* name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i]->name, name) == 0) {
            return devices[i];
        }
    }
    if (deviceCount < MAX_OBJECTS) {
        Home* newObj = create_device(name);
        devices[deviceCount++] = newObj;
        return newObj;
    }

    fprintf(stderr, "Перебор\n");
    return NULL;
}
void add_action_to_queue(void (*execute)(Home*, int), Home* obj, int arg) {
        if (actionCount >= MAX_COMMANDS) {
            fprintf(stderr, "Превышено максимальное количество команд\n");
            return;
        }
        actionQueue[actionCount].execute = execute;
        actionQueue[actionCount].object = obj;
        actionQueue[actionCount].arg = arg;
        actionCount++;
    }


void perform_all_actions() {
    for (int i = 0; i < actionCount; i++) {
        Action cmd = actionQueue[i];
        cmd.execute(cmd.object, cmd.arg);
    }
    actionCount = 0; 
}

//ENTER OUTPUT
void display_system_message(const char* message) {
    printf("[Система Умный Дом] 🏠: %s \n", message);
}

Home* create_device(const char* name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i]->name, name) == 0) {
            return devices[i];
        }
    }

    Home* obj = (Home*)malloc(sizeof(Home));
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
        printf("%s Комната '%s' успешно добавлена в систему управления.\n", SUCCESS_PREFIX, obj->name);
        printf("  - Начальное состояние: Свет %s, Температура %d°C, Звук %s, Занавески %s.\n",
               obj->light ? "включен" : "выключен",
               obj->aircon,
               obj->volume ? "настроен" : "выключен",
               obj->blinds ? "открыты" : "закрыты");
    } else {
        fprintf(stderr, "%s Превышено максимальное количество объектов\n", ERROR_PREFIX);
        free(obj);
        return NULL;
    }

    return obj;
}

void information(Home* obj) {
    if (obj != NULL) {
        printf("%s Информация о комнате '%s': \n - Свет: %s %s \n - Температура: %s %d°C \n - Звук: %s %s \n - Занавески: %s %s\n",
               INFO_PREFIX,
               obj->name,
               obj->light ? LIGHT_ON : LIGHT_OFF,
               obj->light ? "включен" : "выключен",
               obj->aircon > 0 ? AIRCON_ON : AIRCON_OFF,
               obj->aircon,
               obj->volume ? AUDIO_ON : AUDIO_OFF,
               obj->volume ? "настроен" : "выключен",
               obj->blinds ? BLINDS_OPEN : BLINDS_CLOSED,
               obj->blinds ? "открыты" : "закрыты");
    } else {
        printf("%s Ошибка: Объект не определен!\n", ERROR_PREFIX);
    }
}

//MYCOOMANDS: 
//turn_on_light
void activited_light(Home* obj) {
    obj->light = 1;
    printf("%s Свет в %s включен!\n", LIGHT_ON, obj->name);
}

void deactivited_light(Home* obj) {
    obj->light = 0;
    printf("%s В %s свет выключен.\n", LIGHT_OFF, obj->name);
}

void aircon(Home* obj, int aircon) {
    obj->aircon = aircon;
    printf("%s В %s температура установлена на %d°C.\n", AIRCON_ON, obj->name, aircon);
}

void set_audio(Home* obj, int value) {
    obj->volume = value;
    if (value == 0) {
        printf("%s В %s звук выключен.\n", AUDIO_OFF, obj->name);
    } else {
        printf("%s В %s звук установлен на уровень %d.\n", AUDIO_ON, obj->name, value);
    }
}


void shades_on(Home* obj) {
    obj->blinds = 1;
    printf("%s В %s занавески открыты.\n", BLINDS_OPEN, obj->name);
}

void shades_off(Home* obj) {
    obj->blinds = 0;
    printf("%s В %s занавески закрыты.\n", BLINDS_CLOSED, obj->name);
}