%{
#include <stdio.h>
void yyerror(const char* s) {
    fprintf(stderr, "Ошибка: %s\n", s);
}
%}

%token TOKEN

%%

input: TOKEN { printf("Токен: %s\n", $1); }
     | input TOKEN { printf("Токен: %s\n", $2); }
     ;

%%

int main() {
    yyparse();
    return 0;
}
