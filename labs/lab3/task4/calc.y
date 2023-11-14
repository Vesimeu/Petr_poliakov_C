%code requires
  {
    #define YYSTYPE double
  }
%{
#include <stdio.h>
#include "calc.tab.h"
int yylex(void);
%}

%token FLOAT INTEGER
%token PLUS MINUS TIMES DIVIDE LPAREN RPAREN

%left PLUS MINUS
%left TIMES DIVIDE

%%

expression: 
    term                    { /* обработка терма */ }
  | expression PLUS term    { printf("+ "); }
  | expression MINUS term   { printf("- "); }
  ;

term:
    factor                  { /* обработка фактора */ }
  | term TIMES factor       { printf("* "); }
  | term DIVIDE factor      { printf("/ "); }
  ;

factor:
    number                  { /* обработка числа */ }
  | LPAREN expression RPAREN { /* обработка выражения в скобках */ }
  ;
  
number:
    FLOAT       { printf("%f ", $1); }
  | INTEGER    { printf("%d ", $1); }
  ;
  
%%

int main() {
    printf("Введите арифметическое выражение: ");
    yyparse();
    printf("\n");
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 1;
}
