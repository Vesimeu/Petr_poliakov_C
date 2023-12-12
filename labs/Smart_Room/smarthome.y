%{
#include <stdio.h>
#include <stdlib.h>
#include "smart_objects.h"
#include <string.h>
#include "smarthome.tab.h"
#include "smart_objects.c"

// typedef union {
//     int intval;
//     char* strval;
//     struct SmartObject* objectval; // sukaebanaya
// } YYSTYPE;

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
}

%token <intval> INTEGER
%token <strval> STRING
%token <objectval> CREATE_OBJECT IF ELSE TURN_ON TURN_OFF SET_TEMPERATURE SET_VOLUME GRANT_ACCESS CURRENT_TIME SUNRISE_TIME SUNSET_TIME
%token ID COLON SEMICOLON LPAREN RPAREN LBRACE RBRACE EQUAL GREATER LESS COMMA DOT

%type <intval> create_object_statement
%type <intval> expression
%type <strval> object attribute_name
%%

program: statement_list
        ;

statement_list: statement
              | statement_list statement
              ;

statement: create_object_statement SEMICOLON
         | if_else_statement SEMICOLON
         | expression_statement SEMICOLON
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
          | expression EQUAL expression
          | expression GREATER expression
          | expression LESS expression
          ;

time_expression: CURRENT_TIME
              | SUNRISE_TIME
              | SUNSET_TIME
              ;

object: ID
      ;

attribute_name: ID
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
