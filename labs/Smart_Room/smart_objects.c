// В файле smart_objects.c
#include "smart_objects.h"
#include <stdio.h>
#include "smart_objects.h"
#include <stdlib.h>
#include <string.h>

// В файле smart_objects.c
BlockFunction if_block = NULL;
BlockFunction else_block = NULL;
bool last_condition_result = false;

// В файле smart_objects.c

#define MAX_COMMANDS 100  // Примерное ограничение на количество команд
Command commandList[MAX_COMMANDS];
int commandCount = 0;
SmartObject* objects[MAX_OBJECTS];
int objectCount = 0;

SmartObject* get_object(const char* name) {
    // Поиск существующего объекта
    for (int i = 0; i < objectCount; i++) {
        if (strcmp(objects[i]->name, name) == 0) {
            return objects[i];
        }
    }

    // Если объект не найден, создать новый
    if (objectCount < MAX_OBJECTS) {
        SmartObject* newObj = create_object(name);
        objects[objectCount++] = newObj;
        return newObj;
    }

    // Если достигнут лимит объектов
    fprintf(stderr, "Превышено максимальное количество объектов\n");
    return NULL;
}

// Функция для добавления команды с двумя аргументами
void add_command_to_list(void (*execute)(SmartObject*, int), SmartObject* obj) {
    if (commandCount >= MAX_COMMANDS) {
        fprintf(stderr, "Превышено максимальное количество команд\n");
        return;
    }
    commandList[commandCount].execute = execute;
    commandList[commandCount].object = obj;
    commandList[commandCount].arg = 0;  // Установите аргумент в 0
    commandCount++;
}

// Функция для добавления команды с тремя аргументами
void add_command_to_list_3args(void (*execute)(SmartObject*, int), SmartObject* obj, int arg) {
    if (commandCount >= MAX_COMMANDS) {
        fprintf(stderr, "Превышено максимальное количество команд\n");
        return;
    }
    commandList[commandCount].execute = execute;
    commandList[commandCount].object = obj;
    commandList[commandCount].arg = arg;  // Установите аргумент в переданное значение
    commandCount++;
}

void execute_command_list() {
    for (int i = 0; i < commandCount; i++) {
        Command cmd = commandList[i];
        cmd.execute(cmd.object, cmd.arg); // Передаем аргумент в выполнение команды
    }
    commandCount = 0;  // Очищаем список после выполнения
}



SmartObject* create_object(const char* name) {
    // Проверка, существует ли уже объект с таким именем
    for (int i = 0; i < objectCount; i++) {
        if (strcmp(objects[i]->name, name) == 0) {
            return objects[i]; // Возвращаем существующий объект
        }
    }

    // Создаем новый объект, если он не найден
    SmartObject* obj = (SmartObject*)malloc(sizeof(SmartObject));
    if (!obj) {
        perror("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }
    strncpy(obj->name, name, sizeof(obj->name) - 1);
    obj->name[sizeof(obj->name) - 1] = '\0';
    obj->light_state = 0;
    obj->thermostat_temperature = 0;
    obj->blinds_state = 0;
    if (objectCount < MAX_OBJECTS) {
        objects[objectCount++] = obj;
    } else {
        fprintf(stderr, "Превышено максимальное количество объектов\n");
        free(obj);
        return NULL;
    }

    printf("Комната %s успешно создана с атрибутами:\n", obj->name);
    printf("Состояние света: %d\n", obj->light_state);
    printf("Температура: %d градусов\n", obj->thermostat_temperature);
    printf("Состояние зановесок: %d\n", obj->blinds_state);
    return obj;
}

void print_object_state(SmartObject* obj) {
    if (obj != NULL) {
        printf("Текущее состояние комнаты %s : Свет=%d, Температура=%d, Зановески=%d\n", obj->name, obj->light_state, obj->thermostat_temperature, obj->blinds_state);
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
    if (strcmp(method_name, "turn_on_light") == 0) {
        turn_on_light(obj); // Передаем 0 в качестве аргумента
    } else if (strcmp(method_name, "turn_off_light") == 0) {
        turn_off_light(obj); // Передаем 0 в качестве аргумента
    } else if (strcmp(method_name, "turn_on_blinds") == 0) {
        turn_on_blinds(obj); // Передаем 0 в качестве аргумента
    } else if (strcmp(method_name, "turn_off_blinds") == 0) {
        turn_off_blinds(obj); // Передаем 0 в качестве аргумента
    } else if (strcmp(method_name, "status") == 0) {
        print_object_state(obj);
    } else if (strcmp(method_name, "set_temperature") == 0) {
        set_temperature(obj, argument);
    } else {
        fprintf(stderr, "Error: Unknown method '%s'\n", method_name);
        exit(EXIT_FAILURE);
    }
}



//БЛОКИ
void execute_if_else(Condition* condition, BlockFunction if_block, BlockFunction else_block) {
   if (if_block != NULL) {
    if_block();
} else {
    fprintf(stderr, "Error: if_block is NULL\n");
    exit(EXIT_FAILURE);
}

if (else_block != NULL) {
    else_block();
} else {
    fprintf(stderr, "Error: else_block is NULL\n");
    exit(EXIT_FAILURE);
}
}


bool evaluate_condition(const Condition* condition) {
    if (condition != NULL) {
        int left_value = condition->left_value;
        int right_value = condition->right_value;
        char* operator = condition->operator;
        if (operator == NULL) {
            printf("Оператор не задан\n");
            return false;
        }

        printf("Вычисление условия: %d %s %d\n", left_value, operator, right_value);

        if (strcmp(operator, ">") == 0) {
            return left_value > right_value;
        } else if (strcmp(operator, "<") == 0) {
            return left_value < right_value;
        } else if (strcmp(operator, "==") == 0) {
            return left_value == right_value;
        }
    }
    return false; // В случае ошибки или некорректного условия
}


void free_condition(Condition* condition) {
    free(condition->attribute);
    free(condition->operator);
    free(condition);
}

//Он в неё заходит
Condition* create_condition(int left_value, char* operator, int right_value) {
    Condition* condition = (Condition*)malloc(sizeof(Condition));
    if (condition == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    condition->left_value = left_value;
    condition->right_value = right_value;
    condition->operator = strdup(operator);  // Используйте strdup для копирования оператора
    return condition;
}



//будет выполнять список операторов
void execute_block_list(BlockFunction* block_list) {
    if (!block_list) {
        return;
    }

    while (*block_list != NULL) {
        (*block_list)();
        block_list++;
    }
}



Condition* create_condition_object(const char* object_name) {
    // Реализуйте создание условия для объекта
}

Condition* create_condition_time(const char* time_expression) {
    // Реализуйте создание условия для времени
}

Condition* create_condition_attribute(SmartObject* object, const char* attribute_name, char* operator, int right_value) {
    Condition* condition = (Condition*)malloc(sizeof(Condition));
    if (condition == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    condition->object = object;
    condition->attribute = strdup(attribute_name);  // Копируем имя атрибута
    condition->operator = strdup(operator);         // Копируем оператор
    condition->right_value = right_value;           // Устанавливаем правый операнд
    // Левый операнд не используется в этой функции

    return condition;
}



// void block(const char* command, SmartObject* obj, int arg) {
//     if (strcmp(command, "turn_on_light") == 0) {
//         turn_on_light(obj);
//     } else if (strcmp(command, "turn_off_light") == 0) {
//         turn_off_light(obj);
//     } else if (strcmp(command, "turn_on_blinds") == 0) {
//         turn_on_blinds(obj);
//     } else if (strcmp(command, "turn_off_blinds") == 0) {
//         turn_off_blinds(obj);
//     } else if (strcmp(command, "status") == 0) {
//         print_object_state(obj);
//     } else if (strcmp(command, "set_temperature") == 0) {
//         set_temperature(obj, arg);
//     }
// }

