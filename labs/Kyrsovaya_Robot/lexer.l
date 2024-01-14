%{
#include <stdio.h>
#include "bison.tab.h"
%}
%%
[0-9]+ {yylval=atoi(yytext); return NUMBER;};
[A-Z]+ return PER;
[\t]+ ;
\n ;
left return LEFT;
right return RIGHT;
go return GO;
back return BACK;
proverka return PROV;
say_time return TIME;
make_vol return MV;
lampon return LAMPN;
lampoff return LAMPF;
x return X;
y return Y;
vol return V;
"=" ;
%%