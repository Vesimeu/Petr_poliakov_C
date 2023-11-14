%{
#include "calc.tab.h"
#include <stdio.h>
%}

%%

[0-9]+\.[0-9]+  { yylval = atof(yytext); return FLOAT; }
[0-9]+          { yylval = atoi(yytext); return INTEGER; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return TIMES; }
"/"             { return DIVIDE; }
"("             { return LPAREN; }
")"             { return RPAREN; }
[ \t\n]         { /* игнорируем пробелы и символы конца строки */ }
.               { yyerror("unexpected character"); }

%%

int yywrap() {
    return 1;
}
