%{
#include <stdio.h>
%}

%token FLOAT INTEGER
%token PLUS MINUS TIMES DIVIDE LPAREN RPAREN

%left PLUS MINUS
%left TIMES DIVIDE

%%

number:
   FLOAT       { printf("%f ", $1); }
  | INTEGER    { printf("%d" , $1); }

expression: 
    number       { printf("%d ", $1); }
  | LPAREN expression RPAREN     { }
  | expression PLUS expression   { printf("+ "); }
  | expression MINUS expression  { printf("- "); }
  | expression TIMES expression  { printf("* "); }
  | expression DIVIDE expression { printf("/ "); }
  ;

%%

int main() {
    yyparse();
    printf("\n");
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 1;
}
