#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Структура для представления стека
struct Stack {
    char data[100];
    int top;
};

// Функция для инициализации стека
void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

// Функция для проверки, пуст ли стек
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Функция для добавления элемента в стек
void push(struct Stack *stack, char value) {
    if (stack->top < 99) {
        stack->data[++(stack->top)] = value;
    }
}

// Функция для извлечения элемента из стека
char pop(struct Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[(stack->top)--];
    }
    return '\0'; // Возвращаем нуль-терминатор для обозначения ошибки
}

// Функция для получения приоритета оператора
int getPriority(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Функция для преобразования инфиксной записи в постфиксную запись
void infixToPostfix(const char *infixExpression, char *postfixExpression) {
    struct Stack stack;
    initializeStack(&stack);

    int length = strlen(infixExpression);
    int outputIndex = 0;

    for (int i = 0; i < length; i++) {
        char token = infixExpression[i];

        if (isdigit(token)) {
            // Если токен - цифра, добавляем его в выходную строку
            postfixExpression[outputIndex++] = token;
            postfixExpression[outputIndex++] = ' '; // Добавляем пробел после цифры
        } else if (token == '(') {
            // Если токен - открывающая скобка, добавляем ее в стек
            push(&stack, token);
        } else if (token == ')') {
            // Если токен - закрывающая скобка, извлекаем операторы из стека и добавляем в выходную строку до открывающей скобки
            while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
                postfixExpression[outputIndex++] = pop(&stack);
                postfixExpression[outputIndex++] = ' '; // Добавляем пробел после оператора
            }
            // Удаляем открывающую скобку из стека
            pop(&stack);
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            // Если токен - оператор, обрабатываем его приоритет
            while (!isEmpty(&stack) && getPriority(token) <= getPriority(stack.data[stack.top])) {
                postfixExpression[outputIndex++] = pop(&stack);
                postfixExpression[outputIndex++] = ' '; // Добавляем пробел после оператора
            }
            // Добавляем оператор в стек
            push(&stack, token);
        }
    }

    // Извлекаем оставшиеся операторы из стека и добавляем в выходную строку
    while (!isEmpty(&stack)) {
        postfixExpression[outputIndex++] = pop(&stack);
        postfixExpression[outputIndex++] = ' '; // Добавляем пробел после оператора
    }

    // Завершаем выходную строку нуль-терминатором
    postfixExpression[outputIndex] = '\0';
}

int main() {
    char infixExpression[100];
    char postfixExpression[100];

    // Примеры инфиксных выражений
    strcpy(infixExpression, "3 + 4");
    infixToPostfix(infixExpression, postfixExpression);
    printf("Infix: %s, Postfix: %s\n", infixExpression, postfixExpression);

    strcpy(infixExpression, "(5 + 2) * 4");
    infixToPostfix(infixExpression, postfixExpression);
    printf("Infix: %s, Postfix: %s\n", infixExpression, postfixExpression);

    strcpy(infixExpression, "6 / (2 + 3)");
    infixToPostfix(infixExpression, postfixExpression);
    printf("Infix: %s, Postfix: %s\n", infixExpression, postfixExpression);

    return 0;
}
