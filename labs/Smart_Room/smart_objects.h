#include <stdbool.h>
#ifndef SMART_OBJECTS_H
#define SMART_OBJECTS_H
#define MAX_OBJECTS 100 

typedef struct {
    char name[50];
    int light_state;
    int thermostat_temperature;
    int blinds_state;
} SmartObject;

typedef void (*BlockFunction)();
extern bool last_condition_result;
extern SmartObject* objects[MAX_OBJECTS];
extern int objectCount;
typedef void (*CommandFunction)(SmartObject* obj);

// В файле smart_objects.h

typedef struct Command {
    void (*execute)(SmartObject*, int);  // Обновите указатель на функцию, чтобы он мог принимать аргумент
    SmartObject* object;                // Указатель на объект
    int arg;                            // Аргумент для команды
} Command;

typedef struct CommandList {
    Command* commands; // Массив команд
    int count; // Количество команд в списке
} CommandList;


typedef struct {
    SmartObject* object;      // Указатель на объект (если требуется)
    char* attribute;          // Название атрибута объекта (если требуется)
    int left_value;           // Левый операнд для сравнения
    int right_value;          // Правый операнд для сравнения
    char* operator;           // Оператор сравнения
} Condition;

extern SmartObject* current_object;
extern BlockFunction if_block;
extern BlockFunction else_block;

void add_command(CommandFunction func, SmartObject* obj);
void execute_commands();
void clear_commands();
SmartObject* get_object(const char* name);
void execute_if_else(Condition* condition, BlockFunction if_block, BlockFunction else_block);
void execute_block(const char* command, SmartObject* obj);
void add_command_to_list(void (*execute)(SmartObject*, int), SmartObject* obj);
void print_object_state(SmartObject* obj);
SmartObject* create_object(const char* name);
void print_attribute(int attribute_value);
void turn_on_light(SmartObject* obj);
bool evaluate_condition(const Condition* condition);
void execute_method(SmartObject* obj, const char* method_name, int argument) ;
int get_attribute_value(SmartObject* obj, const char* attribute_name);
void execute_block_list(BlockFunction* block_list);
void turn_off_light(SmartObject* obj);
void add_command_to_list_3args(void (*execute)(SmartObject*, int), SmartObject* obj, int arg);
void add_command_to_list_2args(void (*execute)(SmartObject*, int), SmartObject* obj);
void set_temperature(SmartObject* obj, int temperature);
void turn_off_blinds(SmartObject* obj);
void turn_on_blinds(SmartObject* obj);
Condition* create_condition(int left_value, char* operator, int right_value);
Condition* create_condition_attribute(SmartObject* object, const char* attribute_name, char* operator, int right_value);
Condition* create_condition_object(const char* object_name);
Condition* create_condition_time(const char* time_expression);



#endif // SMART_OBJECTS_H
