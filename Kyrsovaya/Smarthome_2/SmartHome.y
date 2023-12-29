%{
#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <string.h>
#include "SmartHome.tab.h"

// #define YYSTYPE_IS_DECLARED 1
// #define YYSTYPE_IS_TRIVIAL 1
extern FILE* yyin;
extern int yylex();
extern char* yytext;

struct AST;
AST* temp = NULL;  // Добавим переменную для хранения объекта
CommandList* current_command_list = NULL; // Добавим переменную для хранения текущего списка команд
void yyerror(const char* s);

%}

%lex-param { YYSTYPE yylval; }

// struct AST;




%union {
    int intval;
    char* strval;
    AST* objectval;
}


%token <intval> INTEGER 
%token <objectval> ADD_OBJ TURN_ON TURN_OFF 
%token COLON LPAREN RPAREN LBRACE RBRACE COMMA HAVE PRINT END
%token <strval> LIGHT_ON LIGHT_OFF BLINDS_ON BLINDS_OFF INFO GREATER LESS EQUAL STRING ID SET_VOLUME SET_CONDITIONER
%type <strval> message_name 
%type <objectval> add_obj_statement light_command blinds_command info_command object 
%%


program: statement_list
        ;

statement_list: statement
              | statement_list statement
              ;


statement: add_obj_statement END
         | light_command END     // Добавляем новую команду для управления светом
         | blinds_command END 
         | info_command END
         | set_conditioner END   
         | set_volume_statement END
         | print_statement END
         ;

add_obj_statement: ADD_OBJ STRING { $$ = add_obj($2); temp = $$; }
;

        
light_command: object HAVE LIGHT_ON LPAREN RPAREN { 
                add_command(turn_on_light, get_obj($1), 0); 
             }
             | object HAVE LIGHT_OFF LPAREN RPAREN { 
                add_command(turn_off_light, get_obj($1), 0); 
             }
             // И так далее для других команд
     

blinds_command: object HAVE BLINDS_ON LPAREN RPAREN { add_command(turn_on_blinds, get_obj($1), 0); }
             | object HAVE BLINDS_OFF LPAREN RPAREN { add_command(turn_off_blinds, get_obj($1), 0); }
             ;



set_conditioner: object HAVE SET_CONDITIONER LPAREN INTEGER RPAREN { add_command(conditioner, temp, $5) ;};


set_volume_statement: object HAVE SET_VOLUME LPAREN INTEGER RPAREN { add_command(set_volume, temp, $5) ;};
             
             
info_command: object HAVE INFO {add_command(print_atribute_room, get_obj($1), 0) ; };


print_statement: PRINT LPAREN message_name RPAREN {add_command(print, $3 , 0) ;}          
;

object: STRING { $$ = get_obj($1); }
      ;
      
message_name: STRING
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

    AST* obj = NULL;  // Добавим переменную для хранения объекта
    // yyparse(&obj);  // Передадим указатель на объект в yyparse

    yyparse();
    execute_command_list();
    fclose(input_file);



    return 0;
}
