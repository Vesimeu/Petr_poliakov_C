%{
#include <stdio.h>
#include <stdlib.h>
#include "smart_objects.h"
#include <string.h>
#include "smarthome.tab.h"

// #define YYSTYPE_IS_DECLARED 1
// #define YYSTYPE_IS_TRIVIAL 1

extern FILE* yyin;
extern int yylex();
extern char* yytext;


struct SmartObject;
SmartObject* current_object = NULL;  // Добавим переменную для хранения объекта

void yyerror(const char* s);

%}

%lex-param { YYSTYPE yylval; }

// struct SmartObject;




%union {
    int intval;
    char* strval;
    SmartObject* objectval;
}


%token <intval> INTEGER 
%token <strval> STRING
%token <objectval> CREATE_OBJECT IF ELSE TURN_ON TURN_OFF SET_VOLUME GRANT_ACCESS CURRENT_TIME SUNRISE_TIME SUNSET_TIME 
%token ID COLON SEMICOLON LPAREN RPAREN LBRACE RBRACE EQUAL GREATER LESS COMMA DOT SET_TEMPERATURE 
%token <strval> TURN_ON_LIGHT TURN_OFF_LIGHT TURN_ON_BLINDS TURN_OFF_BLINDS STATUS

%type <intval> expression SET_TEMPERATURE 
%type <strval> object attribute_name
%type <objectval> create_object_statement light_command blinds_command status_command


%%

program: statement_list
        ;

statement_list: statement
              | statement_list statement
              ;

statement: create_object_statement SEMICOLON
         | if_else_statement SEMICOLON
         | expression_statement SEMICOLON
         | light_command SEMICOLON         // Добавляем новую команду для управления светом
         | blinds_command SEMICOLON  
         | status_command SEMICOLON 
         | set_temperature_statement SEMICOLON      
         ;
// Вместо того чтобы использовать $1 в качестве значения атрибута объекта, создайте новый объект с использованием текущего объекта, а затем обновите текущий объект.
create_object_statement: CREATE_OBJECT STRING { $$ = create_object($2); current_object = $$; }
                     ;

// Обновим команды для управления светом
light_command: object DOT TURN_ON_LIGHT LPAREN RPAREN { turn_on_light(current_object); }
            | object DOT TURN_OFF_LIGHT LPAREN RPAREN { turn_off_light(current_object); }
            ;

// Обновим команды для управления жалюзи
blinds_command: object DOT TURN_ON_BLINDS LPAREN RPAREN { turn_on_blinds(current_object); }
             | object DOT TURN_OFF_BLINDS LPAREN RPAREN { turn_off_blinds(current_object); }
             ;
set_temperature_statement: object DOT SET_TEMPERATURE LPAREN INTEGER RPAREN { set_temperature(current_object, $5); };

// Обновим команду для вывода статуса
status_command: object DOT STATUS LPAREN RPAREN { print_object_state(current_object); }
             ;

// Обновим команду для вызова метода объекта
expression_statement: object DOT attribute_name LPAREN argument_list RPAREN SEMICOLON { turn_on_light(current_object); }
                  ;

if_else_statement: IF LPAREN expression RPAREN LBRACE statement_list RBRACE
                 | IF LPAREN expression RPAREN LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE
                 ;


argument_list: expression
            | argument_list COMMA expression
            ;

expression: INTEGER
          | ID
          | time_expression
          | object DOT attribute_name LPAREN argument_list RPAREN { $$ = (SmartObject*)$1; }
          | expression EQUAL expression
          | expression GREATER expression
          | expression LESS expression
          ;

time_expression: CURRENT_TIME
              | SUNRISE_TIME
              | SUNSET_TIME
              ;

object: STRING { $$ = $1; }
      ;
      
attribute_name: ID
              ;

// command_result: INTEGER  { $$ = $1; }
//              | STRING   { $$ = strdup($1); }
//              | objectval { $$ = $1; }
//              ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s near '%s'\n", s, yytext);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    yyin = input_file;

    SmartObject* obj = NULL;  // Добавим переменную для хранения объекта
    // yyparse(&obj);  // Передадим указатель на объект в yyparse

    yyparse();

    fclose(input_file);

    return 0;
}
