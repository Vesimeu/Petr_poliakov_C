%{
#include "calc.tab.h"
void yyerror(const char *s);
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
[\n] { return AND; }
" " {};
. { yyerror("unknown character"); }

%%

int yywrap(void) {
  return 1;
}
