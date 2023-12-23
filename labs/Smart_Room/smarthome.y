%{
#include <stdio.h>
#include <stdlib.h>
#include "smart_objects.h"
#include <string.h>
#include "smarthome.tab.h"

// #define YYSTYPE_IS_DECLARED 1
// #define YYSTYPE_IS_TRIVIAL 1
bool in_false_if_block = false;
extern FILE* yyin;
extern int yylex();
extern char* yytext;

struct SmartObject;
SmartObject* current_object = NULL;  // Добавим переменную для хранения объекта
CommandList* current_command_list = NULL; // Добавим переменную для хранения текущего списка команд
void yyerror(const char* s);

%}

%lex-param { YYSTYPE yylval; }

// struct SmartObject;




%union {
    int intval;
    char* strval;
    SmartObject* objectval;
    Condition* conditionval; // Добавьте эту строку
    BlockFunction* blocklistval;
    
}


%token <intval> INTEGER 
%token <objectval> CREATE_OBJECT IF ELSE TURN_ON TURN_OFF SET_VOLUME GRANT_ACCESS CURRENT_TIME SUNRISE_TIME SUNSET_TIME 
%token COLON SEMICOLON LPAREN RPAREN LBRACE RBRACE COMMA DOT SET_TEMPERATURE PRINT
%token <strval> TURN_ON_LIGHT TURN_OFF_LIGHT TURN_ON_BLINDS TURN_OFF_BLINDS STATUS GREATER LESS EQUAL STRING ID


%type <intval> expression SET_TEMPERATURE  attribute argument_list
%type <strval> attribute_name relation_operator
%type <objectval> create_object_statement light_command blinds_command status_command object expression_statement light_command_defolt
%type <conditionval> condition
%type <blocklistval> statement_list
%%

program: statement_list
        ;

statement_list: statement
              | statement_list statement
              ;


statement: create_object_statement SEMICOLON 
         | expression_statement SEMICOLON
         | light_command SEMICOLON      // Добавляем новую команду для управления светом
         | blinds_command SEMICOLON  
         | status_command SEMICOLON 
         | set_temperature_statement SEMICOLON    
         | print_statement SEMICOLON 
         | if_else_statement 
         ;
// Вместо того чтобы использовать $1 в качестве значения атрибута объекта, создайте новый объект с использованием текущего объекта, а затем обновите текущий объект.
create_object_statement: CREATE_OBJECT STRING { $$ = create_object($2); current_object = $$; }
;

// Обновим команды для управления светом
light_command_defolt: object DOT TURN_ON_LIGHT LPAREN RPAREN { turn_on_light(current_object); }
            | object DOT TURN_OFF_LIGHT LPAREN RPAREN { turn_off_light(current_object); }
            ;  
            
light_command: object DOT TURN_ON_LIGHT LPAREN RPAREN { 
                add_command_to_list(turn_on_light, get_object($1), 0); 
             }
             | object DOT TURN_OFF_LIGHT LPAREN RPAREN { 
                add_command_to_list(turn_off_light, get_object($1), 0); 
             }
             // И так далее для других команд
     

blinds_command: object DOT TURN_ON_BLINDS LPAREN RPAREN { add_command_to_list(turn_on_blinds, get_object($1), 0); }
             | object DOT TURN_OFF_BLINDS LPAREN RPAREN { add_command_to_list(turn_off_blinds, get_object($1), 0); }
             ;


set_temperature_statement: object DOT SET_TEMPERATURE LPAREN INTEGER RPAREN { add_command_to_list(set_temperature, get_object($1), $5) ;};

// Обновим команду для вывода статуса
status_command_def: object DOT STATUS LPAREN RPAREN { add_command_to_list(print_object_state, current_object); }
             ;
status_command: object DOT STATUS LPAREN RPAREN {print_object_state(current_object) ; };

expression_statement: object DOT attribute_name LPAREN argument_list RPAREN SEMICOLON
{
    execute_method($1, $3, $5); // Выполняем метод объекта
}


print_statement: PRINT LPAREN attribute RPAREN { print_attribute($3); }
;

condition: LPAREN expression relation_operator expression RPAREN
  {
    $$ = create_condition($2, $3, $4);
  }
;



relation_operator: GREATER
                | LESS 
                | EQUAL 
                ;

if_else_statement: 
    IF condition LBRACE
    {
        in_false_if_block = !evaluate_condition($2);
    }
    statement_list 
    RBRACE
    {
        in_false_if_block = false;
    }
    | IF condition LBRACE 
    {
        in_false_if_block = !evaluate_condition($2);
    }
    statement_list 
    RBRACE ELSE LBRACE
    {
        in_false_if_block = true;
    }
    statement_list
    RBRACE
    {
        in_false_if_block = false;
    }
    ;



argument_list: expression
            | argument_list COMMA expression
            ;

expression: INTEGER
          | ID
          | time_expression
          | object DOT attribute_name LPAREN argument_list RPAREN { $$ = (SmartObject*)$1; }
          | attribute
          | condition
          ;

time_expression: CURRENT_TIME
              | SUNRISE_TIME
              | SUNSET_TIME
              ;

object: STRING { $$ = get_object($1); }
      ;
      
attribute_name: ID
              ;

attribute: object DOT ID { $$ = get_attribute_value(current_object, $3); }
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
    execute_command_list();
    fclose(input_file);



    return 0;
}