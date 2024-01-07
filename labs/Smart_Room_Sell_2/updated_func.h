#include <stdbool.h>
#ifndef SMART_OBJECTS_H
#define SMART_OBJECTS_H
#define MAX_OBJECTS 100 
#define MAX_VARIABLES 50

typedef struct {
    char name[50];
    int light; 
    int aircon; 
    int volume;
    int blinds; 
} Device;

extern Device* devices[MAX_OBJECTS];
extern int deviceCount;
typedef void (*ActionFunction)(Device* obj);


typedef struct Action {
    void (*execute)(Device*, int);  
    Device* object;               
    int arg;                            
} Action;

typedef struct ActionList {
    Action* commands; 
    int count; 
} ActionList;



extern Device* temp;


void enqueue_action(void (*execute)(Device*, int), Device* obj, int arg);
void set_audio_level(Device* obj, int value);
Device* get_device(const char* name);
void execute_block(const char* command, Device* obj);
void enqueue_action_to_list(void (*execute)(Device*, int), Device* obj, int arg);
void status_ast(Device* obj);
Device* create_device(const char* name);
void execute_actions();
void print_message(const char* message);
void turn_on_light(Device* obj);
void print_atribute_room(Device* obj);
int get_attribute_value(Device* obj, const char* attribute_name);
void turn_off_light(Device* obj);
void adjust_aircon(Device* obj, int temperature);
void turn_off_shades(Device* obj);
void turn_on_shades(Device* obj);



#endif 