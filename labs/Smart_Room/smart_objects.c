// В файле smart_objects.c
#include "smart_objects.h"
#include <stdio.h>
#include "smart_objects.h"
#include <stdlib.h>
#include <string.h>

// В файле smart_objects.c


SmartObject* create_object(const char* name) {
    SmartObject* obj = (SmartObject*)malloc(sizeof(SmartObject));
    if (obj == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    strcpy(obj->name, name);
    obj->light_state = 0;
    obj->thermostat_temperature = 0;
    obj->blinds_state = 0;
    printf("Комната %s успешно создана с атрибутами:\n", obj->name);
    printf("Light State: %d\n", obj->light_state);
    printf("Thermostat Temperature: %d degrees\n", obj->thermostat_temperature);
    printf("Blinds State: %d\n", obj->blinds_state);
    return obj;
}
void print_object_state(SmartObject* obj) {
    printf("Текущее состояние команты %s : Свет=%d, Температура=%d, Зановески=%d\n", obj->name, obj->light_state, obj->thermostat_temperature, obj->blinds_state);
}

void turn_on_light(SmartObject* obj) {
    obj->light_state = 1;
    printf("%s: Свет включен!\n", obj->name);

}

void turn_off_light(SmartObject* obj) {
    obj->light_state = 0;
    printf("%s: Свет выключен!\n", obj->name);

}

void set_temperature(SmartObject* obj, int temperature) {
    obj->thermostat_temperature = temperature;
    printf("%s: Температура в комнате установлена %d градусов\n", obj->name, temperature);

}

void turn_on_blinds(SmartObject* obj) {
    obj->blinds_state = 1;
    printf("%s: Blinds turned on\n", obj->name);
}

void turn_off_blinds(SmartObject* obj) {
    obj->blinds_state = 0;
    printf("%s: Blinds turned off\n", obj->name);

}