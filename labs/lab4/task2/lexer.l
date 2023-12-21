%{
#include "parser.tab.h"
%}

%%

[0-9]+ { yylval.num = atoi(yytext); return NUMBER; }
"+"    { return PLUS; }
"-"    { return MINUS; }
"*"    { return MULT; }
"("    { return LPAREN; }
")"    { return RPAREN; }
[ \t]  { /* игнорировать пробелы и табы */ }
.      { return yytext[0]; }

%%

int main() {
    return yyparse();
}