%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);

int lbl_count = 0;

// Функция для генерации новой метки
int new_lbl() {
    return lbl_count++;
}

// Функция для вывода инструкций LC-3
void emit(const char *instr, const char *operands) {
    printf("    %s %s\n", instr, operands);
}

// Функция для вывода меток LC-3
void emit_lbl(int lbl) {
    printf("LABEL%d\n", lbl);
}

%}

%union {
    int num;
    char *str;
}

%token <str> IDENTIFIER
%token <num> NUMBER
%token IF ELSE WHILE

%type <str> expression
%type <num> condition
%type <num> statement
%type <num> program

%%

program
    : /* empty */
    | program statement
    ;

statement
    : IF '(' condition ')' statement ELSE statement
        {
            int lbl1 = new_lbl();
            int lbl2 = new_lbl();
            emit("BRn", "LABEL%d", lbl1);
            // Recursive descent into the if statement
            emit("BR", "LABEL%d", lbl2);
            emit_lbl(lbl1);
            // Recursive descent into the else statement
            emit_lbl(lbl2);
        }
    | WHILE '(' condition ')' statement
        {
            int lbl1 = new_lbl();
            int lbl2 = new_lbl();
            emit_lbl(lbl1);
            emit("BRn", "LABEL%d", lbl2);
            // Recursive descent into the while statement
            emit("BR", "LABEL%d", lbl1);
            emit_lbl(lbl2);
        }
    ;

condition
    : expression '>' expression
        {
            emit("CMP", "R0, R1"); // Пример сравнения двух значений
            // В реальной реализации вы бы загрузили значения в регистры
        }
    ;

expression
    : NUMBER
        {
            // Загрузка значения в регистр предполагается
        }
    | IDENTIFIER
        {
            // Для идентификаторов необходимо реализовать таблицу символов
        }
    ;

%%

int main(int argc, char **argv) {
    printf(".ORIG x3000\n");
    yyparse();
    printf(".END\n");
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
