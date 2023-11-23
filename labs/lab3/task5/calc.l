%{
#include "calc.tab.h"
%}

%%
"+" { return ADD; }
"-" { return SUB; }
[0-9]+"."[0-9]+ { yylval.d = atof(yytext); return NUMBER; }
[0-9]+ { yylval.d = atof(yytext); return NUMBER; }
"*" { return '*'; }
"/" { return '/'; }
"(" { return '('; }
")" { return ')'; }
[ \t\n] { /* skip whitespace */ }
. { yyerror("unknown character"); }

%%

int yywrap(void) {
  return 1;
}
