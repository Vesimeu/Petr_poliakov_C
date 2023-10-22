#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Структура для представления стека
struct Stack {
    int data[100];
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
void push(struct Stack *stack, int value) {
    if (stack->top < 99) {
        stack->data[++(stack->top)] = value;
    }
}

// Функция для извлечения элемента из стека
int pop(struct Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[(stack->top)--];
    }
    return -1; // Значение -1 используется для обозначения ошибки
}

// Функция для вычисления выражения в постфиксной записи
int evaluatePostfixExpression(const char *expression) {
    struct Stack stack;
    initializeStack(&stack);

    int length = strlen(expression);

    for (int i = 0; i < length; i++) {
        if (isdigit(expression[i])) {
            // Если символ - цифра, преобразуем его в число и добавляем в стек
            push(&stack, expression[i] - '0');
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            // Если символ - оператор, извлекаем два последних числа из стека и выполняем операцию
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result = 0;

            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 != 0) {
                        result = operand1 / operand2;
                    } else {
                        printf("Error\n");
                        return -1;
                    }
                    break;
            }

            // Результат операции добавляем в стек
            push(&stack, result);
        }
    }

    // Возвращаем значение, оставшееся в стеке (результат вычисления)
    return pop(&stack);
}

int main() {
    // Открываем входной файл для чтения
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error file.\n");
        return 1;
    }

    char expression[100];
    fscanf(inputFile, "%s", expression);

    // Закрываем входной файл
    fclose(inputFile);

    // Вычисляем значение выражения
    int result = evaluatePostfixExpression(expression);

    if (result != -1) {
        printf("Meaning of the expression: %d\n", result);
    }

    return 0;
}
