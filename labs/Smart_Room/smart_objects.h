#ifndef SMART_OBJECTS_H
#define SMART_OBJECTS_H

typedef struct {
    char name[50];
    int light_state;
    int thermostat_temperature;
    int blinds_state;
} SmartObject;

typedef void (*BlockFunction)();

typedef struct {
    SmartObject* object;
    char* attribute;
    int value;
    char* operator;
    int result;
} Condition;

extern SmartObject* current_object;
extern BlockFunction if_block;
extern BlockFunction else_block;

void execute_if_else(Condition* condition, BlockFunction if_block, BlockFunction else_block);
void execute_block(const char* command, SmartObject* obj);

SmartObject* create_object(const char* name);
void print_object_state(SmartObject* obj);
void print_attribute(int attribute_value);
void turn_on_light(SmartObject* obj);
void turn_off_light(SmartObject* obj);
void set_temperature(SmartObject* obj, int temperature);
void turn_on_blinds(SmartObject* obj);
void turn_off_blinds(SmartObject* obj);

Condition* create_condition(SmartObject* object, const char* operator, int value);
Condition* create_condition_object(const char* object_name);
Condition* create_condition_time(const char* time_expression);
Condition* create_condition_attribute(SmartObject* object, const char* attribute_name);



#endif // SMART_OBJECTS_H
