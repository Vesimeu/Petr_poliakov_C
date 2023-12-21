%{
#include "calc.tab.h"
#include <stdio.h>
%}

%%

[0-9]+\.[0-9]+  { yylval.d = atof(yytext); return FLOAT; }
[0-9]+          { yylval.f = atoi(yytext); return INTEGER; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return TIMES; }
"/"             { return DIVIDE; }
"("             { return LPAREN; }
")"             { return RPAREN; }
[ \t\n]         { /* игнорируем пробелы и символы конца строки */ }
.               { yyerror("unexpected character"); return 0; }
<<EOF>> { return 0; }


%%

int yywrap() {
    return 1;
}
