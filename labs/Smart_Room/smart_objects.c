// В файле smart_objects.c
#include "smart_objects.h"
#include <stdio.h>
#include "smart_objects.h"
#include <stdlib.h>
#include <string.h>

// В файле smart_objects.c
BlockFunction if_block = NULL;
BlockFunction else_block = NULL;


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
    if (obj != NULL) {
        printf("Текущее состояние команты %s : Свет=%d, Температура=%d, Зановески=%d\n", obj->name, obj->light_state, obj->thermostat_temperature, obj->blinds_state);
    } else {
        printf("Error: Object is NULL\n");
    }
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

void print_attribute(int attribute_value) {
    printf("%d\n", attribute_value);
}

void turn_on_air_conditioner(SmartObject* obj) {
    // Реализация включения кондиционера
}

void turn_off_air_conditioner(SmartObject* obj) {
    // Реализация выключения кондиционера
}

int get_attribute_value(SmartObject* obj, const char* attribute_name) {
    if (strcmp(attribute_name, "temperature") == 0) {
        return obj->thermostat_temperature;
    } else if (strcmp(attribute_name, "light_state") == 0) {
        return obj->light_state;
    }
    // Добавить обработку других атрибутов
}
// ...

void execute_method(SmartObject* obj, const char* method_name, int argument) {
    if (strcmp(method_name, "set_temperature") == 0) {
        set_temperature(obj, argument);
    } else if (strcmp(method_name, "turn_on_air_conditioner") == 0) {
        turn_on_air_conditioner(obj);
    } else if (strcmp(method_name, "turn_off_air_conditioner") == 0) {
        turn_off_air_conditioner(obj);
    } else {
        // Добавьте обработку других методов, если необходимо
        fprintf(stderr, "Error: Unknown method '%s'\n", method_name);
        exit(EXIT_FAILURE);
    }
}


//БЛОКИ
void execute_if_else(Condition* condition, BlockFunction if_block, BlockFunction else_block) {
    if (condition->result) {
        if_block();
    } else {
        else_block();
    }
}




Condition* create_condition(SmartObject* object, const char* operator, int value) {
    // Реализуйте создание условия
}

Condition* create_condition_object(const char* object_name) {
    // Реализуйте создание условия для объекта
}

Condition* create_condition_time(const char* time_expression) {
    // Реализуйте создание условия для времени
}

Condition* create_condition_attribute(SmartObject* object, const char* attribute_name) {
    Condition* condition = (Condition*)malloc(sizeof(Condition));
    if (condition == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    condition->object = object;
    condition->attribute = attribute_name;
    condition->value = 0; // Установим значение по умолчанию
    condition->operator = "="; // Установим оператор по умолчанию
    condition->result = 0;

    return condition;
}

void block(const char* command, SmartObject* obj, int arg) {
    if (strcmp(command, "turn_on_light") == 0) {
        turn_on_light(obj);
    } else if (strcmp(command, "turn_off_light") == 0) {
        turn_off_light(obj);
    } else if (strcmp(command, "turn_on_blinds") == 0) {
        turn_on_blinds(obj);
    } else if (strcmp(command, "turn_off_blinds") == 0) {
        turn_off_blinds(obj);
    } else if (strcmp(command, "status") == 0) {
        print_object_state(obj);
    } else if (strcmp(command, "set_temperature") == 0) {
        set_temperature(obj, arg);
    }
}


void execute_block(const char* command, SmartObject* obj) {
    block(command, obj, 0);
}
