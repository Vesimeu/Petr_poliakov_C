#ifndef SMART_OBJECTS_H
#define SMART_OBJECTS_H

// Структура для представления состояния объекта
typedef struct {
    int light_state;
    int thermostat_temperature;
    int blinds_state;
} ObjectState;

// Структура для представления объекта
typedef struct {
    char name[50];
    ObjectState state;
} SmartObject;

// Функции для управления объектами
SmartObject* create_object(const char* name);
void turn_on_light(SmartObject* obj);
void turn_off_light(SmartObject* obj);
void set_temperature(SmartObject* obj, int temperature);
void turn_on_blinds(SmartObject* obj);
void turn_off_blinds(SmartObject* obj);

#endif // SMART_OBJECTS_H
