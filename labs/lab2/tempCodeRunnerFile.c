
                        result = operand1 / operand2;
                    } else {
                        printf("Error\n");
                        return -1;
                    }
                    break;
            }

            // Результат операции добавляем в стек
            push(&stack, result);