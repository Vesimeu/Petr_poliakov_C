#include <stdbool.h>
#ifndef SMART_OBJECTS_H
#define SMART_OBJECTS_H
#define MAX_OBJECTS 100 
#define MAX_VARIABLES 50

typedef struct {
    char name[50];
    int light_state;
    int thermostat_temperature;
    int set_volume;
    int blinds_state;
} AST;

extern AST* objects[MAX_OBJECTS];
extern int objectCount;
typedef void (*CommandFunction)(AST* obj);


typedef struct Command {
    void (*execute)(AST*, int);  
    AST* object;               
    int arg;                            
} Command;

typedef struct CommandList {
    Command* commands; 
    int count; 
} CommandList;



extern AST* temp;


void add_command(void (*execute)(AST*, int), AST* obj, int arg);
void set_volume(AST* obj, int value);
AST* get_obj(const char* name);
void execute_block(const char* command, AST* obj);
void add_command_to_list(void (*execute)(AST*, int), AST* obj, int arg);
void status_ast(AST* obj);
AST* add_obj(const char* name);
void print(const char* message);
void turn_on_light(AST* obj);
void print_atribute_room(AST* obj);
int get_attribute_value(AST* obj, const char* attribute_name);
void turn_off_light(AST* obj);
void conditioner(AST* obj, int temperature);
void turn_off_blinds(AST* obj);
void turn_on_blinds(AST* obj);



#endif 