%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(char *s) {
    fprintf(stderr, "error: %s\n", s);
}

int yylex(void);
%}

%union {
    int num;
}

%token <num> NUMBER
%token PLUS MINUS MULT LPAREN RPAREN
%type <num> expression term factor

%%

expression
    : expression PLUS term   { printf("ADD R0, R0, R1\n"); }
    | expression MINUS term  { printf("SUB R0, R0, R1\n"); }
    | term                   { /* ничего не делать */ }
    ;

term
    : term MULT factor       { printf("MUL R1, R1, R2\n"); }
    | factor                 { /* ничего не делать */ }
    ;

factor
    : NUMBER                 { printf("LOAD R2, #%d\n", $1); }
    | LPAREN expression RPAREN { /* ничего не делать */ }
    ;

%%
