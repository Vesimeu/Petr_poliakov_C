// В файле smart_objects.c
#include "smart_objects.h"
#include <stdio.h>
#include "smart_objects.h"
#include <stdlib.h>
#include <string.h>

SmartObject* create_object(const char* name) {
    SmartObject* obj = (SmartObject*)malloc(sizeof(SmartObject));
    if (obj == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    strcpy(obj->name, name);
    obj->state.light_state = 0; // Изначально свет выключен
    obj->state.thermostat_temperature = 0; // Изначально температура не установлена
    obj->state.blinds_state = 0; // Изначально жалюзи выключены

    printf("Object '%s' created with initial attributes:\n", obj->name);
    printf("Light State: %d\n", obj->state.light_state);
    printf("Thermostat Temperature: %d degrees\n", obj->state.thermostat_temperature);
    printf("Blinds State: %d\n", obj->state.blinds_state);

    return obj;
}

void print_object_state(SmartObject* obj) {
    printf("%s State: Light=%d, Thermostat=%d, Blinds=%d\n", obj->name, obj->state.light_state, obj->state.thermostat_temperature, obj->state.blinds_state);
}

void turn_on_light(SmartObject* obj) {
    obj->state.light_state = 1;
    printf("%s: Light turned on\n", obj->name);
    print_object_state(obj);
}

void turn_off_light(SmartObject* obj) {
    obj->state.light_state = 0;
    printf("%s: Light turned off\n", obj->name);
    print_object_state(obj);
}

void set_temperature(SmartObject* obj, int temperature) {
    obj->state.thermostat_temperature = temperature;
    printf("%s: Thermostat set to %d degrees\n", obj->name, temperature);
    print_object_state(obj);
}

void turn_on_blinds(SmartObject* obj) {
    obj->state.blinds_state = 1;
    printf("%s: Blinds turned on\n", obj->name);
    print_object_state(obj);
}

void turn_off_blinds(SmartObject* obj) {
    obj->state.blinds_state = 0;
    printf("%s: Blinds turned off\n", obj->name);
    print_object_state(obj);
}
