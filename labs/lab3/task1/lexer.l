%{
#include "parser.tab.h"
%}

%%
token1 { return TOKEN; }
. { /* игнорируем неизвестные символы */ }

%%
int yywrap() {
    return 1;
}
