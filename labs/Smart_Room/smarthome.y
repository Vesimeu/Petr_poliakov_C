%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YYSTYPE_IS_DECLARED 1
#define YYSTYPE_IS_TRIVIAL 1

extern FILE* yyin;
extern int yylex();
extern char* yytext;

typedef union {
    int intval;
    char* strval;
} YYSTYPE;

void yyerror(const char* s);

%}

%lex-param { YYSTYPE yylval; }

%union {
    int intval;
    char* strval;
}

%token CREATE_OBJECT IF ELSE TURN_ON TURN_OFF SET_TEMPERATURE SET_VOLUME GRANT_ACCESS CURRENT_TIME SUNRISE_TIME SUNSET_TIME
%token ID INTEGER COLON SEMICOLON LPAREN RPAREN LBRACE RBRACE EQUAL GREATER LESS COMMA STRING DOT

%type <strval> object attribute_name expression

%%

program: statement_list
        ;

statement_list: statement
              | statement_list statement
              ;

statement: create_object_statement
         | if_else_statement
         | expression_statement SEMICOLON
         ;

create_object_statement: CREATE_OBJECT STRING
                     ;

if_else_statement: IF LPAREN expression RPAREN LBRACE statement_list RBRACE
                 | IF LPAREN expression RPAREN LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE
                 ;

expression_statement: object DOT attribute_name
                   | object DOT attribute_name LPAREN argument_list RPAREN
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
    fprintf(stderr, "Error: %s\n", s);
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
