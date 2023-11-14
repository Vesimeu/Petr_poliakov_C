%{
#include "calc.tab.h"
%}


%%

[0-9]+      { yylval = atoi(yytext); return NUM; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return TIMES; }
"/"         { return DIVIDE; }
"("         { return LPAREN; }
")"         { return RPAREN; }
[ \t]     { /* игнорируем пробелы и символы конца строки */ }
[\n]     { return 0; }
.           { yyerror("unexpected character"); }

%%

int yywrap() {
    return 1;
}
