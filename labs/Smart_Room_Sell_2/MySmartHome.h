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
} Home;

extern Home* devices[MAX_OBJECTS];
extern int deviceCount;
typedef void (*ActionFunction)(Home* obj);


typedef struct Action {
    void (*execute)(Home*, int);  
    Home* object;               
    int arg;                            
} Action;


extern Home* temp;


void add_action_to_queue(void (*execute)(Home*, int), Home* obj, int arg); 
void set_audio(Home* obj, int value);
Home* retrieve_device(const char* name); 
void perform_all_actions(); 
Home* create_device(const char* name);
void display_system_message(const char* message); 
void activited_light(Home* obj); 
void information(Home* obj); 
int get_attribute_value(Home* obj, const char* attribute_name);
void deactivited_light(Home* obj); 
void aircon(Home* obj, int temperature); 
void shades_off(Home* obj); 
void shades_on(Home* obj); 



#endif 