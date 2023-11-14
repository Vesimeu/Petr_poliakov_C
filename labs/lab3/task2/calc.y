%{
#include <stdio.h>
%}

%token NUMBER

%%

input: /* Если завершается пустой строкой*/
     | input expr '\n'
     {
        printf("%d\n", $2);
     }
     ;

expr: expr '+' expr
    {
        $$ = $1 + $3;
    }
  | expr '-' expr
    {
        $$ = $1 - $3;
    }
  | NUMBER
    {
        $$ = $1;
    } 
  ;


%%

int main() {
    yyparse();
    return 0;
}

int yyerror(const char *msg) {
    fprintf(stderr, "Ошибка: %s\n", msg);
    return 1;
}
