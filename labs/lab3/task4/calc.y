%{
#include <stdio.h>
#include "calc.tab.h"
%}

%token PLUS MINUS TIMES DIVIDE LPAREN RPAREN

%left PLUS MINUS
%left TIMES DIVIDE
    
%union{
  double d;
  int f;
}


%token <d> FLOAT
%token <f> INTEGER

%%

expression
    : term
    | expression PLUS term   { printf("+ "); }
    | expression MINUS term  { printf("- "); }
    ;

term
    : factor
    | term TIMES factor      { printf("* "); }
    | term DIVIDE factor     { printf("/ "); }
    ;

factor
    : number
    | LPAREN expression RPAREN
    ;

number
    : FLOAT                  { printf("%f ", $1); }
    | INTEGER                { printf("%d ", (int)$1); }
    ;

%%

int main() {
    while (1){
    printf("Введите арифметическое выражение: ");
    yyparse();
    printf("\n");
    }
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 1;
}
