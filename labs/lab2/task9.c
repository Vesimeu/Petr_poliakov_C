#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//git : https://github.com/Vesimeu


typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;


void initialize(Stack* stack) {
    stack->top = NULL;
}


void push(Stack* stack, char value) {
    StackNode* newNode = (StackNode*)
    malloc(sizeof(StackNode));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(Stack* stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Ошибка: стек пуст\n");
        exit(1);
    }
    StackNode* topNode = stack->top;
    char value = topNode->data;
    stack->top = topNode->next;
    free(topNode);
    return value;
}

// Проверка, является ли символ оператором
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;  // Для скобок
}

// Преобразование инфиксного выражения в постфиксное
void infixToPostfix(const char* infix, char* postfix) {
    Stack operatorStack;
    initialize(&operatorStack);

    int infixLength = strlen(infix);
    int postfixIndex = 0;

    for (int i = 0; i < infixLength; i++) {
        char currentChar = infix[i];

        if (currentChar == ' ') {
            continue;  // Пропускаем пробелы
        } else if (isdigit(currentChar) || isalpha(currentChar)) {
            // Если символ - операнд, добавляем его в постфиксную строку
            while (isdigit(infix[i]) || isalpha(infix[i])) {
                postfix[postfixIndex++] = infix[i++];
            }
            postfix[postfixIndex++] = ' ';  // Разделитель между операндами
            i--;  // Чтобы не пропустить следующий символ
        } else if (currentChar == '(') {
            // Если символ - открывающая скобка, помещаем ее в стек
            push(&operatorStack, currentChar);
        } else if (currentChar == ')') {
            // Если символ - закрывающая скобка, извлекаем операторы из стека
            // и добавляем их в постфиксную строку до открывающей скобки
            while (operatorStack.top != NULL && operatorStack.top->data != '(') {
                postfix[postfixIndex++] = pop(&operatorStack);
                postfix[postfixIndex++] = ' ';
            }
            if (operatorStack.top == NULL) {
                fprintf(stderr, "Ошибка: несбалансированные скобки\n");
                exit(1);
            }
            pop(&operatorStack);  // Извлекаем открывающую скобку
        } else if (isOperator(currentChar)) {       
            // Если символ - оператор, извлекаем операторы из стека с
            // более высоким или равным приоритетом и добавляем их в постфиксную строку
            while (operatorStack.top != NULL && operatorStack.top->data != '(' &&
                   getPrecedence(currentChar) <= getPrecedence(operatorStack.top->data)) {
                postfix[postfixIndex++] = pop(&operatorStack);
                postfix[postfixIndex++] = ' ';
            }
            push(&operatorStack, currentChar);
        } else {
            fprintf(stderr, "Ошибка: недопустимый символ в выражении\n");
            exit(1);
        }
    }

    // Извлекаем оставшиеся операторы из стека и добавляем их в постфиксную строку
    while (operatorStack.top != NULL) {
        if (operatorStack.top->data == '(') {
            fprintf(stderr, "Ошибка: несбалансированные скобки\n");
            exit(1);
        }
        postfix[postfixIndex++] = pop(&operatorStack);
        postfix[postfixIndex++] = ' ';
    }

    postfix[postfixIndex] = '\0';  // нуль терминатор 
}

int main() {

    while (1) {
        char infixExpression[100];
        char postfixExpression[100];
        printf("Введите арифметическое выражение в инфиксной нотации (или 'exit' для завершения): ");
        scanf("%[^\n]s", infixExpression); 
        getchar(); //need using gets or fgets

        if (strcmp(infixExpression, "exit") == 0) {
            printf("Программа завершена.\n");
            break;
        }

        infixToPostfix(infixExpression, postfixExpression);

        printf("Постфиксная нотация: %s\n", postfixExpression);
    }

    return 0;
}

