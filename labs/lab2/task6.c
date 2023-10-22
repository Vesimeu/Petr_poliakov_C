#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

// Структура для представления стека
struct Stack {
    int data[MAX_STACK_SIZE];
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

// Функция для проверки, полон ли стек
int isFull(struct Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

// Функция для добавления элемента в стек
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("The stack is full. The element cannot be added. = (\n");
    } else {
        stack->data[++(stack->top)] = value;
        printf("add element: %d\n", value);
    }
}

// Функция для извлечения элемента из стека
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("The stack is empty. The element cannot be extracted. = (\n");
        return -1; // Значение -1 используется для обозначения ошибки
    } else {
        int value = stack->data[(stack->top)--];
        printf("The element is extracted: %d\n", value);
        return value;
    }
}

// Функция для просмотра верхнего элемента стека без извлечения
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("The stack is empty. The top element cannot be viewed.\n");
        return -1; // Значение -1 используется для обозначения ошибки
    } else {
        return stack->data[stack->top];
    }
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    // Добавляем элементы в стек
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 228);

    // Извлекаем элементы из стека
    pop(&stack);
    pop(&stack);
    pop(&stack);
    printf("Index the last arg  = %d \n" , (stack.top));
    pop(&stack);
    pop(&stack); // Попытка извлечения из пустого стека
    

    // Пробуем просмотреть верхний элемент
    push(&stack, 4);
    int topValue = peek(&stack);
    printf("The top element of the stack: %d\n", topValue);

    return 0;
}
