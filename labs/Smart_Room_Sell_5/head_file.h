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
    int safe; //system 
} Room;

extern Room* devices[MAX_OBJECTS];
extern int deviceCount;
typedef void (*ActionFunction)(Room* obj);


typedef struct Command {
    void (*execute)(Room*, int);  
    Room* object;               
    int arg;                            
} Command;

typedef struct ActionList {
    Command* commands; 
    int count; 
} ActionList;



extern Room* temp;


void enqueue_action(void (*execute)(Room*, int), Room* obj, int arg);
void set_audio_level(Room* obj, int value);
void execute_block(const char* command, Room* obj);
void enqueue_action_to_list(void (*execute)(Room*, int), Room* obj, int arg);
void status_ast(Room* obj);
Room* create_device(const char* name);
void execute_actions();
void set_light_mode(Room* obj, int mode) ;//status light
void print_message(const char* message);
void print_information_room(Room* obj);
void set_safe_mode(Room* obj, int mode); 
int get_attribute_value(Room* obj, const char* attribute_name);
void set_temperature(Room* obj, int aircon);
void set_blinds_mode(Room* obj, int mode) ; //status blinds



#endif 