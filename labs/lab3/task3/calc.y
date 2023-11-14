%{
#include <stdio.h>
%}

%token NUM
%token PLUS MINUS TIMES DIVIDE LPAREN RPAREN

%left PLUS MINUS
%left TIMES DIVIDE

%%

expression: 
    NUM        { printf("%d " , $1); }
  | LPAREN expression RPAREN     { }
  | expression PLUS expression   { printf("+ "); }
  | expression MINUS expression  { printf("- "); }
  | expression TIMES expression  { printf("* "); }
  | expression DIVIDE expression { printf("/ "); }
  ;

%%

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    printf("\n programm stop");
    return 1;
}

int main() {
    yyparse();
    printf("\033[1A");
    return 0;
}
