%{
#include "calc.tab.h"
%}


%%

[0-9]+ {
    yylval = atoi(yytext);
    return NUMBER;
}
[-+] {
    return yytext[0];
}
\n { 
    return '\n';  // Вернуть символ новой строки как отдельный токен.
}
. {
    // Игнорируем неподходящие символы.
}
%%

int yywrap() {
    return 1;
}
