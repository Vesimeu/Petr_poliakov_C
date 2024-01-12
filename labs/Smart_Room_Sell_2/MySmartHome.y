%{
#include <stdio.h>
#include <stdlib.h>
#include "MySmartHome.h"
#include <string.h>
#include "MySmartHome.tab.h"


extern FILE* yyin;
extern int yylex();
extern char* yytext;

struct Home;
Home* temp = NULL; 
void yyerror(const char* s);

%}

%lex-param { YYSTYPE yylval; }


%union {
    int intval;
    char* strval;
    Home* objectval;
}


%token <intval> INTEGER 
%token <objectval> CREATE 
%token COLON LPAREN RPAREN LBRACE RBRACE COMMA SET PRINT ENDL START
%token <strval> LIGHT_ON LIGHT_OFF BLINDS_ON BLINDS_OFF INFO GREATER LESS EQUAL STRING ID SOUND AIRCON



%type <strval> message 
%type <objectval> create_object light_command blinds_command print_info object 
%%


main_program: statement_list
        ;

statement_list: statement
              | statement_list statement
              ;


statement: create_object ENDL
         | light_command ENDL     
         | blinds_command ENDL 
         | print_info ENDL
         | temperature ENDL   
         | set_volume ENDL
         | print_message ENDL
         ;

create_object: START CREATE STRING { $$ = create_device($3); temp = $$; }
;


            
light_command: START object SET LIGHT_ON  { 
                add_action_to_queue(activited_light, retrieve_device($2), 0); 
             }
             | START object SET LIGHT_OFF  { 
                add_action_to_queue(deactivited_light, retrieve_device($2), 0); 
             }
          
     

blinds_command: START object SET BLINDS_ON  { add_action_to_queue(shades_on, retrieve_device($2), 0); }
             | START object SET BLINDS_OFF  { add_action_to_queue(shades_off, retrieve_device($2), 0); }
             ;



temperature: START object SET AIRCON LPAREN INTEGER RPAREN { add_action_to_queue(aircon, temp, $6) ;};


set_volume: START object SET SOUND LPAREN INTEGER RPAREN { add_action_to_queue(set_audio, temp, $6) ;};
             
             
print_info: START object INFO {add_action_to_queue(information, retrieve_device($2), 0) ; };


print_message: START PRINT LPAREN message RPAREN {add_action_to_queue(display_system_message, $4 , 0) ;}          
;

object: STRING { $$ = retrieve_device($1); }
      ;
      
message: STRING
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

    Home* obj = NULL; 

    yyparse();
    perform_all_actions();
    fclose(input_file);



    return 0;
}