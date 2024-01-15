%{
#include <stdio.h>
#include <stdlib.h>
#include "head_file.h"
#include <string.h>
#include "control.tab.h"


extern FILE* yyin;
extern int yylex();
extern char* yytext;

struct Device;
Device* temp = NULL;  // хранения объекта
ActionList* current_command_list = NULL; // текущего списка команд
void yyerror(const char* s);

%}

%lex-param { YYSTYPE yylval; }



%union {
    int intval;
    char* strval;
    Device* objectval;
}


%token <intval> INTEGER 
%token <objectval> ADD_ROOM TURN_ON TURN_OFF 
%token COLON LPAREN RPAREN LBRACE RBRACE COMMA START PRINT END AND
%token <strval> SET_AUDIO_LEVEL SET_TEMPERATURE SET_LIGHT_MODE SET_BLINDS_MODE INFO GREATER LESS EQUAL STRING ID
%type <strval> message_name 
%type <objectval> add_obj_statement light_command blinds_command info_command object 
%%


program: statement_list
       ;

statement_list: statement
              | statement_list statement
              ;
statement: command_sequence END
         ;

command_sequence: command
                | command_sequence AND command
                ;

command: add_obj_statement
         | light_command 
         | blinds_command
         | info_command 
         | set_conditioner   
         | set_volume_statement 
         | print_statement 
;


add_obj_statement: ADD_ROOM STRING { $$ = create_device($2); temp = $$; }
;
   
light_command: object START SET_LIGHT_MODE LPAREN INTEGER RPAREN { 
                enqueue_action(set_light_mode, get_device($1), $5); 
             } ;
          
    
blinds_command: object START SET_BLINDS_MODE LPAREN INTEGER RPAREN { 
                enqueue_action(set_blinds_mode, get_device($1), $5); 
             } ;

set_conditioner: object START SET_TEMPERATURE LPAREN INTEGER RPAREN { enqueue_action(adjust_aircon, temp, $5) ;};


set_volume_statement: object START SET_AUDIO_LEVEL LPAREN INTEGER RPAREN { enqueue_action(set_audio_level, temp, $5) ;};
             
             
info_command: object START INFO {enqueue_action(print_atribute_room, get_device($1), 0) ; };


print_statement: PRINT LPAREN message_name RPAREN {enqueue_action(print_message, $3 , 0) ;}          
;

object: STRING { $$ = get_device($1); }
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

    Device* obj = NULL; 

    yyparse();
    execute_actions();
    fclose(input_file);



    return 0;
}