; Арифметические операции в LC-3
.orig x3000 ; начальный адрес программы

; Загрузить значения в регистры
LD R1, NUMBER1 ; загрузить первое число в r1
LD R2, NUMBER2 ; загрузить второе число в r2

; Сложение
ADD R3, R1, R2 ; сложить r1 и r2, результат в r3

; Вычитание
NOT R4, R2     ; инвертировать r2
ADD R4, R4, #1 ; добавить 1 к r4 для получения -number2
ADD R4, R1, R4 ; вычесть r4 из r1, результат в r4

; Умножение (простое многократное сложение)
AND R5, R5, #0 ; обнулить r5 для результата умножения
ADD R6, R2, #0 ; скопировать number2 в r6 для счетчика
MUL_LOOP: BRZ DONE_MUL ; если r6 равен 0, завершить умножение
ADD R5, R5, R1 ; добавить number1 к результату
ADD R6, R6, #-1 ; уменьшить счетчик
BRNZP MUL_LOOP ; перейти к следующей итерации, если r6 не 0
DONE_MUL:

HALT ; завершить программу

; Данные
NUMBER1 .FILL #3 ; первое число для операций
NUMBER2 .FILL #2 ; второе число для операций

.END ; конец программы
