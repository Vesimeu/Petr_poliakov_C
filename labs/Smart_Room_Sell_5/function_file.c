
#include "head_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 56
Command actionQueue[MAX_COMMANDS];
int actionCount = 0;
Room* devices[MAX_OBJECTS];
int deviceCount = 0;

void enqueue_action(void (*execute)(Room*, int), Room* obj, int arg) {
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
        Command cmd = actionQueue[i];
        cmd.execute(cmd.object, cmd.arg);
    }
    actionCount = 0; 
}


void print_message(const char* message) {
    printf("Сообщение системы: %s\n", message);
}

Room* create_device(const char* name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i]->name, name) == 0) {
            return devices[i]; 
        }
    }

    Room* obj = (Room*)malloc(sizeof(Room));
    if (!obj) {
        perror("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }
    strncpy(obj->name, name, sizeof(obj->name) - 1);
    obj->name[sizeof(obj->name) - 1] = '\0';
    obj->light = 0;
    obj->aircon = 15;
    obj->volume = 0;
    obj->blinds = 0;
    obj->safe = 0;
    if (deviceCount < MAX_OBJECTS) {
        devices[deviceCount++] = obj;
    } else {
        fprintf(stderr, "Превышено максимальное количество объектов\n");
        free(obj);
        return NULL;
    }

    printf("⚠️ Новая комната %s успешно добавлена в систему управления.\n", obj->name);
    return obj;
}


void print_information_room(Room* obj) {
    if (obj != NULL) {
        printf("🌟 Инофрмация о комнате: %s 🌟\n", obj->name);
        printf("├── Свет: %s %s\n", obj->light ? "💡" : "🌑", obj->light ? "Включен" : "Выключен");
        printf("├── Температура: %d°C %s\n", obj->aircon, obj->aircon > 22 ? "🔥 Тепло" : "❄️ Прохладно");
        printf("├── Звук: %s %d\n", obj->volume ? "🔊" : "🔈", obj->volume);
        printf("└── Занавески: %s %s\n", obj->blinds ? "🚪 Закрыты" : "🌅 Открыты", obj->blinds ? "| Уютно" : "| Много света");
        printf("└── Система безопасности: %s %s\n", obj->safe ? "🔒" : "🔓", obj->safe ? "Включена" : "Отключена");
    } else {
        printf("⚠️ Ошибка: Комната не определена!\n");
    }
}
void set_safe_mode(Room* obj, int mode) {
    if (mode) {  
        obj->safe = 1;
        printf("- Система безопасности в комнате %s включена!\n", obj->name);
    } else {  
        obj->safe = 0;
        printf("- Система безопасности в комнате %s отключена!\n", obj->name);
    }
}

void set_light_mode(Room* obj, int mode) {
    if (mode) {  // Если mode равно 1 (или true), включить свет
        obj->light = 1;
        printf("- Освещение в %s теперь светит ярко!\n", obj->name);
    } else {  // Если mode равно 0 (или false), выключить свет
        obj->light = 0;
        printf("- В %s теперь темно, свет выключен.\n", obj->name);
    }
}

void set_blinds_mode(Room* obj, int mode) {
    if (mode) {  // Если mode равно 1 (или true), закрыть занавески
        obj->blinds = 1;
        printf("- В %s зановески закрыты для уюта.\n", obj->name);
    } else {  // Если mode равно 0 (или false), открыть занавески
        obj->blinds = 0;
        printf("- В %s зановески открыты, впуская свет!\n", obj->name);
    }
}

void set_temperature(Room* obj, int aircon) {
    // Проверка на допустимый диапазон температур
    if (aircon < 15 || aircon > 30) {
        printf("- ⚠️ Температура должна быть в пределе от 15°C до 30°C!\n");
        return;
    }

    // Установка температуры
    obj->aircon = aircon;

    // Вывод различных сообщений в зависимости от уровня температуры
    if (aircon <= 18) {
        printf("- ❄️ В комнате %s установлена прохладная температура %d°C. Освежающе!\n", obj->name, aircon);
    } else if (aircon > 18 && aircon <= 22) {
        printf("- 🌡️ В %s установлена комфортная температура %d°C. Идеально для отдыха!\n", obj->name, aircon);
    } else if (aircon > 22 && aircon < 26) {
        printf("- ☀️ В %s установлена теплая температура %d°C. Уютно и тепло!\n", obj->name, aircon);
    } else {
        printf("- 🔥 В %s установлена жаркая температура %d°C. Летнее настроение!\n", obj->name, aircon);
    }
}

void set_audio_level(Room* obj, int value) {
    // Проверка на допустимый диапазон значений
    if (value < 0 || value > 100) {
        printf("- ⚠️ Уровень звука должен быть в пределе от 0 до 100!\n");
        return;
    }

    // Установка уровня звука
    obj->volume = value;

    // Вывод различных сообщений в зависимости от уровня громкости
    if (value == 0) {
        printf("- 🔇 В комнате %s наступила тишина, звук выключен.\n", obj->name);
    } else if (value > 0 && value <= 30) {
        printf("- 🔈 В %s уровень звука установлен на тихий %d.\n", obj->name, value);
    } else if (value > 30 && value <= 70) {
        printf("- 🔉 В %s уровень звука установлен на средний %d.\n", obj->name, value);
    } else if (value > 70 && value < 100) {
        printf("- 🔊 В %s уровень звука установлен на громкий %d.\n", obj->name, value);
    } else {
        printf("- 🎶 Музыка в комнате %s включена на полную громкость %d!\n", obj->name, value);
    }
}
