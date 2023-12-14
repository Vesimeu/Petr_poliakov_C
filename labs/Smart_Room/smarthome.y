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

void yyerror(const char* s);

%}

%lex-param { YYSTYPE yylval; }

// struct SmartObject;




%union {
    int intval;
    char* strval;
    SmartObject* objectval;
    ObjectState stateval;  // Добавляем новый тип для хранения состояния объекта
}


%token <intval> INTEGER
%token <strval> STRING
%token <objectval> CREATE_OBJECT IF ELSE TURN_ON TURN_OFF SET_TEMPERATURE SET_VOLUME GRANT_ACCESS CURRENT_TIME SUNRISE_TIME SUNSET_TIME 
%token ID COLON SEMICOLON LPAREN RPAREN LBRACE RBRACE EQUAL GREATER LESS COMMA DOT
%token <strval> TURN_ON_LIGHT TURN_OFF_LIGHT TURN_ON_BLINDS TURN_OFF_BLINDS STATUS

%type <intval> create_object_statement
%type <intval> expression
%type <strval> object attribute_name
%type <objectval> command_result  // Новый тип для хранения результата выполнения команды
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
         | status_command SEMICOLON       // Добавляем status
         ;
status_command: object DOT STATUS LPAREN RPAREN { print_object_state($1); }  // Добавляем команду для проверки статуса
             ;

light_command: object DOT TURN_ON_LIGHT LPAREN RPAREN { turn_on_light($1); }  // Добавляем команду для включения света
            | object DOT TURN_OFF_LIGHT LPAREN RPAREN { turn_off_light($1); }  // Добавляем команду для выключения света
            ;

blinds_command: object DOT TURN_ON_BLINDS LPAREN RPAREN { turn_on_blinds($1); }  // Добавляем команду для включения жалюзи
             | object DOT TURN_OFF_BLINDS LPAREN RPAREN { turn_off_blinds($1); }  // Добавляем команду для выключения жалюзи
             ;
             

create_object_statement: CREATE_OBJECT STRING { $$ = create_object($2); }
                     ;

if_else_statement: IF LPAREN expression RPAREN LBRACE statement_list RBRACE
                 | IF LPAREN expression RPAREN LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE
                 ;

expression_statement: object DOT attribute_name LPAREN argument_list RPAREN SEMICOLON
    ;



argument_list: expression
            | argument_list COMMA expression
            ;

expression: INTEGER
          | ID
          | time_expression
          | object DOT attribute_name LPAREN argument_list RPAREN { $$ = $1; }   // Учтем вызов метода в контексте объекта
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

command_result: INTEGER  { $$ = $1; }  // Просто передаем значение INTEGER
             | STRING   { $$ = strdup($1); }  // Для STRING делаем strdup, чтобы создать копию строки
             ;

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

    yyparse();

    fclose(input_file);

    return 0;
}
